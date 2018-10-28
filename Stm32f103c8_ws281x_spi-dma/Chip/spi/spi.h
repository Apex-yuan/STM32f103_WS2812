#ifndef __SPI_H
#define __SPI_H

#include "stm32f10x.h"


void spi1_init(void);	//初始化SPI1口
void spi1_setSpeed(u8 SpeedSet); //设置SPI1速度   
uint8_t spi1_readWriteByte(uint8_t txData); //SPI1总线读写一个字节
		 
#endif

