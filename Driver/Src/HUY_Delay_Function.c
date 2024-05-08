#include "HUY_STM32F103.h"
#include "HUY_Delay_Function.h"

void delay_ms(uint32_t time, uint32_t HCLK_Freq)
{
	for (uint32_t i =0; i<time;i++)
	{
		HUY_Systick ->LOAD.bit.RELOAD = (HCLK_Freq/1000)-1;
		HUY_Systick ->VAL.bit.CURRENT =0;
		HUY_Systick ->CTRL.reg =5;
		while(HUY_Systick->CTRL.bit.COUNTFLAG ==0);
	}
}


void delay_us(uint32_t time, uint32_t HCLK_Freq)
{
	for (uint32_t i=0;i<time;i++)
	{
		HUY_Systick ->LOAD.bit.RELOAD = (HCLK_Freq/1000000)-1;
		HUY_Systick ->VAL.bit.CURRENT =0;
		HUY_Systick ->CTRL.reg =5;
		while(HUY_Systick->CTRL.bit.COUNTFLAG ==0);
	}
}
