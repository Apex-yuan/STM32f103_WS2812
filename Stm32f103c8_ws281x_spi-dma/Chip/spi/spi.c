#include "spi.h"


/**
  * @brief  硬件spi1初始化
  * @param  None
  * @retval None
  */
void spi1_init(void)
{
 	GPIO_InitTypeDef GPIO_InitStructure;
  SPI_InitTypeDef  SPI_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //PORTA时钟使能 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE); //SPI1时钟使能 	

  /* PA5  SPI1_SCK  */
  /* PA6  SPI1_MISO */
  /* PA7  SPI1_MOSI */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //PA5/6/7复用推挽输出 SPI
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA

	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //设置SPI单向或者双向的数据模式:SPI设置为双线双向全双工
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//设置SPI工作模式:设置为主SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		//设置SPI的数据大小:SPI发送接收8位帧结构
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;		//串行同步时钟的空闲状态为低电平
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;	//串行同步时钟的第1个跳变沿（上升或下降）数据被采样
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		//NSS信号由硬件（NSS管脚）还是软件（使用SSI位）管理:内部NSS信号有SSI位控制
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;		//定义波特率预分频的值:波特率预分频值为256
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	//指定数据传输从MSB位还是LSB位开始:数据传输从MSB位开始
	SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRC值计算的多项式
	SPI_Init(SPI1, &SPI_InitStructure);  //根据SPI_InitStruct中指定的参数初始化外设SPIx寄存器
 
	SPI_Cmd(SPI1, ENABLE); //使能SPI外设

} 

/**
  * @brief  设定spi1的速度
  * @param  SPI_BaudRatePrescaler：分频数 参数如下：
  *             SPI_BaudRatePrescaler_2   2分频   
  *             SPI_BaudRatePrescaler_8   8分频   
  *             SPI_BaudRatePrescaler_16  16分频  
  *             SPI_BaudRatePrescaler_256 256分频 
  * @retval None
  */
void spi1_setSpeed(uint8_t SPI_BaudRatePrescaler)
{
  assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler));
	SPI1->CR1&=0XFFC7;
	SPI1->CR1|=SPI_BaudRatePrescaler;	//设置SPI2速度 
	SPI_Cmd(SPI1,ENABLE); 
} 

/**
  * @brief  通过硬件spi1读写一个字节的数据
  * @param  txData：要发送的数据
  * @retval 通过spi接收到的数据
  */
uint8_t spi1_readWriteByte(uint8_t txData)
{		
	uint8_t retry = 0;
  /* Loop while DR register in not emplty */  
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET) //检查指定的SPI标志位设置与否:发送缓存空标志位
	{
		retry++;
		if(retry > 200) return 0;
	}			  
	SPI_I2S_SendData(SPI1, txData); //通过外设SPIx发送一个数据( 只有先发送数据才能使能SCK引脚产生时钟)
	
  retry=0;
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET) //检查指定的SPI标志位设置与否:接受缓存非空标志位
	{
		retry++;
		if(retry > 200) return 0;
	}	  						    
	return SPI_I2S_ReceiveData(SPI1); //返回通过SPIx最近接收的数据					    
}  
