#include "beep.h"


	   

//��ʼ��PE8Ϊ�����.��ʹ������ڵ�ʱ��		    
//��������ʼ��
void BEEP_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	 //ʹ��GPIOE�˿�ʱ��
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				 //BEEP-->PE.4 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //�ٶ�Ϊ50MHz
 GPIO_Init(GPIOE, &GPIO_InitStructure);	 //���ݲ�����ʼ��GPIOE.4
 
 GPIO_ResetBits(GPIOE,GPIO_Pin_2);//���0���رշ��������


}
void BEEP_Ring(uint16_t time) //����������
{	
	GPIO_SetBits(GPIOE,GPIO_Pin_2);  
	delay_ms(time);
	GPIO_ResetBits(GPIOE,GPIO_Pin_2);	
}

