#include "relay.h"


void relay_init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd(RELAY_IN_CLOCK,ENABLE);
  
  GPIO_InitStructure.GPIO_Pin = RELAY_IN_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(RELAY_IN_PORT, &GPIO_InitStructure);
  
  GPIO_ResetBits(RELAY_IN_PORT, RELAY_IN_PIN);
  
}

void relay_on(void)
{
  GPIO_SetBits(RELAY_IN_PORT, RELAY_IN_PIN);
}

void relay_off(void)
{
  GPIO_ResetBits(RELAY_IN_PORT,RELAY_IN_PIN);
}



