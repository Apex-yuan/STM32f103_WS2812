#include "human_induction.h"

void human_induction_init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd(HUMAN_INDUCTION_OUT_CLOCK, ENABLE);
  
  GPIO_InitStructure.GPIO_Pin = HUMAN_INDUCTION_OUT_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(HUMAN_INDUCTION_OUT_PORT, &GPIO_InitStructure);
}

uint8_t human_induction_check(void)
{
  if(GPIO_ReadInputDataBit(HUMAN_INDUCTION_OUT_PORT,HUMAN_INDUCTION_OUT_PIN))
    return 1; //有人
  else 
    return 0; //无人
}




