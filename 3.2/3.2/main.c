#include "LPC11xx.h"
#include "oled.h"
#include "ui.h"
#include "key.h"
#include "delay.h"
#include "ADC.h"
#include "UART.h"

extern  float low_temp ;
extern 	float high_temp ;
extern 	int   lastlow_temp ;
extern 	int   lasthigh_temp ; 

extern uint8_t blocklogo[];
	

	




extern int key_value;
int main()
{
	
	
	UART_Init ();
  ADC_Init ();	
	OLED_Init();
	key_init();
	
	while(1)
	{

	 UI();
		
		
		////////////
		
	}
	


}

	
	
