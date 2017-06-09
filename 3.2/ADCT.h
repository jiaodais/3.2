#ifndef _ADCT_H_
#define _ADCT_H_
#include "LPC11xx.h"
extern uint8_t temp(void);
extern void lowtemp_setting(void);
extern void hightemp_setting(void);
extern void SysTickInit(void);
extern void ALLtemp_setting(void);

#endif
