#ifndef __MAX6675_H
#define __MAX6675_H

#include "stm32f10x.h"

#define MAX6675_CS1_CLK   RCC_APB2Periph_GPIOA
#define MAX6675_CS1_PORT  GPIOA
#define MAX6675_CS1_PIN   GPIO_Pin_4

void max6675_init(void);			 //��ʼ��max6675ģ�� 
uint8_t max6675_readWriteByte(uint8_t txData); //max6675ģ���дһ���ֽ�
uint16_t max6675_readRawValue(void);
float max6675_readTemperature(void);


#endif
