#ifndef __JSN_SR04_H
#define __JSN_SR04_H

#include "stm32f10x.h"

#define JSN_SR04T_TRIG_CLK   RCC_APB2Periph_GPIOA
#define JSN_SR04T_TRIG_PORT  GPIOA
#define JSN_SR04T_TRIG_PIN   GPIO_Pin_4

#define JSN_SR04T_ECHO_CLK   RCC_APB2Periph_GPIOA
#define JSN_SR04T_ECHO_PORT  GPIOA
#define JSN_SR04T_ECHO_PIN   GPIO_Pin_5

#define JSN_SR04T_ECHO_EXTI_PORT_SOURCE   GPIO_PortSourceGPIOA
#define JSN_SR04T_ECHO_EXTI_PIN_SOURCE  GPIO_PinSource5



extern float Distance;


void jsn_sr04t_init(void);
void jsn_sr04t_start(void);



#endif /* __JSN_SR04_H*/





