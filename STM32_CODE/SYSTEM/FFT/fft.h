#ifndef __FFT_H
#define __FFT_H	 
#include "sys.h"

extern uint32_t input[1024], output[1024], Mag[1024], Phase[1024]; /* 输入，输出和幅值 */

void PowerMag(uint16_t _usFFTPoints);
void DSP_FFT1024(void);
void DSP_FFT64(void);
void DSP_FFT256(void);
void Power_Phase_Radians(uint16_t _usFFTPoints);
void DSP_FFTPhase(void);
					    
#endif
