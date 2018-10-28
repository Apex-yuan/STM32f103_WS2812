#include "spi.h"


/**
  * @brief  Ӳ��spi1��ʼ��
  * @param  None
  * @retval None
  */
void spi1_init(void)
{
 	GPIO_InitTypeDef GPIO_InitStructure;
  SPI_InitTypeDef  SPI_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //PORTAʱ��ʹ�� 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE); //SPI1ʱ��ʹ�� 	

  /* PA5  SPI1_SCK  */
  /* PA6  SPI1_MISO */
  /* PA7  SPI1_MOSI */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //PA5/6/7����������� SPI
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA

	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//����SPI����ģʽ:����Ϊ��SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		//����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;		//����ͬ��ʱ�ӵĿ���״̬Ϊ�͵�ƽ
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;	//����ͬ��ʱ�ӵĵ�1�������أ��������½������ݱ�����
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		//NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;		//���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ256
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRCֵ����Ķ���ʽ
	SPI_Init(SPI1, &SPI_InitStructure);  //����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
 
	SPI_Cmd(SPI1, ENABLE); //ʹ��SPI����

} 

/**
  * @brief  �趨spi1���ٶ�
  * @param  SPI_BaudRatePrescaler����Ƶ�� �������£�
  *             SPI_BaudRatePrescaler_2   2��Ƶ   
  *             SPI_BaudRatePrescaler_8   8��Ƶ   
  *             SPI_BaudRatePrescaler_16  16��Ƶ  
  *             SPI_BaudRatePrescaler_256 256��Ƶ 
  * @retval None
  */
void spi1_setSpeed(uint8_t SPI_BaudRatePrescaler)
{
  assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler));
	SPI1->CR1&=0XFFC7;
	SPI1->CR1|=SPI_BaudRatePrescaler;	//����SPI2�ٶ� 
	SPI_Cmd(SPI1,ENABLE); 
} 

/**
  * @brief  ͨ��Ӳ��spi1��дһ���ֽڵ�����
  * @param  txData��Ҫ���͵�����
  * @retval ͨ��spi���յ�������
  */
uint8_t spi1_readWriteByte(uint8_t txData)
{		
	uint8_t retry = 0;
  /* Loop while DR register in not emplty */  
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET) //���ָ����SPI��־λ�������:���ͻ���ձ�־λ
	{
		retry++;
		if(retry > 200) return 0;
	}			  
	SPI_I2S_SendData(SPI1, txData); //ͨ������SPIx����һ������( ֻ���ȷ������ݲ���ʹ��SCK���Ų���ʱ��)
	
  retry=0;
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET) //���ָ����SPI��־λ�������:���ܻ���ǿձ�־λ
	{
		retry++;
		if(retry > 200) return 0;
	}	  						    
	return SPI_I2S_ReceiveData(SPI1); //����ͨ��SPIx������յ�����					    
}  
