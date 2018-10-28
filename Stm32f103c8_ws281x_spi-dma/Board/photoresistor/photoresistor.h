#ifndef __PHOTORESISTOR_H
#define __PHOTORESISTOR_H

#include "chip.h"

//DO(数字端口输出)引脚定义
#define PHOTORESISTOR_DO_CLOCK RCC_APB2Periph_GPIOA
#define PHOTORESISTOR_DO_PORT GPIOA
#define PHOTORESISTOR_DO_PIN GPIO_Pin_0


void photoresistor_init(void);
uint8_t photoresistor_check(void);


#endif /* __PHOTORESISTOR_H */

