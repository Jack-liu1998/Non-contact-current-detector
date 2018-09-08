#include "timer.h"
#include "led.h"
#include "key.h"
#include "db.h"
#include "gui.h"
#include "usart.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//Mini STM32开发板
//通用定时器 驱动代码			   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2010/12/03
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 正点原子 2009-2019
//All rights reserved
////////////////////////////////////////////////////////////////////////////////// 	  
 

////通用定时器中断初始化
////这里时钟选择为APB1的2倍，而APB1为36M
////arr：自动重装值。
////psc：时钟预分频数
////这里使用的是定时器3!

//extern u8 kk;
//void TIM2_Int_Init(u16 arr,u16 psc)
//{
//  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;

//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //时钟使能
//	
//	//定时器TIM3初始化
//	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
//	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
//	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
// 
//	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断

//	//中断优先级NVIC设置
//	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM3中断
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //先占优先级1级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级3级
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道使能
//	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器
//	
//	TIM_Cmd(TIM2, ENABLE);  //使能TIMx					 
//}
////u8 kk=0;
////定时器3中断服务函数:10ms定时一次
//void TIM2_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET) //溢出中断
//	{ 
//		kk++;
//		if(kk>=10)kk=0;
//	}
//	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //清除中断标志位
//}

//TIM6初始化，触发DAC
void TIM6_Init(u16 arr, u16 psc)
{
    TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;

    /* TIM6 时钟使能*/
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
    /* TIM6 配置 */
    /* Time6 时基单元配置 */
    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Period = arr;
    TIM_TimeBaseStructure.TIM_Prescaler = psc;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);

    /* TIM6 TRGO selection */
    TIM_SelectOutputTrigger(TIM6, TIM_TRGOSource_Update);
    /* 使能TIM6 计数功能 */
    TIM_Cmd(TIM6, ENABLE);

}


///***************************************************************************************************
//1、通用定时器4初始化 定时器4使用内部时钟72M  arr：自动重装值0-65535。 psc：时钟预分频数0-65535
//2、定时器4的通道4的PWM输出（PB9 上升沿）用于触发ADC,启动ADC转换
//Tout= ((arr+1)*(psc+1))/Tclk (Tclk：TIM3 的输入时钟频率（单位为 Mhz）,Tout：TIM3 溢出时间（单位为 us）)
//****************************************************************************************************/
//void ADCTriggerByTIM4(u16 arr,u16 psc)
//{
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure; 
//	GPIO_InitTypeDef  GPIO_InitStructure;
// 	
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PB端口时钟
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //时钟使能
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				 //LED0-->PB.9 端口配置
//    GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_AF_PP; 		 //复用推挽输出
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
//    GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.9

//	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
//	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位	
//		
//	//初始化TIM4 Channel4 比较输出模式	 
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
//	//TIM_OCInitStructure.TIM_OCMode =TIM_OCMode_Toggle; 
// 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //输出使能
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
//	TIM_OCInitStructure.TIM_Pulse=(uint16_t) (((uint32_t) 50 * (arr+1)) / 100);			//方波
//	TIM_OC4Init(TIM4, &TIM_OCInitStructure);  //根据指定的参数初始化外设TIM4 OC4

//	TIM_SelectOutputTrigger(TIM4,TIM_TRGOSource_OC4Ref);       //使用TIM4 通道4 PWM输出作为ADC触发
//	TIM_Cmd(TIM4, ENABLE);  //使能TIM4外设
//	
//}

//通用定时器3时基单元初始化
//定时器3使用内部时钟72M
//arr：自动重装值。
//psc：时钟预分频数
void ADCTriggerByTIM3(u16 arr, u16 psc)
{
//	GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure;


    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	//使能定时器3时钟
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //使能GPIO外设和AFIO复用功能模块时钟

//	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); //Timer3部分重映射  TIM3_CH2->PB5

    //初始化TIM3
    TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值
    TIM_TimeBaseStructure.TIM_Prescaler = psc; //设置用来作为TIMx时钟频率除数的预分频值
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

    /* TIM3 选择更新事件为外部触发源 */
    TIM_SelectOutputTrigger(TIM3, TIM_TRGOSource_Update);

    TIM_Cmd(TIM3, ENABLE);  //使能TIM3
}


