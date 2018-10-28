#ifndef __RELAY_H
#define __RELAY_H

#include "chip.h"
#include "stm32f10x.h"

#define RELAY_IN_CLOCK RCC_APB2Periph_GPIOB
#define RELAY_IN_PORT GPIOB
#define RELAY_IN_PIN GPIO_Pin_11


void relay_init(void);
void relay_on(void);
void relay_off(void);


#endif /* __RELAY_H */

