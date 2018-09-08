#ifndef __ADC_H
#define __ADC_H
#include "sys.h"
#include "led.h"
#include "dac.h"

//extern uint16_t adc_buff[300];

//void collect_once(void);
//void Adc_Init(void);
//u16  Get_Adc(u8 ch);
//u16 Get_Adc_Average(u8 ch,u8 times);

#define SAMPDEPTH 1024

extern u32 ADC_Fr;
extern u16 ADCConvertedValue[SAMPDEPTH]; 	//volatile
extern u8 UpdatTrue;

extern u16 arr_ADC, psc_ADC;	//∂®“Â‘⁄main.c
extern u16 GEAR_CTRL_VALUE [4];

void Adc_Init(void);
void ADC_Change_Fr(u32 Fr);
void ADC_Fr_plus(void);
void ADC_Fr_dec(void);
void ADC_change_gear (u8 gear);

#endif
