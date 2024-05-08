#include "STM32F103.h"
#include "GPIO.h"
#include "I2C.h"
#include "stdarg.h"

void I2C_init(uint8_t i2c, uint8_t freq_MHZ, uint8_t mode_clk,float SCL_CLOCK,int option ,...)
{
	if (i2c == I2C1_MODE)
	{
		RCC->APB1ENR.bit.I2C1EN = 1;
		RCC->APB2ENR.bit.AFIOEN =1;
		GPIO_MODE_MULTI_PIN(GPIO_PORTB,OUTPUT_50MHZ,OP_ALTERNATE_OPEN_DRAIN,2,6,7);  //// SCL = PB6 ; SDA =PB7
		I2C1->CR1.bit.SWRST =1;
		I2C1->CR1.bit.SWRST =0;
		I2C1->CR2.bit.FREQ = freq_MHZ;
		if(mode_clk == Fast_MODE)
		{
			uint32_t maximum_rise_time_freq = 3333333; // 1/300nano
			I2C1->CCR.bit.F_S =1;
			uint16_t data = (uint16_t) ((freq_MHZ*1000000)/(3*SCL_CLOCK));
			I2C1->CCR.bit.CCR = data;
			uint8_t data2 = (uint8_t) ((freq_MHZ*1000000)/maximum_rise_time_freq);
			I2C1->TRISE.bit.TRISE = data2 +1;
		}
		else 
		{
			uint32_t maximum_rise_time_freq = 1000000; // 1/1000nano
			I2C1->CCR.bit.F_S =0;
			uint16_t data = (uint16_t) ((freq_MHZ*1000000)/(2*SCL_CLOCK));
			I2C1->CCR.bit.CCR = data;
			uint8_t data2 = (uint8_t) ((freq_MHZ*1000000)/maximum_rise_time_freq);
			I2C1->TRISE.bit.TRISE = data2 +1;
		}
		I2C1->CR1.bit.PE=1;
		if (option == HAVE_OPTION_CR1)
		{
			int value;
			va_list data;
			va_start (data,option);
			while((value = va_arg(data,int)) != 0)
			{
				I2C1->CR1.reg |= (1<<value);
			}
			va_end (data);
		}
	}
	else
	{
		RCC->APB1ENR.bit.I2C2EN =1;
		RCC->APB2ENR.bit.AFIOEN =1;
		GPIO_MODE_MULTI_PIN(GPIO_PORTB,OUTPUT_50MHZ,OP_ALTERNATE_OPEN_DRAIN,2,10,11);  //// SCL =10 ; SDA = 11
		I2C2->CR1.bit.SWRST =1;
		I2C2->CR1.bit.SWRST =0;
		I2C2->CR2.bit.FREQ = freq_MHZ;
		if(mode_clk == Fast_MODE)
		{
			uint32_t maximum_rise_time_freq = 3333333; // 1/300nano
			I2C2->CCR.bit.F_S =1;
			uint16_t data = (uint16_t) ((freq_MHZ*1000000)/(3*SCL_CLOCK));
			I2C2->CCR.bit.CCR = data;
			uint8_t data2 = (uint8_t) ((freq_MHZ*1000000)/maximum_rise_time_freq);
			I2C2->TRISE.bit.TRISE = data2 +1;
		}
		else 
		{
			uint32_t maximum_rise_time_freq = 1000000; // 1/100nano
			I2C2->CCR.bit.F_S =0;
			uint16_t data = (uint16_t) ((freq_MHZ*1000000)/(2*SCL_CLOCK));
			I2C2->CCR.bit.CCR = data;
			uint8_t data2 = (uint8_t) ((freq_MHZ*1000000)/maximum_rise_time_freq);
			I2C2->TRISE.bit.TRISE = data2 +1;
		}
		if (option == HAVE_OPTION_CR1)
		{
			int value;
			va_list data;
			va_start (data,option);
			while((value = va_arg(data,int)) != 0)
			{
				I2C2->CR1.reg |= (1<<value);
			}
			va_end (data);
		}
		I2C2->CR1.bit.PE =1;
	}
}

