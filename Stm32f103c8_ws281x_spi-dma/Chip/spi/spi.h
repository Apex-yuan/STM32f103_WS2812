#ifndef __SPI_H
#define __SPI_H

#include "stm32f10x.h"


void spi1_init(void);	//��ʼ��SPI1��
void spi1_setSpeed(u8 SpeedSet); //����SPI1�ٶ�   
uint8_t spi1_readWriteByte(uint8_t txData); //SPI1���߶�дһ���ֽ�
		 
#endif