//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void TIM1_PWM_Init(u16 arr, u16 psc)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);//
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);   //使能GPIO外设时钟使能


    //设置该引脚为复用输出功能,输出TIM1 CH1的PWM脉冲波形
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; //TIM1_CH4
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 80K
    TIM_TimeBaseStructure.TIM_Prescaler = psc; //设置用来作为TIMx时钟频率除数的预分频值  不分频
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位


    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
    TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
    TIM_OC4Init(TIM1, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx

    TIM_CtrlPWMOutputs(TIM1, ENABLE);	//MOE 主输出使能

    TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);  //CH1预装载使能

    TIM_ARRPreloadConfig(TIM1, ENABLE); //使能TIMx在ARR上的预装载寄存器

    TIM_Cmd(TIM1, ENABLE);  //使能TIM1
}


//通用定时器4时基单元初始化
//定时器1使用内部时钟72M，更新时间为1S,更新中断使能
//arr：自动重装值。psc：时钟预分频数
//TIM4设置为主模式，并将1s更新事件作为从定时器的触发脉冲

void TIM4_Int_Init(u16 arr, u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //时钟使能

    //TIM4时基单元初始化
    TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 调用函数时arr=9999  更新时间为1s
    TIM_TimeBaseStructure.TIM_Prescaler = psc; //设置用来作为TIMx时钟频率除数的预分频值   调用函数时psc=7199 72M分频为10khz
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIM4的时间基数单位

    //TIM4设置为主模式，将1S更新事件作为从定时器的触发脉冲
    TIM_SelectOutputTrigger(TIM4, TIM_TRGOSource_Update);

    TIM_Cmd(TIM4, ENABLE);  //TIM4使能计数功能，开始计数

}


extern u32 FreqExtCounter;
extern u32 FreqVal;
extern u32 FreqVal1;
//通用定时器2初始化  定时器2使用内部时钟72M
//arr：自动重装值。 psc：时钟预分频数
//定时器2使用外部时钟源模式2，将待测频率信号加到PA0（TIM2_CH1_ETR）端
void TIM2_Int_Init(u16 arr, u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    //定时器2通道1输入捕获配置
    TIM_ICInitTypeDef  TIM2_ICInitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;


    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //时钟使能
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //使能GPIOA时钟

    //端口PA0的设置
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;  //PA0
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//GPIO_Mode_IN_FLOATING; //
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    //GPIO_ResetBits(GPIOA,GPIO_Pin_0);  //PA0输出数据比特为0

    //TIM2时基单元初始化
    TIM_TimeBaseStructure.TIM_Period = arr; //	arr=0xffff  当计数寄存器=arr时产生TIM2更新中断
    TIM_TimeBaseStructure.TIM_Prescaler = psc; //设置用来作为TIMx时钟频率除数的预分频值  psc=0,不分频  72M输入时钟
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

    //初始化TIM2输入捕获参数
    TIM2_ICInitStructure.TIM_Channel = TIM_Channel_1; // 输入通道1
    TIM2_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_BothEdge;//TIM_ICPolarity_Rising;	//上升沿捕获
    TIM2_ICInitStructure.TIM_ICSelection = TIM_ICSelection_TRC; //CC1S=11 	选择输入端 IC1映射到TRC上//用主定时器触发捕获TRC
    TIM2_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //配置输入分频,不分频
    TIM2_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 配置输入滤波器 不滤波
    TIM_ICInit(TIM2, &TIM2_ICInitStructure);


    /* Slave Mode selection: TIM2 */
    //选择TIM2为从模式中的复位模式
    TIM_SelectSlaveMode(TIM2, TIM_SlaveMode_Reset); //用主定时器复位,清0

    //TIM2选择TIM4的更新事件作为触发输入，TIM4发生更新事件，TIM2的计数寄存器清0
    TIM_SelectInputTrigger(TIM2, TIM_TS_ITR3);//见中文参考手册14.3.14 节，表78 //选择T4为T2的TRC

    //TIM2选择外部时钟源模式2，即将外部ETR（待测信号）作为TIM2的计数脉冲，不分频，在ETR上升沿计数，不使用外部触发滤波
    //TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_DIV4,TIM_ExtTRGPolarity_NonInverted, 0x00);

    TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x00); //

    //中断分组初始化
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM2中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //先占优先级2级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级0级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
    NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

    TIM_ClearITPendingBit(TIM2, TIM_IT_Update | TIM_IT_Trigger  ); //


    TIM_ITConfig(TIM2, TIM_IT_Update | TIM_IT_Trigger, ENABLE); //允许更新中断,允许通道1的捕获中断

    //TIM_ClearITPendingBit(TIM2, TIM_IT_Update| TIM_IT_CC1 );

    //TIM_ITConfig(TIM2,TIM_IT_Update| TIM_IT_CC1,ENABLE);//允许更新中断,允许通道1的捕获中断


    TIM_Cmd(TIM2, ENABLE);  //使能TIM2外设


}

