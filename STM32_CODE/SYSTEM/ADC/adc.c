#include "adc.h"
#include "delay.h"
#include "stm32f10x_adc.h"
#include "stm32f10x_dma.h"
#include "timer.h"
// #include "Data_manage.h"

//volatile u16 ADCConvertedValue[SAMPDEPTH] = {0}; //AD转换缓冲区
u8 UpdatTrue = 0;        //中断标记 AD转换完成20次即将该标志置为0xff 在主程序中将转换处理完毕则清0

//初始化ADC
//这里我们仅以规则通道为例
void  Adc_Init(void)
{
	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	DMA_InitTypeDef   DMA_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;  //设置中断优先级分组为组2：2位抢占优先级，2位响应优先级

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1	, ENABLE );	 //使能ADC1通道时钟
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);         //ADC1使用DMA1的通道1


	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //设置ADC分频因子6 72M/6=12,ADC最大时间不能超过14M

	//ADC1 通道1使用PA1 作为模拟通道输入引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//模拟输入引脚
	GPIO_Init(GPIOA, &GPIO_InitStructure);


	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADCConvertedValue;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = SAMPDEPTH;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord ;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
	DMA_Cmd(DMA1_Channel1, ENABLE);
	
	DMA_Cmd( DMA1_Channel1, ENABLE);
	DMA_ITConfig(DMA1_Channel1, DMA_IT_TC, ENABLE);


	ADC_DeInit(ADC1);  //复位ADC1
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC工作模式:ADC1和ADC2工作在独立模式
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//模数转换工作在单通道模式
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//模数转换工作在单次转换模式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T3_TRGO; 	//转换由TIM4通道4输出触发启动（也可由TIM4 CH4通道输入捕捉触发 根据定时器的初始化配置决定）//定时器3更新事件为外部触发源
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 1;	//顺序进行规则转换的ADC通道的数目
	ADC_Init(ADC1, &ADC_InitStructure);	//根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器

	ADC_ExternalTrigConvCmd(ADC1, ENABLE);
//  	ADC_ITConfig(ADC1,ADC_IT_EOC,ENABLE);  //开启ADC1转换结束中断
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5 );	//ADC1,ADC通道1,采样时间为13.5周期
	ADC_DMACmd(ADC1, ENABLE);

	ADC_Cmd(ADC1, ENABLE);	//使能指定的ADC1
	ADC_ResetCalibration(ADC1);	//使能复位校准
	while (ADC_GetResetCalibrationStatus(ADC1));	//等待复位校准结束
	ADC_StartCalibration(ADC1);	 //开启AD校准
	while (ADC_GetCalibrationStatus(ADC1));	 //等待校准结束

//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能

	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel1_IRQn ;	//中断类型
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//抢占优先级2，
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;			//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		//使能外部中断通道
	NVIC_Init(&NVIC_InitStructure);

}

//DMA完成一组数据传递后的中断
void DMA1_Channel1_IRQHandler(void)
{
	if (DMA_GetITStatus(DMA1_IT_TC1) != RESET)
	{
		DMA_ClearITPendingBit(DMA1_IT_TC1);
		UpdatTrue = 0xff;            //设置中断标记，在主程序中判断并清0
		TIM_Cmd(TIM3, DISABLE);	   //在主程序中处理完数据后再打开
	}
}

u32 ADC_Fr = 100000;
//改变采样率
void ADC_Change_Fr(u32 Fr)//16-1000001HZ
{
	u16 temp;
	if ((Fr > 15) && (Fr < 1000002))
	{
		temp = 1000000 / Fr;
	}
	else
	{
		temp = 1;
	}
	arr_ADC = temp - 1;
	psc_ADC = 72 - 1;
	ADCTriggerByTIM3(arr_ADC, psc_ADC);
	ADC_Fr = Fr;
}

void ADC_Fr_plus(void)
{
	ADC_Fr = ADC_Fr << 1;
	ADC_Change_Fr(ADC_Fr);
}

void ADC_Fr_dec(void)
{
	ADC_Fr = ADC_Fr >> 1;
	ADC_Change_Fr(ADC_Fr);
}

//换挡，改变增益
void ADC_change_gear (u8 gear) {
	switch(gear){
		case 0 : {
			LED0 = 0;
			LED1 = 0;
			Dac1_Set_Vol(GEAR_CTRL_VALUE[0]);//控制VGA
			break;
		}
		case 1 : {
			LED0 = 1;
			LED1 = 0;
			Dac1_Set_Vol(GEAR_CTRL_VALUE[1]);//控制VGA
			break;
		}
		case 2 : {
			LED0 = 0;
			LED1 = 1;
			Dac1_Set_Vol(GEAR_CTRL_VALUE[2]);//控制VGA
			break;
		}
		case 3 : {
			LED0 = 1;
			LED1 = 1;
			Dac1_Set_Vol(GEAR_CTRL_VALUE[3]);//控制VGA
			break;
		}
		default : {
			LED0 = 0;
			LED1 = 0;
			Dac1_Set_Vol(GEAR_CTRL_VALUE[0]);//控制VGA
			break;
		}
	}
}























