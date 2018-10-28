#include "photoresistor.h"


void photoresistor_init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd(PHOTORESISTOR_DO_CLOCK, ENABLE);
  
  GPIO_InitStructure.GPIO_Pin = PHOTORESISTOR_DO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(PHOTORESISTOR_DO_PORT, &GPIO_InitStructure);
}

uint8_t photoresistor_check(void)
{
  if(GPIO_ReadInputDataBit(PHOTORESISTOR_DO_PORT, PHOTORESISTOR_DO_PIN) == 1)
    return 1; //ºÚÒ¹
  else
    return 0; //°×Ìì
}


