#ifndef __HUMAN_INDUCTION_H
#define __HUMAN_INDUCTION_H

#include "stm32f10x.h"
#include "chip.h"


//TrigÒý½Åºê¶¨Òå
#define HUMAN_INDUCTION_OUT_CLOCK RCC_APB2Periph_GPIOA
#define HUMAN_INDUCTION_OUT_PORT GPIOA
#define HUMAN_INDUCTION_OUT_PIN  GPIO_Pin_3


void human_induction_init(void);
uint8_t human_induction_check(void);


#endif /* __HUMAN_INDUCTION_H */

