/**
  ******************************************************************************
  * @file    key.c
  * @author  xiaoyuan
  * @version V1.0
  * @date    2016-04-12
  * @brief   This file provides all the LED functions.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "key.h"
#include "delay.h"
//#include "sys.h"
//��ʼ��PC0��PD12Ϊ�����.��ʹ���������ڵ�ʱ��		    
//KEY IO��ʼ��
void KEY_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��PC,PD�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;				 //KEY�˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //���ó���������
 GPIO_Init(GPIOE, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOC.0
	
//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_15;//PA15
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
// 	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA15
//	
//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5;//PC5
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
// 	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIOC5
// 
//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;//PA0
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0���ó����룬Ĭ������	  
//	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.0
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;				 //KEY�˿�����
 //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //���ó���������
	//GPIO_Init(GPIOD, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOD.12
 
}
//����ɨ�躯����������ʱ������
//mode��0����֧�ֳ��� 1��֧�ֳ���
//���ذ���ֵ ����ֵ��0���ް������¡�1��KEY0���¡�2��KEY1����
u8 KEY_Scan(uint8_t mode)
{
	static uint8_t key_up = 1;
	if(mode) key_up = 1;
	if(key_up&&(KEY_U==0||KEY_D==0||KEY_L==0||KEY_R==0||KEY_M==0))
	{
//		delay_ms(10); �����ⲿ�ж���ִ�У�����Ҫ��ʱ
		key_up = 0;
		if(KEY_U == 0) return 1;
		else if(KEY_D == 0) return 2;
		else if(KEY_L == 0) return 3;
		else if(KEY_R == 0) return 4;
		else if(KEY_M == 0) return 5;
	}
	else if(KEY_U == 1&&KEY_D ==1&&KEY_L ==1&&KEY_R ==1&&KEY_M ==1) 
		key_up =1;
	return 0;
}
