#ifndef _GUI_H_
#define _GUI_H_

#include "lcd.h"
#include "touch.h"
#include "delay.h"
#include "led.h"
#include "lcd.h"
#include "malloc.h"
#include "MMC_SD.h"
#include "ff.h"
#include "exfuns.h"
#include "fontupd.h"
#include "text.h"
#include "dac.h"
#include "adc.h"
#include "usart.h"
//#include "wave.h"
#include "math.h"   //调用平方函数需要
#include "timer.h"
#include "fft.h"

#define   LeftorRight_Num  10     //左移或右移一次为10个点
#define   UporDown_Num	10

//extern DAC_WAVE_Typedef DAC_SETTING;

extern u16 arr_ADC, psc_ADC;	//定义在main.c
extern u8 state_flag;
extern u8 clear_flag;  //0已清屏，1未清屏


void GUI_draw(void);
void GUI_draw_key_0(void);
void GUI_draw_key_1(void);
void GUI_draw_coordinate(void);	//画坐标
void GUI_draw_frame(void);	//画框

void GUI_scan_0(void);
void GUI_scan_1(void);

/*
void GUI_draw_sin(void);
void GUI_draw_sawtooth(void);
void GUI_draw_triangle(void);
void GUI_draw_square(void);
void GUI_draw_AnyWave(void);

void GUI_draw_left(void);
void GUI_draw_right(void);
void GUI_draw_up(void);
void GUI_draw_down(void);
*/

void GUI_draw_AdcWave(void);
void GUI_Lock(void);	//锁定ADC波形
void GUI_Lock_up(void);
void GUI_Lock_down(void);
void GUI_change_Lock_phase(void);	//改变锁定类型

void GUI_signal_processing(void);	//AD采样数据处理
void GUI_show_signal(void);			//显示AD处理后的数据

void GUI_show_FFT(void);
void GUI_fft_harmonic(void);	//计算谐波
uint32_t FFT_FindMax(u32 Frc, u8 error);	//求最大值
void GUI_show_fft_value(void);

void Auto_set (void);

#define x0 20
#define x1 90
#define x2 160
#define x3 230
#define x4 300
#define y0 20
#define y1 70
#define y2 120
#define y3 170
#define y4 220

//#define x0 20
//#define x1 70
//#define x2 120
//#define x3 170
//#define x4 220
//#define y0 20
//#define y1 90
//#define y2 160
//#define y3 230
//#define y4 300

#endif