u8  TIM5CH1_CAPTURE_STA;	//输入捕获状态
u16	TIM5CH1_CAPTURE_VAL;	//输入捕获值
u8  plus_sta = 1; //测量脉冲/测量周期切换
u16 Cycle_Val;//周期值

void TIM2_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM2, TIM_IT_Trigger) != RESET)
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Trigger | TIM_IT_Update ); //清除TIM2通道1的输入捕获中断标志
        FreqVal = FreqExtCounter + TIM_GetCapture1(TIM2);
        FreqExtCounter = 0;
        if(FreqVal >= 500) //大于500Hz关闭脉宽测量
        {
            TIM_ITConfig(TIM5, TIM_IT_Update | TIM_IT_CC1, DISABLE); //允许更新中断 ,允许CC1IE捕获中断
            TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
            TIM_Cmd(TIM5, DISABLE ); 	//使能定时器5
            TIM5CH1_CAPTURE_STA = 0;			//清空 ，准备
            TIM5CH1_CAPTURE_VAL = 0;
            TIM_SetCounter(TIM5, 0);
        } else
        {
            TIM_ITConfig(TIM5, TIM_IT_Update | TIM_IT_CC1, ENABLE); //允许更新中断 ,允许CC1IE捕获中断
            TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
            TIM_Cmd(TIM5, ENABLE ); 	//使能定时器5
        }
//				LED1=0;
    }
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)  //检查TIM2更新中断发生与否
    {
//		    LED0=0;
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        FreqExtCounter = FreqExtCounter + 0x10000; //已计数0x10000=65536个待测信号上升沿（周期）
    }



}


//定时器5通道1输入捕获配置
//u8  TIM5CH1_CAPTURE_STA = 0;	//输入捕获状态
//u16	TIM5CH1_CAPTURE_VAL;		//输入捕获值
//u8  plus_sta = 1; 				//测量脉冲/测量周期切换

TIM_ICInitTypeDef  TIM5_ICInitStructure;

void TIM5_Cap_Init(u16 arr, u16 psc)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);	//使能TIM5时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //使能GPIOA时钟

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;  //PA0 清除之前设置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0 输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOA, GPIO_Pin_0);						 //PA0 下拉

    //初始化定时器5 TIM5
    TIM_TimeBaseStructure.TIM_Period = arr; //设定计数器自动重装值
    TIM_TimeBaseStructure.TIM_Prescaler = psc; 	//预分频器
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

    //初始化TIM5输入捕获参数
    TIM5_ICInitStructure.TIM_Channel = TIM_Channel_1; //CC1S=01 	选择输入端 IC1映射到TI1上
    TIM5_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
    TIM5_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //映射到TI1上
    TIM5_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //配置输入分频,不分频
    TIM5_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 配置输入滤波器 不滤波
    TIM_ICInit(TIM5, &TIM5_ICInitStructure);

    //中断分组初始化
    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;  //TIM3中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //先占优先级2级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
    NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

    TIM_ITConfig(TIM5, TIM_IT_Update | TIM_IT_CC1, ENABLE); //允许更新中断 ,允许CC1IE捕获中断
    TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
    TIM_Cmd(TIM5, ENABLE ); 	//使能定时器5



}

