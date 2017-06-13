#include "LPC11xx.h"
#include "stdio.h"
#include "string.h"
#include "KEY.h"
#include "delay.h"
#include "oled.h"
#include "ui.h"
#include "ADC.h"
#include "UART.h"
#include "ADCT.h"
extern int  	key_value  ;
extern  float low_temp ;
extern  float high_temp ;
extern  uint32_t  k,t;
float temperature1;
extern	int   lastlow_temp ;
extern	int   lasthigh_temp ; 
extern float low_temp;
extern float high_temp;
extern uint8_t xiaoren[];
uint8_t s=30;
uint8_t x=20;
uint8_t Arrow = 2,	chonum, scrnum = 0;

uint8_t AR[]="--+";//��ʾ��ͷ
uint8_t AC[]="   ";//������ͷ

char buff[20];
typedef struct 
{
	uint8_t num;
	uint8_t number[2];
	uint8_t title[20];
	uint8_t choose1[20];
	uint8_t choose2[20];
	uint8_t choose3[20];
	uint8_t choose4[20];
	uint8_t choose5[20];
	uint8_t choose6[20];
	uint8_t choose7[20];
}screen[1];//Ϊ�˵���ǰ�ṩ����
static screen scr[10]=
{
//{???,"???","����",      					 "�˵�1",               "�˵�2",           			  "�˵�3",           	    "�˵�4",             		"�˵�5", 	},
	{0,"0","    zhuomian     ",   "  Temperature  ",   "   T-Setting   ",   "    Picture    ",   "     MAKER     ",   "    nothing    ",   },   
  {1,"1","  Temperature    ",   "  Temperature  ",   "    nothing    ",   "    nothing    ",   "    nothing    ",   "    nothing    ",   },
  {2,"2","    setting      ",   "    low-temp   ",   "    hige-temp  ",   "       _       ",   "       -       ",   "       -       ",   },
  {3,"3","    Picture       ",   "   Picture    ",   "       _       ",   "       _       ",   "       -       ",   "    nothing    ",   },
  {4,"4","     MAKER       ",   "  15160200124  ",   "   LINXIA      ",   "  15160200116  ",   "  QIANCAHNGYOU ",   "      0.0      ",   },
	

};
void printscreen(uint8_t i)
{
	OLED_P6x8Str(0,0,scr[i]->title );//��ӡָ�����ѡ��
	OLED_P6x8Str(16,2,scr[i]->choose1);
  OLED_P6x8Str(16,3,scr[i]->choose2);
	OLED_P6x8Str(16,4,scr[i]->choose3);
	OLED_P6x8Str(16,5,scr[i]->choose4);
	OLED_P6x8Str(16,6,scr[i]->choose5);
	OLED_P6x8Str(16,7,scr[i]->choose6);
	
}
uint8_t  UI(void)
{
	key_value = 0;//������ֵ��λ0
	chonum = 0;//������ҳ
	
	
	OLED_P6x8Str(0,Arrow,AR );//OLED��ӡ��ͷ
	
	printscreen (scrnum);//
	
	switch(key_value )//���µ�һ�������Ϸ�
	{
		case 6:                                   
    OLED_P6x8Str(0,Arrow,AC);
    Arrow--;
    if(Arrow < 2) Arrow=7;//����ͷָ�򳬹����߸���ʱ��ص���ʼλ��
    OLED_P6x8Str(0,Arrow,AR);
    key_value = 0;//������ֵ�ظ�0
    break;
    
  case 7:                                   
    OLED_P6x8Str(0,Arrow,AC);//���µڶ��������·�
    Arrow++;
    if(Arrow > 7) Arrow=2;
    OLED_P6x8Str(0,Arrow,AR);
    key_value = 0;
    break;
    
  case 8:                                   
    {
      OLED_CLS();//���µ�������ת�������
      OLED_P6x8Str(0,Arrow,AC);             
      if(scrnum!=0)                          
      {
        chonum=scrnum*10+Arrow-1;  //��ҳ         
      }
      else
      {
        scrnum=Arrow-1;                     
        chonum=Arrow-1;
      }
      key_value = 0;
      break;
    }
  case 9:                                   
    {
      OLED_P6x8Str(0,Arrow,AC);//�˳���ǰ����
      scrnum=0;
      key_value = 0;
      OLED_CLS();//����
      break;
    }
  case 10:
		
    break;
	}



  switch(chonum)
    {

			case 11:
							OLED_Print(5, 0, "Now Tem:");//�ڶ�Ӧ�����ӡ����
			        OLED_Print(5, 3, "Now Frh" );
			        while(key_value != 9)//û�а��·��ؼ�ʱ
							{
								
								
								temperature1 = ADC_read();//��temp1��ֵ
							if (temperature1 !=0){
								sprintf(buff,"%.2f",temperature1);//��ӡֵ
								OLED_Print(70,3,"     ");
								OLED_Print(70,4,"       ");//����
								ALLtemp_setting();//�¶ȱ�������
								
									OLED_P6x8Str(30,2,buff);
							
								
							
								sprintf(buff,"%.2f",(temperature1*(9/5)+32));//ת�����϶�
								OLED_P6x8Str(30,5,buff);
								OLED_P6x8Str(60,2,"C'");
								OLED_P6x8Str(60,5,"F'");
							}
										
										
										if(key_value == 9)
											{
												OLED_CLS();
											}
							}	
							break;
      case 12:break;
      case 13:break;
      case 14:break;
							
							
							
							
				case 21:lastlow_temp=low_temp;//lastlow_temp=��ʼ����ֵ
							while(key_value != 9)
							{
								lowtemp_setting();
								if(key_value == 9)
								{
								low_temp=lastlow_temp;
									OLED_CLS();
								}	
							}
						  break;
			case 22:
							lasthigh_temp=high_temp;//lasthigh_temp=��ʼ����ֵ
							while(key_value != 9)
							{
								hightemp_setting();
								if(key_value == 9)//�����ؼ�high_temp=����ֵ
								{
						
								high_temp=lasthigh_temp;
									OLED_CLS();
								}	
							}
							 break;
			case 23:
							break;
			case 31: while(key_value != 9)//û���·��ؼ���ӡС��  ��������
							{
							
							
								Draw_BMP(15,0,65,5,xiaoren); //��ӡС��
									Draw_BMP(63,0,113,5,xiaoren);
					
								
								
								if(key_value == 9)
											{
												OLED_CLS();//����
											}
							}
							
							 break;
							
							case 33:
								break;

    }
return 0;
	
}				
							