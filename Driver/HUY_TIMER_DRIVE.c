#include "HUY_TIMER_DRIVE.h"
#include "HUY_STM32F103.h"
#include "HUY_GPIO.h"
#include "stdarg.h"

void Configure_TIMER1(uint8_t Auto_reload_Preload, uint8_t Aligned_Mode,uint8_t Direction,uint8_t Clock_Division)
{
	HUY_RCC->APB2ENR.bit.TIM1EN =1;
	HUY_TIMER1->CR1.bit.CEN =0;
	HUY_TIMER1->CR1.bit.APRE = Auto_reload_Preload;
	HUY_TIMER1->CR1.bit.CMS = Aligned_Mode;
	HUY_TIMER1->CR1.bit.DIR = Direction;
	HUY_TIMER1->CR1.bit.CKD = Clock_Division;
}


void Configure_TIMER2345(uint8_t Select_Timer,uint8_t Auto_reload_Preload, uint8_t Aligned_Mode,uint8_t Direction,uint8_t Clock_Division)
{
	HUY_TIMER2345_Struct * TIMER_SELECTED;
	HUY_RCC->APB1ENR.reg |= (1<<Select_Timer);
	switch (Select_Timer)
	{
		default : TIMER_SELECTED = HUY_TIMER2; break;
		case Select_Timer3: TIMER_SELECTED = HUY_TIMER3; break;
		case Select_Timer4: TIMER_SELECTED = HUY_TIMER4; break;
		case Select_Timer5: TIMER_SELECTED = HUY_TIMER5; break;
	}
	TIMER_SELECTED->CR1.bit.CEN =0;
	TIMER_SELECTED->CR1.bit.APRE = Auto_reload_Preload;
	TIMER_SELECTED->CR1.bit.CMS = Aligned_Mode;
	TIMER_SELECTED->CR1.bit.DIR = Direction;
	TIMER_SELECTED->CR1.bit.CKD = Clock_Division;
}


void Configure_TIMER1_OutputChannel(uint8_t Output_Mode,uint8_t Channel,uint8_t Compare_polarity,uint8_t Compare_fast ,uint8_t Complementary, uint16_t Compare_Value,uint8_t Compare_Preload)
{
	HUY_RCC->APB2ENR.bit.AFIOEN =1;
	HUY_TIMER1->CCMR1.OutputCompare.CC1S = 0;
	if(Channel == CH1)
	{
		GPIO_MODE(GPIO_PORTA,8,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL);
		HUY_TIMER1->CCR1.Data = Compare_Value;
		HUY_TIMER1->CCMR1.OutputCompare.OC1M = Output_Mode;
		HUY_TIMER1->CCMR1.OutputCompare.OC1PE = Compare_Preload;
		HUY_TIMER1->CCMR1.OutputCompare.OC1FE = Compare_fast;
		HUY_TIMER1->CCER.bit.CC1P = Compare_polarity;
		HUY_TIMER1->CCER.bit.CC1E = 1;
		HUY_TIMER1->CCER.bit.CC1NP = Compare_polarity;
		HUY_TIMER1->CCER.bit.CC1NE = Complementary;
	}
	
	else if (Channel == CH2)
	{
		GPIO_MODE(GPIO_PORTA,9,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL);
		HUY_TIMER1->CCR2.Data = Compare_Value;
		HUY_TIMER1->CCMR1.OutputCompare.OC2M = Output_Mode;
		HUY_TIMER1->CCMR1.OutputCompare.OC2PE = Compare_Preload;
		HUY_TIMER1->CCMR1.OutputCompare.OC2FE = Compare_fast;
		HUY_TIMER1->CCER.bit.CC2P = Compare_polarity;
		HUY_TIMER1->CCER.bit.CC2E = 1;
		HUY_TIMER1->CCER.bit.CC2NP = Compare_polarity;
		HUY_TIMER1->CCER.bit.CC2NE = Complementary;
	}
	else if (Channel == CH3)
	{
		GPIO_MODE(GPIO_PORTA,10,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL);
		HUY_TIMER1->CCR3.Data = Compare_Value;
		HUY_TIMER1->CCMR2.OutputCompare.OC3M = Output_Mode;
		HUY_TIMER1->CCMR2.OutputCompare.OC3PE = Compare_Preload;
		HUY_TIMER1->CCMR2.OutputCompare.OC3FE = Compare_fast;
		HUY_TIMER1->CCER.bit.CC3P = Compare_polarity;
		HUY_TIMER1->CCER.bit.CC3E = 1;
		HUY_TIMER1->CCER.bit.CC3NP = Compare_polarity;
		HUY_TIMER1->CCER.bit.CC3NE = Complementary;
	}
	else
	{
		GPIO_MODE(GPIO_PORTA,11,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL);
		HUY_TIMER1->CCR4.Data = Compare_Value;
		HUY_TIMER1->CCMR2.OutputCompare.OC4M = Output_Mode;
		HUY_TIMER1->CCMR2.OutputCompare.OC4PE = Compare_Preload;
		HUY_TIMER1->CCMR2.OutputCompare.OC4FE = Compare_fast;
		HUY_TIMER1->CCER.bit.CC4P = Compare_polarity;
		HUY_TIMER1->CCER.bit.CC4E = 1;
	}
	HUY_TIMER1->BDTR.bit.MOE =1;
}


