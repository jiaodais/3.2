#include "KEY.H"
#include "LPC11XX.H"
#include "delay.h"
 int key_value;
int key_mode;
void key_init()
{
	LPC_GPIO3->DIR = 0xe0; // 把P3.0-5设置为输入引脚
	LPC_GPIO3->IE = 0x1f; // 允许P3.0-5引脚上的中断
  LPC_GPIO3->IS = 0xe0; // 设置P3.0-5引脚为边沿触发
  LPC_GPIO3->IEV =0xe0; // 设置P3.0-5引脚为下降沿触发
//	LPC_GPIO3->IS = 0x1f; // 设置P3.0-5引脚为电平触发
//	LPC_GPIO3->IEV =0xe0; // 设置P3.0-5引脚为低电平触发
  NVIC_EnableIRQ(EINT3_IRQn); // 打开GPIO3中断
}

void PIOINT3_IRQHandler()
{
		key_mode=0;														//0按键未松开就计数，1按键松开后计数
		if((LPC_GPIO3->MIS & (1<<0))==(1<<0)) // P3.0按下
			{		
				delay(50);
				key_value=6;
				while((LPC_GPIO3->DATA&(1<<0))!=(1<<0)&&key_mode);
				delay(50);
				LPC_GPIO3->IC = (1<<0);  // 清中断
			}
    if((LPC_GPIO3->MIS & (1<<1))==(1<<1)) // P3.1按下
			{	
				delay(50);
				key_value=7;
				while((LPC_GPIO3->DATA&(1<<1))!=(1<<1)&&key_mode);
				delay(50);
				LPC_GPIO3->IC = (1<<1);  // 清中断
			}
		if((LPC_GPIO3->MIS & (1<<2))==(1<<2)) // P3.2按下
			{	
				delay(50);
				key_value=8;
				while((LPC_GPIO3->DATA&(1<<2))!=(1<<2)&&key_mode);
				delay(50);
				LPC_GPIO3->IC = (1<<2);  // 清中断
			}
		if((LPC_GPIO3->MIS & (1<<3))==(1<<3)) // P3.3按下
			{		
				delay(50);				
				key_value=9;
				while((LPC_GPIO3->DATA&(1<<3))!=(1<<3)&&key_mode);
				delay(50);
				LPC_GPIO3->IC = (1<<3);  // 清中断
			}
		if((LPC_GPIO3->MIS & (1<<4))==(1<<4)) // P3.4按下
			{	
				delay(50);				
				key_value=10;
				while((LPC_GPIO3->DATA&(1<<4))!=(1<<4)&&key_mode);
				delay(50);
				LPC_GPIO3->IC = (1<<4);  // 清中断
			}
}

