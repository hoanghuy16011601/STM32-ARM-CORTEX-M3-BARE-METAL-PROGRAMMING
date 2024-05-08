#include "STM32F103.h"
#include "SPI.h"
#include "stdarg.h"
#include "GPIO.h"




void SPI_init_master(uint8_t type,int baudrate,...)
{
	if (type == SPI1_MODE)
	{
		int value;
		RCC->APB2ENR.bit.AFIOEN =1;
		RCC->APB2ENR.bit.IOPAEN =1;
		RCC->APB2ENR.bit.SPI1EN =1;
		GPIO_MODE(GPIO_PORTA,4,OUTPUT_50MHZ,OP_GENERAL_PUSH_PULL);
		GPIO_MODE(GPIO_PORTA,5,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL);
		GPIO_MODE(GPIO_PORTA,6,INPUT,IP_PULL_UP_DOWN);
		GPIO_MODE(GPIO_PORTA,7,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL);
		SPI1->CR1.bit.BR =(uint16_t) baudrate;
		va_list data;
		va_start (data,baudrate);
		while (( value = va_arg(data,int)) != 0)
		{
			SPI1->CR1.reg |= (1<<value);
		}
		va_end(data);
		SPI1->CR1.bit.MSTR =1;
		SPI1->CR2.bit.SSOE =1;
		SPI1->CR1.bit.SPE =1;
	}
	
	else if (type == SPI2_MODE)
	{
		RCC->APB2ENR.bit.AFIOEN =1;
		RCC->APB2ENR.bit.IOPBEN =1;
		RCC->APB1ENR.bit.SPI2EN =1;
		GPIO_MODE(GPIO_PORTB,12,OUTPUT_50MHZ,OP_GENERAL_PUSH_PULL);
		GPIO_MODE(GPIO_PORTB,13,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL);
		GPIO_MODE(GPIO_PORTB,14,INPUT,IP_PULL_UP_DOWN);
		GPIO_MODE(GPIO_PORTB,15,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL);
		SPI2_I2S->CR1.bit.BR =(uint16_t) baudrate;
		va_list data;
		va_start (data,baudrate);
		int value;
		while (( value = va_arg(data,int)) != 0)
		{
			SPI2_I2S->CR1.reg |= (1<<value);
		}
		va_end(data);
		SPI2_I2S->CR1.bit.MSTR =1;
		SPI2_I2S->CR1.bit.SPE =1;
	}
	
	else
	{
		RCC->APB2ENR.bit.AFIOEN =1;
		RCC->APB2ENR.bit.IOPBEN =1;
		RCC->APB2ENR.bit.IOPAEN =1;
		RCC->APB1ENR.bit.SPI3EN =1;
		GPIO_MODE(GPIO_PORTA,15,OUTPUT_50MHZ,OP_GENERAL_PUSH_PULL);
		GPIO_MODE(GPIO_PORTB,3,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL);
		GPIO_MODE(GPIO_PORTB,4,INPUT,IP_PULL_UP_DOWN);
		GPIO_MODE(GPIO_PORTB,5,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL);
		SPI3_I2S->CR1.bit.BR =(uint16_t) baudrate;
		va_list data;
		va_start (data,baudrate);
		int value;
		while (( value = va_arg(data,int)) != 0)
		{
			SPI3_I2S->CR1.reg |= (1<<value);
		}
		va_end(data);
		SPI3_I2S->CR1.bit.MSTR =1;
		SPI3_I2S->CR1.bit.SPE =1;
	}
}


uint16_t SPI_full_duxplex_16bit(uint8_t type,uint16_t data)
{
	if (type == SPI1_MODE)
	{
		while(SPI1->SR.bit.TXE == 0);
		WRITE_GPIO_PIN(GPIO_PORTA,4,LOW);
		SPI1->DR.bit.DATA = data;
		while(SPI1->SR.bit.RXNE ==0);
		data =(uint16_t) SPI1->DR.bit.DATA;
		WRITE_GPIO_PIN(GPIO_PORTA,4,HIGH);
		return data;
	}
	else if (type == SPI2_MODE)
	{
		while(SPI2_I2S->SR.bit.TXE == 0);
		WRITE_GPIO_PIN(GPIO_PORTA,4,LOW);
		SPI2_I2S->DR.bit.DATA = data;
		while(SPI2_I2S->SR.bit.RXNE ==0);
		data = (uint16_t) SPI2_I2S->DR.bit.DATA;
		WRITE_GPIO_PIN(GPIO_PORTA,4,HIGH);
		return data;
	}
	else
	{
		while(SPI3_I2S->SR.bit.TXE == 0);
		WRITE_GPIO_PIN(GPIO_PORTA,4,LOW);
		SPI3_I2S->DR.bit.DATA = data;
		while(SPI3_I2S->SR.bit.RXNE ==0);
		data =(uint16_t) SPI3_I2S->DR.bit.DATA;
		WRITE_GPIO_PIN(GPIO_PORTA,4,HIGH);
		return data;
	}
}


uint8_t SPI_full_duxplex_8bit(uint8_t type,uint8_t data)
{
	if (type == SPI1_MODE)
	{
		while(SPI1->SR.bit.TXE == 0);
		WRITE_GPIO_PIN(GPIO_PORTA,4,LOW);
		SPI1->DR.bit.DATA =data;
		while(SPI1->SR.bit.RXNE ==0);
		data = (uint8_t) SPI1->DR.bit.DATA;
		WRITE_GPIO_PIN(GPIO_PORTA,4,HIGH);
		return data;
	}
	else if (type == SPI2_MODE)
	{
		while(SPI2_I2S->SR.bit.TXE == 0);
		WRITE_GPIO_PIN(GPIO_PORTA,4,LOW);
		SPI2_I2S->DR.bit.DATA = (uint32_t) data;
		while(SPI2_I2S->SR.bit.RXNE ==0);
		data = (uint8_t) SPI2_I2S->DR.bit.DATA;
		WRITE_GPIO_PIN(GPIO_PORTA,4,HIGH);
		return data;
	}
	else
	{
		while(SPI3_I2S->SR.bit.TXE == 0);
		WRITE_GPIO_PIN(GPIO_PORTA,4,LOW);
		SPI3_I2S->DR.bit.DATA = (uint32_t) data;
		while(SPI3_I2S->SR.bit.RXNE ==0);
		data = (uint8_t) SPI3_I2S->DR.bit.DATA;
		WRITE_GPIO_PIN(GPIO_PORTA,4,HIGH);
		return data;
	}
}

	









