#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "key.h"
#include "24cxx.h"
#include "myiic.h"
#include "touch.h"
#include "GUI.h"
//#include "usmart.h"
#include "adc.h"
#include "dac.h"
#include "stm32f10x_dma.h"
//#include "wave.h"
#include "exti.h"
#include "timer.h"
//#include "malloc.h" 

//DAC_WAVE_Typedef DAC_SETTING;

u16 arr_ADC, psc_ADC;
u16 arr_DAC, psc_DAC;

u16 arr_PWM = 999;	//PWM参数

u32 FreqExtCounter=0;
u32 FreqVal=0;
u32 FreqVal1=0;

u16 GEAR_CTRL_VALUE [4] = {2000,2000,2000,2000};
u16 ADCConvertedValue[SAMPDEPTH];	//ADCbuf AD转换缓冲区

u8 state_flag = 3;
u8 clear_flag = 0;  //0已清屏，1未清屏

float av=0.316;
//u8 kk;
void Inits(void);//初始化

int main(void)
{
//    u8 state_flag = 0;
//    u8 key_value = 0;
//  u8 clear_flag = 0;  //0已清屏，1未清屏
    POINT_COLOR = RED; //设置字体为红色
    Inits();
//    DMA_Cmd(DMA1_Channel1, ENABLE);
//    LCD_Clear(WHITE);//清屏
	LCD_Fill(0,0,320,240,WHITE);
    while (1)
    {
		if(key_flag){
			key_flag = 0;
	//		key_timer_scan 按键扫描，由timer7刷新
			if(key_timer_scan == KEY0_PRES){
				clear_flag = 1;
				if (state_flag == 2 || state_flag == 3) {
				  state_flag = 1;
				}
				else if (state_flag == 0) {
				  state_flag = 1;
				}
				else if (state_flag == 1) {
				  state_flag = 0;
				}
				else
				{
				  state_flag = 1;
				}
	//		printf("key0 state_flag = %d\n",state_flag);	//just for test
			}
			else if(key_timer_scan == KEY1_PRES) {
				clear_flag = 1;
				if (state_flag == 0 || state_flag == 1) {
				  state_flag = 3;
				}
				else if (state_flag == 3) {
				  state_flag = 2;
				}
				else if (state_flag == 2)
				{
				  state_flag = 3;
				}
				else
				{
				  state_flag = 3;
				}
	//		printf("key1 state_flag = %d\n",state_flag);	//just for test
			}					
		}
		
        switch (state_flag) {
        case 0:
            if (clear_flag) {
//                LCD_Clear(WHITE);//清屏
				LCD_Fill(0,0,320,240,WHITE);
//                GUI_draw_AnyWave();
                clear_flag = 0;
            }
			GUI_show_FFT();
			TIM_Cmd(TIM3, ENABLE);
//            GUI_draw_coordinate();
            GUI_scan_1();
            GUI_draw_key_1();
            GUI_draw_frame();
            break;

        case 1:
            if (clear_flag) {
//                LCD_Clear(WHITE);//清屏
				LCD_Fill(0,0,320,240,WHITE);
//                GUI_draw_AnyWave();
                clear_flag = 0;
            }
            GUI_draw_coordinate();
			GUI_show_FFT();
			TIM_Cmd(TIM3, ENABLE);
			GUI_show_fft_value();
            break;
        case 2:
            if (clear_flag) {
//                LCD_Clear(WHITE);//清屏
				LCD_Fill(0,0,320,240,WHITE);
                clear_flag = 0;
            }
            GUI_draw_AdcWave();
			TIM_Cmd(TIM3, ENABLE);
            GUI_draw_key_1();
            GUI_draw_frame();
            GUI_scan_1();
            break;
        case 3:
            if (clear_flag) {
//                LCD_Clear(WHITE);//清屏
				LCD_Fill(0,0,320,240,WHITE);
                clear_flag = 0;
            }
            GUI_draw_AdcWave();
			TIM_Cmd(TIM3, ENABLE);
			GUI_show_signal();	//显示AD数据
            GUI_draw_coordinate();
            GUI_draw_frame();
//			LCD_ShowNum(60+80,190,mem_perused(),3,16);//显示内存使用率
            break;
        default:
            state_flag = 3;
            clear_flag = 1;
            break;
        }
    }
}

void Inits()
{
    delay_init();            //延时函数初始化
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
    uart_init(9600);        //串口初始化为9600
    LED_Init();             //初始化与LED连接的硬件接口，用来换挡，改变增益
    LCD_Init();             //初始化LCD
    KEY_Init();             //按键初始化
    tp_dev.init();          //触摸屏初始化

	//ADC初始化
    Adc_Init();	//基于DMA方式
	ADC_Change_Fr(100000);//ADC触发采样频率100Khz
	
	//DAC初始化 控制AD603
	Dac1_Init();
	Dac1_Set_Vol(2000);//先初始化为最大衰减
	
	//频率计初始化
	TIM4_Int_Init(9999,7199);   //arr=9999     psc=7199  1000ms=(9999+1)(7199+1)/72000000
	TIM2_Int_Init(0xffff,0);  //ETC计数，由T4触发
    TIM5_Cap_Init(0XFFFF,72-1);	//以1Mhz的频率计数
	
	//按键刷新时钟 1s一次
	TIM7_Int_Init(499,7199);   //arr=999     psc=7199  100ms=(999+1)(7199+1)/72000000

    font_init();//中文字库初始化
}
