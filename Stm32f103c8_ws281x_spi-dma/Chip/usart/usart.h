/**
  ******************************************************************************
  * @file    usart.h
  * @author  xiaoyuan
  * @version V2.0
  * @date    2018-1-28
  * @brief   �ṩ��USARTģ�麯��������
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#ifndef __USART_H
#define __USART_H

#include "stm32f10x.h"
/* Ҫ�õ�printf���������Ҫ����C���Եı�׼��������ļ� */
#include "stdio.h"  //�ڴ˴�����stdio.h�ļ���ˣ����ⲿ�ļ���ֻ�����usart.h�����ֱ��ʹ��printf��scanf�Ⱥ���


#define USE_MICROLIB      1  //(1)ʹ��΢��/��0����ʹ��΢�� ��ѡ��ʹ��΢����Ҫ��Option->Targetѡ�����й�ѡ��USE MicroLIB
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����



void usart1_init(uint32_t baud);


#endif //__USART_H
