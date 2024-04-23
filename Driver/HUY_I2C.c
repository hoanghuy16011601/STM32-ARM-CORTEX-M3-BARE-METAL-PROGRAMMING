#include "HUY_STM32F103.h"
#include "HUY_GPIO.h"
#include "HUY_I2C.h"
#include "stdarg.h"

void I2C_init(uint8_t Select_I2C, uint8_t freq_MHZ, uint8_t mode_clk,float SCL_CLOCK,int option ,...)
{
	HUY_I2C_Struct * I2C_Selected;
	HUY_RCC->APB1ENR.reg |= (1<<Select_I2C);
	HUY_RCC->APB2ENR.bit.AFIOEN =1;
	switch(Select_I2C)
	{
		default 			: I2C_Selected = HUY_I2C1; 
										GPIO_MODE_MULTI_PIN(GPIO_PORTB,OUTPUT_50MHZ,OP_ALTERNATE_OPEN_DRAIN,2,6,7);  //// SCL = PB6 ; SDA = PB7 
										break;
		case I2C2_MODE: I2C_Selected = HUY_I2C2;
										GPIO_MODE_MULTI_PIN(GPIO_PORTB,OUTPUT_50MHZ,OP_ALTERNATE_OPEN_DRAIN,2,10,11);  //// SCL = PB10 ; SDA = PB11 
										break;
	}
	I2C_Selected->CR1.bit.SWRST =1;
	I2C_Selected->CR1.bit.SWRST =0;
	I2C_Selected->CR2.bit.FREQ = freq_MHZ;
	if(mode_clk == I2C_Fast_MODE)
	{
		uint16_t data;
		uint8_t data2;
		uint32_t maximum_rise_time_freq = 3333333; // 1/300nano
		I2C_Selected->CCR.bit.F_S =1;
		data = (uint16_t) ((freq_MHZ*1000000)/(3*SCL_CLOCK));
		I2C_Selected->CCR.bit.CCR = data;
		data2 = (uint8_t) ((freq_MHZ*1000000)/maximum_rise_time_freq);
		I2C_Selected->TRISE.bit.TRISE = data2 +1;
	}
	else 
	{
		uint16_t data;
		uint8_t data2;
		uint32_t maximum_rise_time_freq = 1000000; // 1/1000nano
		I2C_Selected->CCR.bit.F_S =0;
		data = (uint16_t) ((freq_MHZ*1000000)/(2*SCL_CLOCK));
		I2C_Selected->CCR.bit.CCR = data;
		data2 = (uint8_t) ((freq_MHZ*1000000)/maximum_rise_time_freq);
		I2C_Selected->TRISE.bit.TRISE = data2 +1;
	}
	I2C_Selected->CR1.bit.PE=1;
	if (option == I2C_HAVE_OPTION_CR1)
	{
		int value;
		va_list data;
		va_start (data,option);
		while((value = va_arg(data,int)) != 0)
		{
			I2C_Selected->CR1.reg |= (1<<value);
		}
		va_end (data);
	}
}

uint8_t I2C_Start(uint8_t Select_I2C,uint8_t I2C_Direction ,uint8_t Number_Bit_Address, uint16_t Address)
{
	HUY_I2C_Struct * I2C_Selected;
	volatile uint32_t tmp;
	switch(Select_I2C)
	{
		default 			:	I2C_Selected = HUY_I2C1; break;
		case I2C2_MODE: I2C_Selected = HUY_I2C2; break;
	}
	START:
	I2C_Selected->CR1.bit.START =1;
	while(I2C_Selected->SR1.bit.SB ==0);
	tmp = I2C_Selected->SR1.reg;  // FINISH V5: CLEAR SB
	if (Number_Bit_Address == I2C_Address_7_Bit)
	{
		Address =(uint8_t) (Address<<1|I2C_Direction);
		I2C_Selected->DR.reg= Address;
		while(I2C_Selected->SR1.bit.ADDR ==0);
	}
	else
	{
		uint16_t address2 = Address>>7&0x06;
		uint8_t data = (uint8_t) (0xF0|address2|I2C_Direction);
		I2C_Selected->DR.bit.DATA = data;
		while(I2C_Selected->SR1.bit.ADD10 ==0);
		I2C_Selected->DR.bit.DATA = (uint8_t) Address;
		while(I2C_Selected->SR1.bit.ADDR ==0);
	}
	if (I2C_Selected->SR1.bit.AF ==1)
	{
		static uint8_t count =0;
		if(count < 3)
		{
			count+=1;
			goto START;    /// REPEAT START
		}
		return I2C_NO_ADDRESS_MATCH;  /// NO SLAVE ADRRESS MATCH
	}
	tmp = I2C_Selected->SR1.reg;  /// FINISH V6: CLEAR ADDR
	tmp = I2C_Selected->SR2.reg;
	return I2C_ADDRESS_MATCH;
}


void I2C_Transmit_Data(uint8_t Select_I2C,unsigned char Data)
{
	HUY_I2C_Struct * I2C_Selected;
	switch(Select_I2C)
	{
		default   		: I2C_Selected = HUY_I2C1; break;
		case I2C2_MODE:	I2C_Selected = HUY_I2C2; break;
	}
	while(I2C_Selected->SR1.bit.TXE == 0);
	I2C_Selected->DR.bit.DATA = Data;
	while(I2C_Selected->SR1.bit.BTF == 0);
}



void I2C_Stop(uint8_t Select_I2C)
{
	HUY_I2C_Struct * I2C_Selected;
	switch(Select_I2C)
	{
		default   		: I2C_Selected = HUY_I2C1; break;
		case I2C2_MODE:	I2C_Selected = HUY_I2C2; break;
	}
	while(I2C_Selected->SR1.bit.TXE == 0 || HUY_I2C1->SR1.bit.BTF ==0);
	I2C_Selected->CR1.bit.STOP =1;
}
