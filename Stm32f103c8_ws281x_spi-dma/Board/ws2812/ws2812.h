#ifndef __WS2812_H
#define __WS2812_H

#include "stm32f10x.h"

#define PIXEL_NUM 11

//Ӳ��spiģ��ws2811ʱ����spi��8λ����ģ��ws281x��һλ���ݣ�
//Ҫ��ϵͳʱ������Ϊ56M����Ƶ������Ϊ8����SPI��ͨ��Ƶ��Ϊ7M������һλ���ݵ�ʱ��ԼΪ143���루ns��
//3*143 = 429ns   5*143 = 715ns  ����WS281XоƬ��ͨ��ʱ��
//  _____   
// |     |___|   11111000  high level
//  ___         
// |   |_____|   11100000  low level

#define WS_HIGH 0XF8
#define WS_LOW  0XE0

void ws281x_init(void);
void ws281x_closeAll(void);
void ws281x_rainbowCycle(uint8_t wait);
uint32_t ws281x_color(uint8_t red, uint8_t green, uint8_t blue);
void ws281x_setPixelColor(uint16_t n ,uint32_t GRBcolor);
void ws281x_show(void);

void ws281x_theaterChase(uint32_t c, uint8_t wait);
void ws281x_colorWipe(uint32_t c, uint8_t wait);
void ws281x_rainbow(uint8_t wait);
void ws281x_theaterChaseRainbow(uint8_t wait);

#endif /* __WS2812_H */

