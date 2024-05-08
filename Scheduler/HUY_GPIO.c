
#include "HUY_GPIO.h"
#include "HUY_STM32F103.h"




void GPIO_MODE (uint8_t PORT, uint8_t PIN,uint8_t MODE, uint8_t CNF)
	{
		HUY_GPIO_Struct * GPIO_Selected;
		volatile uint8_t MODE0 = MODE & 0x01;
		volatile uint8_t MODE1 = (MODE & 0x02)>>1;
		volatile uint8_t CNF0 = CNF & 0x01;
		volatile uint8_t CNF1 = (CNF & 0x02)>>1;
		HUY_RCC->APB2ENR.reg |= (1<<PORT);
		switch(PORT)
		{
			case GPIO_PORTB: GPIO_Selected = HUY_GPIO_PORTB; break;
			case GPIO_PORTC: GPIO_Selected = HUY_GPIO_PORTC; break;
			default: GPIO_Selected = HUY_GPIO_PORTA; break;
		}
		if(PIN<=7)
		{
			GPIO_Selected->CRL.reg &= ~((1<<PIN*4)|(1<<(PIN*4+1))|(1<<(PIN*4+2))|(1<<(PIN*4+3)));
			GPIO_Selected->CRL.reg |= (uint32_t) ((MODE0<<(PIN*4))|(MODE1<<(PIN*4+1))|(CNF0<<(PIN*4 +2))|(CNF1<<(PIN*4+3)));
		}
		else 
		{
			PIN -= 8;
			GPIO_Selected->CRH.reg &= ~((1<<PIN*4)|(1<<(PIN*4+1))|(1<<(PIN*4+2))|(1<<(PIN*4+3)));
			GPIO_Selected->CRH.reg |= (uint32_t) ((MODE0<<(PIN*4))|(MODE1<<(PIN*4+1))|(CNF0<<(PIN*4 +2))|(CNF1<<(PIN*4+3)));
		}
	}
	
	
	
void GPIO_MODE_MULTI_PIN (uint8_t PORT, uint8_t MODE, uint8_t CNF,int numberpin,...)
	{
		HUY_GPIO_Struct * GPIO_Selected;
		volatile uint8_t MODE0 = MODE & 0x01;
		volatile uint8_t MODE1 = (MODE & 0x02)>>1;
		volatile uint8_t CNF0 = CNF & 0x01;
		volatile uint8_t CNF1 = (CNF & 0x02)>>1;
		volatile int PIN;
		va_list data;
		HUY_RCC->APB2ENR.reg |= (1<<PORT);
		switch(PORT)
		{
			case GPIO_PORTB: GPIO_Selected = HUY_GPIO_PORTB; break;
			case GPIO_PORTC: GPIO_Selected = HUY_GPIO_PORTC; break;
			default: GPIO_Selected = HUY_GPIO_PORTA; break;
		}
		va_start (data,numberpin);
		for (uint8_t i =0; i<numberpin;i++)
		{
			PIN = va_arg(data,int);
			if(PIN<=7)
			{
				GPIO_Selected->CRL.reg &= (uint32_t) (~((1<<PIN*4)|(1<<(PIN*4+1))|(1<<(PIN*4+2))|(1<<(PIN*4+3))));
				GPIO_Selected->CRL.reg |= (uint32_t) ((MODE0<<(PIN*4))|(MODE1<<(PIN*4+1))|(CNF0<<(PIN*4 +2))|(CNF1<<(PIN*4+3)));
			}
			else
			{
				PIN -=8;
				GPIO_Selected->CRH.reg &= (uint32_t) (~((1<<PIN*4)|(1<<(PIN*4+1))|(1<<(PIN*4+2))|(1<<(PIN*4+3))));
				GPIO_Selected->CRH.reg |= (uint32_t) ((MODE0<<(PIN*4))|(MODE1<<(PIN*4+1))|(CNF0<<(PIN*4 +2))|(CNF1<<(PIN*4+3)));
			}
		}
		va_end (data);
	}
	
	
	
	
uint8_t READ_GPIO_PIN(uint8_t PORT, uint8_t PIN)
	{
		HUY_GPIO_Struct  * GPIO_Selected;
		switch(PORT)
		{
			case GPIO_PORTB: GPIO_Selected = HUY_GPIO_PORTB; break;
			case GPIO_PORTC: GPIO_Selected = HUY_GPIO_PORTC; break;
			default: GPIO_Selected = HUY_GPIO_PORTA; break;
		}
			return(uint8_t)((GPIO_Selected->IDR.Data&(1<<PIN))>>PIN);
	}
	
	
	
	
uint16_t READ_GPIO_PORT(uint8_t PORT)
	{
		HUY_GPIO_Struct  * GPIO_Selected;
		switch(PORT)
		{
			case GPIO_PORTB: GPIO_Selected = HUY_GPIO_PORTB; break;
			case GPIO_PORTC: GPIO_Selected = HUY_GPIO_PORTC; break;
			default: GPIO_Selected = HUY_GPIO_PORTA; break;
		}
		return GPIO_Selected->IDR.Data;
	}
	
	
	
	
void WRITE_GPIO_PIN(uint8_t PORT, uint8_t PIN,uint8_t CMD)
	{
		HUY_GPIO_Struct  * GPIO_Selected;
		switch(PORT)
		{
			case GPIO_PORTB: GPIO_Selected = HUY_GPIO_PORTB; break;
			case GPIO_PORTC: GPIO_Selected = HUY_GPIO_PORTC; break;
			default: GPIO_Selected = HUY_GPIO_PORTA; break;
		}
		if (CMD == HIGH)
		{
			GPIO_Selected->ODR.Data |= (1<<PIN);
		}
		else
		{
			GPIO_Selected->ODR.Data &= ~(1<<PIN);
		}
	}
	
	
	
	
void WRITE_GPIO_PORT(uint8_t PORT,uint16_t CMD)
	{
		HUY_GPIO_Struct  * GPIO_Selected;
		switch(PORT)
		{
			case GPIO_PORTB: GPIO_Selected = HUY_GPIO_PORTB; break;
			case GPIO_PORTC: GPIO_Selected = HUY_GPIO_PORTC; break;
			default: GPIO_Selected = HUY_GPIO_PORTA; break;
		}
		GPIO_Selected->ODR.Data = CMD;

	}