void Configure_TIMER2345_OutputChannel(uint8_t Select_Timer,uint8_t Output_Mode,uint8_t Channel,uint8_t Compare_polarity,uint8_t Compare_fast ,uint16_t Compare_Value,uint8_t Compare_Preload)
{
	HUY_TIMER2345_Struct * TIMER_SELECTED;
	HUY_RCC->APB2ENR.bit.AFIOEN =1;
	switch (Select_Timer)
	{
		default : TIMER_SELECTED = HUY_TIMER2; break;
		case Select_Timer3: TIMER_SELECTED = HUY_TIMER3; break;
		case Select_Timer4: TIMER_SELECTED = HUY_TIMER4; break;
		case Select_Timer5: TIMER_SELECTED = HUY_TIMER5; break;
	}
	if(Channel == CH1)
	{
		switch (Select_Timer)
		{
			default : GPIO_MODE(GPIO_PORTA,0,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL); break;
			case Select_Timer3: GPIO_MODE(GPIO_PORTA,6,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL); break;
			case Select_Timer4: GPIO_MODE(GPIO_PORTB,6,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL); break;
		}
		TIMER_SELECTED->CCR1.Data = Compare_Value;
		TIMER_SELECTED->CCMR1.OutputCompare.CC1S = 0;
		TIMER_SELECTED->CCMR1.OutputCompare.OC1M = Output_Mode;
		TIMER_SELECTED->CCMR1.OutputCompare.OC1PE = Compare_Preload;
		TIMER_SELECTED->CCMR1.OutputCompare.OC1FE = Compare_fast;
		TIMER_SELECTED->CCER.bit.CC1P = Compare_polarity;
		TIMER_SELECTED->CCER.bit.CC1E = 1;
	}
	
	else if (Channel == CH2)
	{
		switch (Select_Timer)
		{
			default : GPIO_MODE(GPIO_PORTA,1,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL); break;
			case Select_Timer3: GPIO_MODE(GPIO_PORTA,7,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL); break;
			case Select_Timer4: GPIO_MODE(GPIO_PORTB,7,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL); break;
		}
		TIMER_SELECTED->CCR2.Data = Compare_Value;
		TIMER_SELECTED->CCMR1.OutputCompare.CC2S = 0;
		TIMER_SELECTED->CCMR1.OutputCompare.OC2M = Output_Mode;
		TIMER_SELECTED->CCMR1.OutputCompare.OC2PE = Compare_Preload;
		TIMER_SELECTED->CCMR1.OutputCompare.OC2FE = Compare_fast;
		TIMER_SELECTED->CCER.bit.CC2P = Compare_polarity;
		TIMER_SELECTED->CCER.bit.CC2E = 1;
	}
	else if (Channel == CH3)
	{
		switch (Select_Timer)
		{
			default : GPIO_MODE(GPIO_PORTA,2,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL); break;
			case Select_Timer3: GPIO_MODE(GPIO_PORTB,0,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL); break;
			case Select_Timer4: GPIO_MODE(GPIO_PORTB,8,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL); break;
		}
		TIMER_SELECTED->CCR3.Data = Compare_Value;
		TIMER_SELECTED->CCMR2.OutputCompare.CC3S = 0;
		TIMER_SELECTED->CCMR2.OutputCompare.OC3M = Output_Mode;
		TIMER_SELECTED->CCMR2.OutputCompare.OC3PE = Compare_Preload;
		TIMER_SELECTED->CCMR2.OutputCompare.OC3FE = Compare_fast;
		TIMER_SELECTED->CCER.bit.CC3P = Compare_polarity;
		TIMER_SELECTED->CCER.bit.CC3E = 1;
	}
	else
	{
		switch (Select_Timer)
		{
			default : GPIO_MODE(GPIO_PORTA,3,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL); break;
			case Select_Timer3: GPIO_MODE(GPIO_PORTB,1,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL); break;
			case Select_Timer4: GPIO_MODE(GPIO_PORTB,9,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL); break;
			case Select_Timer5: GPIO_MODE(GPIO_PORTA,3,OUTPUT_50MHZ,OP_ALTERNATE_PUSH_PULL); break;
		}
		TIMER_SELECTED->CCR4.Data = Compare_Value;
		TIMER_SELECTED->CCMR2.OutputCompare.CC4S = 0;
		TIMER_SELECTED->CCMR2.OutputCompare.OC4M = Output_Mode;
		TIMER_SELECTED->CCMR2.OutputCompare.OC4PE = Compare_Preload;
		TIMER_SELECTED->CCMR2.OutputCompare.OC4FE = Compare_fast;
		TIMER_SELECTED->CCER.bit.CC4P = Compare_polarity;
		TIMER_SELECTED->CCER.bit.CC4E = 1;
	}
}


