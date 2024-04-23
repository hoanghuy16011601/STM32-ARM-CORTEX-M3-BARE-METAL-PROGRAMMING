#ifndef __HUY_TIMER1_DRIVE_H
#define __HUY_TIMER1_DRIVE_H
#include "stdint.h"



////Bit-field Configure TIMER
#define Select_Timer1 0xff //(ONLY FOR START COUNT)
//Select Timer (Configure Timer2345)
#define Select_Timer2 0
#define Select_Timer3 1
#define Select_Timer4 2
#define Select_Timer5 3
//Auto-reload-Preload
#define TIMER_Auto_reload_Preload_Disable 0
#define TIMER_Auto_reload_Preload_Enable 1
//Timer Aligned Mode
#define TIMER_Edge_Aligned 0
#define TIMER_Center_Aligned_1 1
#define TIMER_Center_Aligned_2 2
#define TIMER_Center_Aligned_3 3
//Direction
#define TIMER_Upcounter 0
#define TIMER_Downcounter 1
// Clock Division
#define TIMER_tDTS_tCKin 0
#define TIMER_tDTS_2tCKin 1
#define TIMER_tDTS_4tCKin 2



//// Bit-field Configure TIMER1 OUTPUT-MODE
//Channel
#define CH1 1  
#define CH2 2
#define CH3 3
#define CH4 4
// Compare-Fast-Enable
#define TIMER_OC5REF 0
#define TIMER_OC1REF 1
// Compare-preload
#define TIMER_Compare_Preload_Disable 0
#define TIMER_Compare_Preload_Enable 1
// Compare-Mode
#define TIMER_Compare_Active_Mode 1
#define TIMER_Compare_InActive_Mode 2 
#define TIMER_Compare_Toggle_Mode 3
#define TIMER_Force_InActive_Mode 4
#define TIMER_Force_Active_Mode 5
#define TIMER_PWM1_MODE 6
#define TIMER_PWM2_MODE 7
// Output-Polarity
#define TIMER_Active_High 0
#define TIMER_Active_LOW 1
// Complementary-Mode
#define TIMER_Single_Channel 0
#define TIMER_Complementary_Channel 1


//// Bit-field Configure TIMER1 INPUT CAPTURE MODE
//Input Capture Mode
#define TIM1_Normal_Mode 0
#define TIM1_Encoder_Mode1 1 
#define TIM1_Encoder_Mode2 2 
#define TIM1_Encoder_Mode3 3 
#define TIM1_Reset_Mode 4 
#define TIM1_Gated_Mode 5
#define TIM1_Trigger_Mode 6
#define TIM1_External_Clock_Mode 7 
//Input Trigger
#define TIM1_ITR0_Input 0
#define TIM1_ITR1_Input 1
#define TIM1_ITR2_Input 2
#define TIM1_ITR3_Input 3
#define TIM1_TI1F_ED_Input 4
#define TIM1_TI1FP1_Input 5
#define TIM1_TI2FP2_Input 6
#define TIM1_ETRF_Input 7
//Input Source
#define TIM1_ICx_Select_TIx 1
#define TIM1_ICx_Select_TIy 2
#define TIM1_ICx_Select_TRC 3
///Input Capture Prescaler
#define TIM1_Prescaler1 0
#define TIM1_Prescaler2 1
#define TIM1_Prescaler4 2
#define TIM1_Prescaler8 3
//Input Capture Filter
#define TIM1_No_Filter 0
#define TIM1_SAMPLING_DTS_N2 1
#define TIM1_SAMPLING_DTS_N4 2
#define TIM1_SAMPLING_DTS_N8 3
#define TIM1_SAMPLING_DTS_Divided2_N6 4 
#define TIM1_SAMPLING_DTS_Divided2_N8 5
#define TIM1_SAMPLING_DTS_Divided4_N6 6
#define TIM1_SAMPLING_DTS_Divided4_N8 7 
#define TIM1_SAMPLING_DTS_Divided8_N6 8 
#define TIM1_SAMPLING_DTS_Divided8_N8 9
#define TIM1_SAMPLING_DTS_Divided16_N5 10 
#define TIM1_SAMPLING_DTS_Divided16_N6 11
#define TIM1_SAMPLING_DTS_Divided16_N8 12
#define TIM1_SAMPLING_DTS_Divided32_N5 13
#define TIM1_SAMPLING_DTS_Divided32_N6 14
#define TIM1_SAMPLING_DTS_Divided32_N8 15
/// Input Capture Edge 
#define TIM1_Rising 0
#define TIM1_Falling 1


void Configure_TIMER1(uint8_t Auto_reload_Preload, uint8_t Aligned_Mode,uint8_t Direction,uint8_t Clock_Division);
void Configure_TIMER2345(uint8_t Select_Timer,uint8_t Auto_reload_Preload, uint8_t Aligned_Mode,uint8_t Direction,uint8_t Clock_Division);
void Configure_TIMER1_OutputChannel(uint8_t Output_Mode,uint8_t Channel,uint8_t Compare_polarity,uint8_t Compare_fast ,uint8_t Complementary,
	uint16_t Compare_Value,uint8_t Compare_Preload);
void Configure_TIMER2345_OutputChannel(uint8_t Select_Timer,uint8_t Output_Mode,uint8_t Channel,uint8_t Compare_polarity,uint8_t Compare_fast ,
	uint16_t Compare_Value,uint8_t Compare_Preload);
void Configure_TIMER1_InputCapture(uint8_t Input_Mode, uint8_t Trigger_Input,uint8_t Channel,uint8_t Input_Source, uint8_t InputCapture_Prescaler,uint8_t InputCapture_Filter);
void Configure_TIMER1_Counter(uint16_t Auto_reload_value, uint16_t Prescaler_value, uint16_t Counter_value);
void Configure_TIMER2345_Counter(uint8_t Select_Timer,uint16_t Auto_reload_value, uint16_t Prescaler_value, uint16_t Counter_value);
void Configure_TIMER1_InputCapture_Edge(uint8_t Channel,uint8_t Edge);
void TIMER_Start_Count(uint8_t Select_Timer);
	
#endif



