#ifndef ADC_H
#define ADC_H
#include "LPC11xx.h"
#include "delay.h"
void ADC_Init(void);
float ADC_read(void );
float CaculTwoPoint(float   x1, float y1, float x2, float y2, float x);
#endif