void Configure_TIMER1_Counter(uint16_t Auto_reload_value, uint16_t Prescaler_value, uint16_t Counter_value)
{
	HUY_TIMER1->ARR.Data = Auto_reload_value;
	HUY_TIMER1->PSC.Data = Prescaler_value;
	HUY_TIMER1->CNT.Data = Counter_value;
	if(HUY_TIMER1->CR1.bit.APRE == 1)
	{
		HUY_TIMER1->EGR.bit.UG =1;
	}
}

void Configure_TIMER2345_Counter(uint8_t Select_Timer,uint16_t Auto_reload_value, uint16_t Prescaler_value, uint16_t Counter_value)
{
	HUY_TIMER2345_Struct * TIMER_SELECTED;
	switch (Select_Timer)
	{
		default : TIMER_SELECTED = HUY_TIMER2; break;
		case Select_Timer3: TIMER_SELECTED = HUY_TIMER3; break;
		case Select_Timer4: TIMER_SELECTED = HUY_TIMER4; break;
		case Select_Timer5: TIMER_SELECTED = HUY_TIMER5; break;
	}
	TIMER_SELECTED->ARR.Data = Auto_reload_value;
	TIMER_SELECTED->PSC.Data = Prescaler_value;
	TIMER_SELECTED->CNT.Data = Counter_value;
	if(HUY_TIMER1->CR1.bit.APRE == 1)
	{
		TIMER_SELECTED->EGR.bit.UG =1;
	}
}

void Configure_TIMER1_InputCapture(uint8_t Input_Mode, uint8_t Trigger_Input,uint8_t Channel,uint8_t Input_Source, uint8_t InputCapture_Prescaler,uint8_t InputCapture_Filter)
{
	HUY_TIMER1->SMCR.bit.SMS = Input_Mode;
	if(Input_Mode != TIM1_Normal_Mode)
	{
		HUY_TIMER1->SMCR.bit.TS = Trigger_Input;
	}
	if(Channel == CH1)
	{
		HUY_TIMER1->CCMR1.InputCapture.CC1S = Input_Source;
		HUY_TIMER1->CCMR1.InputCapture.IC1PSC = InputCapture_Prescaler;
		HUY_TIMER1->CCMR1.InputCapture.IC1F = InputCapture_Filter;
		HUY_TIMER1->CCER.bit.CC1E = 1;
	}
	else if(Channel == CH2)
	{
		HUY_TIMER1->CCMR1.InputCapture.CC2S = Input_Source;
		HUY_TIMER1->CCMR1.InputCapture.IC2PSC = InputCapture_Prescaler;
		HUY_TIMER1->CCMR1.InputCapture.IC2F = InputCapture_Filter;
		HUY_TIMER1->CCER.bit.CC2E = 1;
	}
	else if(Channel == CH3)
	{
		HUY_TIMER1->CCMR2.InputCapture.CC3S = Input_Source;
		HUY_TIMER1->CCMR2.InputCapture.IC3PSC = InputCapture_Prescaler;
		HUY_TIMER1->CCMR2.InputCapture.IC3F = InputCapture_Filter;
		HUY_TIMER1->CCER.bit.CC3E = 1;
	}
	else
	{
		HUY_TIMER1->CCMR2.InputCapture.CC4S = Input_Source;
		HUY_TIMER1->CCMR2.InputCapture.IC4PSC = InputCapture_Prescaler;
		HUY_TIMER1->CCMR2.InputCapture.IC4F = InputCapture_Filter;
		HUY_TIMER1->CCER.bit.CC4E = 1;
	}
}

void Configure_TIMER1_InputCapture_Edge(uint8_t Channel,uint8_t Edge)
{
	switch(Channel)
	{
		default : HUY_TIMER1->CCER.bit.CC1P = Edge; break;
		case CH2: HUY_TIMER1->CCER.bit.CC2P = Edge; break;
		case CH3: HUY_TIMER1->CCER.bit.CC3P = Edge; break;
		case CH4: HUY_TIMER1->CCER.bit.CC4P = Edge; break;
		
	}
		
}
	

void TIMER_Start_Count(uint8_t Select_Timer)
{
	switch(Select_Timer)
	{
		default : HUY_TIMER1->CR1.bit.CEN =1; break;
		case Select_Timer2 : HUY_TIMER2->CR1.bit.CEN=1; break;
		case Select_Timer3 : HUY_TIMER3->CR1.bit.CEN=1; break;
		case Select_Timer4 : HUY_TIMER4->CR1.bit.CEN=1; break;
		case Select_Timer5 : HUY_TIMER5->CR1.bit.CEN=1; break;
	}
}


