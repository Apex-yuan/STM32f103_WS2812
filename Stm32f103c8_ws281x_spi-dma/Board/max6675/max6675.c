#include "max6675.h"
#include "spi.h"


/**
  * @brief  max66675ģ���ʼ��
  * @param  None
  * @retval None
  */
void max6675_init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(MAX6675_CS1_CLK, ENABLE); //PORTAʱ��ʹ�� 
  
  GPIO_InitStructure.GPIO_Pin = MAX6675_CS1_PIN;  // PA4 ���� 	  T_CS
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(MAX6675_CS1_PORT, &GPIO_InitStructure);
 	GPIO_SetBits(MAX6675_CS1_PORT,MAX6675_CS1_PIN);	//	T_CS=1
  
  spi1_init();
} 

/**
  * @brief  max6675ģ���дһ���ֽڵ�����
  * @param  txData��Ҫ���͵�����
  * @retval ���յ�������
  */
uint8_t max6675_readWriteByte(uint8_t txData)
{		
  return spi1_readWriteByte(txData);
}  

/**
  * @brief  max6675ģ���ȡ��õ�ԭʼ����
  * @param  None
  * @retval �¶ȵ�ԭʼ����
  */
uint16_t max6675_readRawValue(void)
{
  uint16_t tmp;
  
  GPIO_ResetBits(MAX6675_CS1_PORT,MAX6675_CS1_PIN); //enable max6675
 
  tmp = max6675_readWriteByte(0XFF); //read MSB
  tmp <<= 8;
  tmp |= max6675_readWriteByte(0XFF); //read LSB
  
  GPIO_SetBits(MAX6675_CS1_PORT,MAX6675_CS1_PIN); //disable max6675
  if (tmp & 4) 
  {
    // thermocouple open
    tmp = 2000; //δ��⵽�ȵ�ż
  }
  else 
  {
    tmp = tmp >> 3;
  }

  return tmp;
}

/**
  * @brief  max6675ģ���ȡ��õ�ԭʼ����
  * @param  None
  * @retval �¶�ֵ����λ���棩
  */
float max6675_readTemperature(void)
{
  return (max6675_readRawValue() * 1024.0 / 4096);
}

