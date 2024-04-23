
#include "HUY_RCC.h"
#include "HUY_STM32F103.h"
#include "math.h"

void Configure_HSE_Clock(uint8_t HSE_Divided)
{
	HUY_RCC->CR.bit.HSEBYP = HUY_RCC_CR_HSEBYP_HSE_NotBypass;
	HUY_RCC->CR.bit.HSEON = HUY_RCC_CR_HSEON_HSE_ON;
	while(HUY_RCC->CR.bit.HSERDY == HUY_RCC_CR_HSERDY_HSE_NotReady)
	{
		static uint16_t count =0;
		count++;
		if(count ==500) return;
	}
	HUY_RCC->CFGR.bit.PLLXTPRE = HSE_Divided;
}


void Configure_PLL_Clock(uint8_t PLLCLK_Select_InputClock, uint8_t PLL_Multiple)
{
	HUY_RCC->CR.bit.PLLON = HUY_RCC_CR_PLLON_PLL_OFF;
	HUY_RCC->CFGR.bit.PLLSRC = PLLCLK_Select_InputClock;
	HUY_RCC->CFGR.bit.PLLMUL = PLL_Multiple;
	HUY_RCC->CR.bit.PLLON = HUY_RCC_CR_PLLON_PLL_ON;
	while(HUY_RCC->CR.bit.PLLRDY == HUY_RCC_CR_PLLRDY_PLL_UnLocked);
}
	
void Configure_System_Clock(uint8_t SYSCLK_Select_InputClock, uint8_t AHB_Prescaler,uint8_t APB1_Prescaler, uint8_t APB2_Prescaler, uint8_t ADC_Prescaler)
{
	HUY_RCC->CFGR.bit.HPRE = AHB_Prescaler;
	HUY_RCC->CFGR.bit.PPRE1 = APB1_Prescaler;
	HUY_RCC->CFGR.bit.PPRE2 = APB2_Prescaler;
	HUY_RCC->CFGR.bit.ADCPRE = ADC_Prescaler;
	HUY_RCC->CFGR.bit.SW = SYSCLK_Select_InputClock;
	while(HUY_RCC->CFGR.bit.SWS != SYSCLK_Select_InputClock);
}


void Configure_Microcontroler_ClockOuput(uint8_t MCO_Select_InputClock)
{
	HUY_RCC->CFGR.bit.MCO = MCO_Select_InputClock;
}



uint32_t Read_Clock(uint8_t Clock)
{
	uint32_t HSE_CLOCK = 8000000;
	uint32_t HSI_CLOCK = 8000000;
	uint32_t PLLXTPRE_CLOCK = 8000000;
	uint32_t PLL_CLOCK = HSI_CLOCK/2;
	uint32_t SYS_CLOCK = HSI_CLOCK;
	uint32_t HCLK = SYS_CLOCK;
	uint32_t MCO_CLOCK =0;
	uint32_t PCLK1 =0;
	uint32_t PCLK2 =0;
	uint32_t TIMER1_CLOCK = 0;
	uint32_t TIMER234_CLOCK =0;

//calculate PLLXTRE_CLOCK
	if (HUY_RCC->CFGR.bit.PLLXTPRE == HSE_Divided2) PLLXTPRE_CLOCK = HSE_CLOCK/2;
	if(HUY_RCC->CFGR.bit.PLLSRC == PLL_Select_HSE) PLL_CLOCK = PLLXTPRE_CLOCK;

	//calculate PLL CLOCK
	PLL_CLOCK = PLL_CLOCK *(HUY_RCC->CFGR.bit.PLLMUL +2);
	if(Clock == READ_PLL_Clock_Output) return PLL_CLOCK;

//calculate SYSCLK
	if(HUY_RCC->CFGR.bit.SWS ==SYSCLK_Select_HSE)
	{
		SYS_CLOCK = HSE_CLOCK;
	}
	else if(HUY_RCC->CFGR.bit.SWS == SYSCLK_Select_PLL)
	{
		SYS_CLOCK = PLL_CLOCK;
	}

//calculate HCLK
	HCLK = SYS_CLOCK;
	if((HUY_RCC->CFGR.bit.HPRE&0x08)==0);
	else if(HUY_RCC->CFGR.bit.HPRE<=0X0B)
	{
		uint8_t exponent = (HUY_RCC->CFGR.bit.HPRE&0X07)+1;
		HCLK =(uint32_t) (HCLK/pow(2,exponent));
	}
	else
	{
		uint8_t exponent = (HUY_RCC->CFGR.bit.HPRE&0X07)+2;
		HCLK =(uint32_t) (HCLK/pow(2,exponent));
	}
//calculate MCO_Clock
	if(HUY_RCC->CFGR.bit.MCO== HUY_RCC_CFGR_MCO_HSICLK_Selected)
	{
		MCO_CLOCK = HSI_CLOCK;
	}
	else if (HUY_RCC->CFGR.bit.MCO == HUY_RCC_CFGR_MCO_HSECLK_Selected)
	{
		MCO_CLOCK = HSE_CLOCK;
	}
	else if (HUY_RCC->CFGR.bit.MCO == HUY_RCC_CFGR_MCO_SYSCLK_Selected)
	{
		MCO_CLOCK = SYS_CLOCK;
	}
	else if(HUY_RCC->CFGR.bit.MCO == HUY_RCC_CFGR_MCO_PLLCLK_Divided2_Selected)
	{
		MCO_CLOCK = PLL_CLOCK/2;
	}
	
//calculate PCLK1 AND TIMER234_CLOCK
	if((HUY_RCC->CFGR.bit.PPRE1&0x04) ==0)
		{
			PCLK1 = HCLK;
			TIMER234_CLOCK = PCLK1;
		}
	else
	{
		uint8_t exponent = (HUY_RCC->CFGR.bit.PPRE1&0X03)+1;
		PCLK1 =(uint32_t) (HCLK/pow(2,exponent));
		TIMER234_CLOCK = PCLK1*2;
	}
	
//calculate PCLK2 and TIMER1_CLOCK
	if((HUY_RCC->CFGR.bit.PPRE2&0x04) ==0)
	{
		PCLK2 =HCLK;
		TIMER1_CLOCK = PCLK2;
	}
	else
	{
		uint8_t exponent = (HUY_RCC->CFGR.bit.PPRE1&0X03)+1;
		PCLK2 =(uint32_t) (HCLK/pow(2,exponent));
		TIMER1_CLOCK = PCLK2*2;
	}
	
	
	
	
/// return value
	if(Clock == READ_System_Clock_Output) return SYS_CLOCK;
	else if (Clock == READ_AHP_Clock_Output) return HCLK;
	else if (Clock == READ_ADC_Clock_Output) return HCLK*(HUY_RCC->CFGR.bit.ADCPRE+1);
	else if (Clock == READ_MCO_Clock_Output) return MCO_CLOCK;
	else if (Clock == READ_APB1_Clock_Output) return PCLK1;
	else if(Clock == READ_APB2_Clock_Output) return PCLK2;
	else if(Clock == READ_TIMER1_Clock_INPUT) return TIMER1_CLOCK;
	else return TIMER234_CLOCK;
}