//定时器5中断服务程序
void TIM5_IRQHandler(void)
{
    if((TIM5CH1_CAPTURE_STA & 0X80) == 0) //还未成功捕获
    {
        if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)//中断标志=1 有益处中断
        {
            if(TIM5CH1_CAPTURE_STA & 0X40) //已经捕获到高电平了
            {
                if((TIM5CH1_CAPTURE_STA & 0X3F) == 0X3F) //高电平太长了
                {
                    TIM5CH1_CAPTURE_STA |= 0X80; //标记成功捕获了一次
                    TIM5CH1_CAPTURE_VAL = 0XFFFF; //超长，无法测量，但强制结束
                } else TIM5CH1_CAPTURE_STA++;//每溢出中断一次加一周期
            }
        }
        if (TIM_GetITStatus(TIM5, TIM_IT_CC1) != RESET)//有高电平,捕获1发生捕获事件
        {
            if(TIM5CH1_CAPTURE_STA & 0X40)		//捕获到一个下降沿
            {
                TIM5CH1_CAPTURE_STA |= 0X80;		//标记成功捕获到一次高电平脉宽 测量完成
                TIM5CH1_CAPTURE_VAL = TIM_GetCapture1(TIM5); //尾数值
                TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
            } else  								//还未开始,第一次捕获上升沿
            {
                TIM5CH1_CAPTURE_STA = 0;			//清空 ，准备
                TIM5CH1_CAPTURE_VAL = 0;
                TIM_SetCounter(TIM5, 0);
                TIM5CH1_CAPTURE_STA |= 0X40;		//标记捕获到了上升沿
                if(plus_sta == 0) //如果=1,就是测试两次上升间的数据,为周期
                {   //脉宽测量
                    TIM_OC1PolarityConfig(TIM5, TIM_ICPolarity_Falling);		//CC1P=1 设置为下降沿捕获
                }
            }
        }
    }
    TIM_ClearITPendingBit(TIM5, TIM_IT_CC1 | TIM_IT_Update); //清除中断标志位
}


//通用定时器7中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器4
void TIM7_Int_Init(u16 arr, u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE); //时钟使能

    //定时器TIM4初始化
    TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值
    TIM_TimeBaseStructure.TIM_Prescaler = psc; //设置用来作为TIMx时钟频率除数的预分频值
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位


    //中断优先级NVIC设置
    NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;  //TIM7中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;  //先占优先级0级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级3级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
    NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器

    TIM_UpdateRequestConfig(TIM7, TIM_UpdateSource_Regular);  //只有计数器上溢或下溢才可以产生更新中断，设置UG位或通过从模式控制器不能产生更新
    TIM_ClearITPendingBit(TIM7, TIM_IT_Update);   //清除更新使能的中断标志，防止立即进入更新中断
    TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE ); //使能指定的TIM4中断,允许更新中断

    TIM_Cmd(TIM7, ENABLE);  //使能TIM7
}


//DDS_RAM 使用时需要在main.c里面定义
//extern u32 FreqCH0S0Val;
//extern u32 FreqCH0Val;
//extern u32 FreqCH0E0Val;
//extern u32 FreqCH0step;
//extern u32 FreqCH1S0Val;
//extern u32 FreqCH1Val;
//extern u32 FreqCH1E0Val;
//extern u32 FreqCH1step;
//定时器7中断服务程序
u8 refresh_flag;
u8 key_timer_scan = 0;
extern u8 max_flag;
static u8 time_1s = 0;
void TIM7_IRQHandler(void)   //TIM7中断
{
    if (TIM_GetITStatus(TIM7, TIM_IT_Update) != RESET)  //检查TIM7更新中断发生与否
    {
        TIM_ClearITPendingBit(TIM7, TIM_IT_Update  );  //清除TIMx更新中断标志
        key_timer_scan = KEY_Scan(0);	//得到键值
				if	(max_flag==1)
				{
			//AD603();
					max_flag=0;
				}
		
        //通道0 扫频控制
//        FreqCH0Val = FreqCH0Val + FreqCH0step;
//        if(FreqCH0Val >= FreqCH0E0Val) {
//            FreqCH0Val = FreqCH0S0Val;
//        }
//        AD9958_W_Freq(0, FreqCH0Val);  //AD9958_W_Freq(1,10000000);
//        AD9958_IO_Update();

////    AD9958_W_Amp(0,256);         //AD9958_W_Amp(1,512);
////    AD9958_W_Phase(0,15);        // AD9958_W_Phase(1,90);

//        //通道1 扫频控制
//        FreqCH1Val = FreqCH1Val + FreqCH1step;
//        if(FreqCH1Val >= FreqCH1E0Val) {
//            FreqCH1Val = FreqCH1S0Val;
//        }
//        AD9958_W_Freq(1, FreqCH1Val);  //AD9958_W_Freq(1,10000000);
//        AD9958_IO_Update();

        time_1s++;
        if(time_1s == 20) {
            time_1s = 0;
            refresh_flag = 1;
        }
    }
}








