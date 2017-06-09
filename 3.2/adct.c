#include "LPC11xx.h"                    // Device header
#include "ADCT.h"
#include "oled.h"
#include "key.h"
#include "ADC.h"
  float low_temp=20;
	float high_temp = 80;
  int lastlow_temp = 0;
	int lasthigh_temp = 0; 


	extern int key_value;
void lowtemp_setting(void)
{
	if(lastlow_temp <=(-30))lastlow_temp = -30;
	
	OLED_Print(5,0,"lowtemp_setting:");
	OLED_Print(5,2,"now :");
	OLED_PrintNum(50,2,lastlow_temp%100/10);
	OLED_PrintNum(60,2,lastlow_temp%10);
	
	if(key_value==6)
	{
		lastlow_temp ++;
		key_value =0;	
		
	}
	if(key_value ==7)
	{
		lastlow_temp --;
		key_value =0;
	}
	
	low_temp=lastlow_temp;
	
}
void hightemp_setting(void)
{
	
	if(lasthigh_temp >=80)lasthigh_temp = 80;
	OLED_Print(5,0,"hightemp_setting:");
	OLED_Print(5,2,"now :");
	OLED_PrintNum(50,2,lasthigh_temp%100/10);
	OLED_PrintNum(60,2,lasthigh_temp%10);
	
	if(key_value==6)
	{
		lasthigh_temp ++;
		key_value =0;	
	}
	if(key_value ==7)
	{
		lasthigh_temp --;
		key_value =0;
	}
	high_temp=lasthigh_temp;
}
	void ALLtemp_setting(void)
	{
		
		
if ( (int)temp/100>=high_temp){
	OLED_Print(70,3,"High");
	OLED_Print(70,4,"Warning");
}
	
	if ( (int)temp/100<=low_temp){
		
		OLED_Print(70,3,"Low");
	OLED_Print(70,4,"Warning");
}
	
	}
