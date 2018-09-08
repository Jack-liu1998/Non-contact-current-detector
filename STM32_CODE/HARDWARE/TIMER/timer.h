#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK Mini STM32开发板
//通用定时器 驱动代码
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2010/12/03
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 正点原子 2009-2019
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////

extern u8  TIM5CH1_CAPTURE_STA;	//输入捕获状态
extern u16	TIM5CH1_CAPTURE_VAL;	//输入捕获值
extern u8 key_timer_scan;
//extern u8 kk;
//void TIM2_Int_Init(u16 arr, u16 psc);
void TIM6_Init(u16 arr, u16 psc);		//DAC触发
//void ADCTriggerByTIM4(u16 arr,u16 psc);
void ADCTriggerByTIM3(u16 arr, u16 psc);	//ADC触发
void TIM1_PWM_Init(u16 arr,u16 psc);	//PWM输出，PA11S

void TIM2_Int_Init(u16 arr,u16 psc);	//TIM2,4,5测频率
void TIM5_Cap_Init(u16 arr,u16 psc);
void TIM4_Int_Init(u16 arr,u16 psc);

void TIM7_Int_Init(u16 arr, u16 psc);	//产生1s，做刷新控制

#endif