uint8_t Send_address(uint8_t i2c,uint8_t mode ,uint8_t number_bit_address, uint16_t address)
{
	uint32_t tmp;
	if(i2c == I2C1_MODE)
	{
		START:
		I2C1->CR1.bit.START =1;
		while(I2C1->SR1.bit.SB ==0);
		tmp = I2C1->SR1.reg;  // FINISH V5: CLEAR SB
		if (number_bit_address == address_7_bit)
		{
			address =(uint8_t) (address<<1|mode);
			I2C1->DR.reg= address;
			//while(I2C1->SR1.bit.ADDR ==0);
		}
		else
		{
			uint16_t address2 = address>>7&0x06;
			uint8_t data = (uint8_t) (0xF0|address2|mode);
			I2C1->DR.bit.DATA = data;
			while(I2C1->SR1.bit.ADD10 ==0);
			I2C1->DR.bit.DATA = (uint8_t) address;
			while(I2C1->SR1.bit.ADDR ==0);
		}
		if (I2C1->SR1.bit.AF ==1)
		{
			static uint8_t count =0;
			if(count < 3)
			{
				count+=1;
				goto START;    /// REPEAT START
			}
			return NO_ADDRESS_MATCH;  /// NO SLAVE ADRRESS MATCH
		}
		tmp = I2C1->SR1.reg;  /// FINISH V6: CLEAR ADDR
		tmp = I2C1->SR2.reg;
		return ADDRESS_MATCH;
	}
	
	else
	{
		START2:
		I2C2->CR1.bit.START =1;
		while(I2C2->SR1.bit.SB ==0);
		tmp = I2C2->SR1.reg;  // FINISH V5: CLEAR SB
		if (number_bit_address == address_7_bit)
		{
			address =(uint8_t) (address<<1|mode);
			I2C2->DR.bit.DATA =(uint8_t) address;
			while(I2C2->SR1.bit.ADDR ==0);
		}
		else
		{
			uint16_t address2 = address>>7&0x06;
			uint8_t data = (uint8_t) (0xF0|address2|mode);
			I2C2->DR.bit.DATA = data;
			while(I2C2->SR1.bit.ADD10 ==0);
			I2C2->DR.bit.DATA = (uint8_t) address;
			while(I2C2->SR1.bit.ADDR ==0);
		}
		if (I2C2->SR1.bit.AF ==1)
		{
			static uint8_t count =0;
			if(count < 3)
			{
				count+=1;
				goto START2;    /// REPEAT START
			}
			return NO_ADDRESS_MATCH;  /// NO SLAVE ADRRESS MATCH
		}
		tmp = I2C2->SR1.reg;  /// FINISH V6: CLEAR ADDR
		tmp = I2C2->SR2.reg;
		return ADDRESS_MATCH;
	}	
}


void I2C_transmit_data(uint8_t i2c,unsigned char data)
{
	if(i2c == I2C1_MODE)
	{
		while(I2C1->SR1.bit.TXE == 0);
		I2C1->DR.bit.DATA = data;
	}
	else
	{
		while(I2C2->SR1.bit.TXE == 0);
		I2C2->DR.bit.DATA = data;
	}
}



void I2C_stop(uint8_t i2c)
{
	if (i2c == I2C1_MODE)
	{
		while(I2C1->SR1.bit.TXE == 0 || I2C1->SR1.bit.BTF ==0);
		I2C1->CR1.bit.STOP =1;
	}
	else
	{
		while(I2C2->SR1.bit.TXE == 0 || I2C2->SR1.bit.BTF ==0);
		I2C2->CR1.bit.STOP =1;
	}
}


void I2C_transmit_string(uint8_t i2c, uint8_t number_bit_address, uint16_t address,unsigned char string[])
{
	if(i2c == I2C1_MODE)
	{
		uint8_t i =0;
		i = Send_address(I2C1_MODE,Transmit,number_bit_address,address);
		if(i == NO_ADDRESS_MATCH)
		{
			return;
		}
		i=0;
		while(string[i] != '\0')
		{
			I2C_transmit_data(I2C1_MODE, string[i]);
			i+=1;
		}
	}
	
	else
	{
		uint8_t i =0;
		i = Send_address(I2C1_MODE,Transmit,number_bit_address,address);
		if(i == NO_ADDRESS_MATCH)
		{
			return;
		}
		i=0;
		while(string[i] != '\0')
		{
			I2C_transmit_data(I2C2_MODE,string[i]);
			i+=1;
		}
	}
}
