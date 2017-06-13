#include "LPC11xx.h"                    // Device header
#include "ADCT.h"
#include "oled.h"
#include "key.h"
#include "ADC.h"
  float low_temp=	10;
	float high_temp =80;
  int lastlow_temp =0;
	int lasthigh_temp =0; 
extern float temperature1;

	extern int key_value;
void lowtemp_setting(void)
{

	
	OLED_Print(2,0,"lowtemp setting");
	OLED_Print(5,4,"now :");
	OLED_PrintNum(50,4,lastlow_temp%100/10);
	OLED_PrintNum(60,4,lastlow_temp%10);
	
	if(key_value==6)//按下按键数值加
	{
		lastlow_temp ++;
		key_value =0;	
		
	}
	if(key_value ==7)//按下按键数值减
	{
		lastlow_temp --;
		key_value =0;
	}
		if(lastlow_temp <=10)lastlow_temp =10;//设置最低不小于10
	low_temp=lastlow_temp;
	
}
void hightemp_setting(void)
{
	

	OLED_Print(2,0,"hightemp setting");//打印所需单词和数字
	OLED_Print(5,4,"now :");
	OLED_PrintNum(50,4,lasthigh_temp%100/10);
	OLED_PrintNum(60,4,lasthigh_temp%10);
	
	if(key_value==6)//按下数值加
	{
		lasthigh_temp ++;
		key_value =0;	
	}
	if(key_value ==7)//按下数值减
	{
		lasthigh_temp --;
		key_value =0;
	}
		if(lasthigh_temp >=80)lasthigh_temp = 80;//设置最大值不大于80
	high_temp=lasthigh_temp;
}
	void ALLtemp_setting(void)
	{
		
		
if ( temperature1>=high_temp){
	OLED_Print(70,3,"High");
	OLED_Print(70,4,"Warning");
	
}
	
	if ( temperature1<=low_temp){
	OLED_Print(70,3,"Low");
	OLED_Print(70,4,"Warning");
}
	
	}
