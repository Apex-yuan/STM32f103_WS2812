#ifndef __BEEP_H
#define __BEEP_H	 
#include "sys.h"
#include "delay.h"


//�������˿ڶ���
#define BEEP PEout(2)	// BEEP,�������ӿ�		   

void BEEP_Init(void);	//��ʼ��
void BEEP_Ring(uint16_t time);


#endif //__BEEP_H

