#include "stdint.h"

#ifndef RCC_H
#define RCC_H
// CLOCK
typedef struct{
	volatile uint32_t HSION:1;
	volatile uint32_t HSIRDY:1;
	volatile uint32_t Reserved:1;
	volatile uint32_t HSITRIM:5;
	volatile uint32_t HSCIAL:8;
	volatile uint32_t HSEON:1;
	volatile uint32_t HSERDY:1;
	volatile uint32_t HSEBYP:1;
	volatile uint32_t CSSON:1;
	volatile uint32_t Reserved2:4;
	volatile uint32_t PLLON:1;
	volatile uint32_t PLLRDY:1;
	volatile uint32_t Reserved3:6;
}CR_Struct;

typedef union{
	uint32_t reg;
	CR_Struct bit;
}CR_Union;

typedef struct{
	volatile uint32_t SW:2;
	volatile uint32_t SWS:2;
	volatile uint32_t HPRE:4;
	volatile uint32_t PPRE1:3;
	volatile uint32_t PPRE2:3;
	volatile uint32_t ADCPRE:2;
	volatile uint32_t PLLSRC:1;
	volatile uint32_t PLLXTPRE:1;
	volatile uint32_t PLLMUL:4;
	volatile uint32_t USBPRE:1;
	volatile uint32_t Reserved:1;
	volatile uint32_t MCO:3;
	volatile uint32_t Reserved3:5;
}CFGR_Struct;

typedef union{
	uint32_t reg;
	CFGR_Struct bit;
}CFGR_Union;


typedef struct{
	volatile uint32_t LSIRDYF:1;
	volatile uint32_t LSERDYF:1;
	volatile uint32_t HSIRDYF:1;
	volatile uint32_t HSERDYF:1;
	volatile uint32_t PLLRDYF:1;
	volatile uint32_t Reserved:2;
	volatile uint32_t CSSF:1;
	volatile uint32_t LSIRDYE:1;
	volatile uint32_t LSERDYE:1;
	volatile uint32_t HSIRDYE:1;
	volatile uint32_t HSERDYE:1;
	volatile uint32_t PLLRDYE:1;
	volatile uint32_t Reserved2:3;
	volatile uint32_t LSIRDYC:1;
	volatile uint32_t LSERDYC:1;
	volatile uint32_t HSIRDYC:1;
	volatile uint32_t HSERDYC:1;
	volatile uint32_t PLLRDYC:1;
	volatile uint32_t Reserved3:2;
	volatile uint32_t CSSC:1;
	volatile uint32_t Reserved4:8;
}CIR_Struct;

typedef union{
	uint32_t reg;
	CR_Struct bit;
}CIR_Union;

typedef struct{
	volatile uint32_t AFIOEN:1;
	volatile uint32_t Reserved:1;
	volatile uint32_t IOPAEN:1;
	volatile uint32_t IOPBEN:1;
	volatile uint32_t IOPCEN:1;
	volatile uint32_t IOPDEN:1;
	volatile uint32_t IOPEEN:1;
	volatile uint32_t Reserved2:2;
	volatile uint32_t ADC1EN:1;
	volatile uint32_t ADC2EN:1;
	volatile uint32_t TIM1EN:1;
	volatile uint32_t SPI1EN:1;
	volatile uint32_t Reserved3:1;
	volatile uint32_t USART1EN:1;
	volatile uint32_t Reserved4:17;
}APB2ENR_Struct;

typedef union{
	uint32_t reg;
	APB2ENR_Struct bit;
}APB2ENR_Union;

typedef struct{
	volatile uint32_t TIM2EN:1;
	volatile uint32_t TIM3EN:1;
	volatile uint32_t TIM4EN:1;
	volatile uint32_t TIM5EN:1;
	volatile uint32_t TIM6EN:1;
	volatile uint32_t TIM7EN:1;
	volatile uint32_t Reserved:5;
	volatile uint32_t WWDGEN:1;
	volatile uint32_t Reserved2:2;
	volatile uint32_t SPI2EN:1;
	volatile uint32_t SPI3EN:1;
	volatile uint32_t Reserved3:1;
	volatile uint32_t USART2EN:1;
	volatile uint32_t USART3EN:1;
	volatile uint32_t UART4EN:1;
	volatile uint32_t UART5EN:1;
	volatile uint32_t I2C1EN:1;
	volatile uint32_t I2C2EN:1;
	volatile uint32_t Reserved4:2;
	volatile uint32_t CAN1EN:1;
	volatile uint32_t CAN2EN:1;
	volatile uint32_t BKPEN:1;
	volatile uint32_t PWREN:1;
	volatile uint32_t DACEN:1;
	volatile uint32_t Reserved5:2;
}APB1ENR_Struct;

typedef union{
	uint32_t reg;
	APB1ENR_Struct bit;
}APB1ENR_Union;

typedef struct{
	volatile uint32_t LSEON:1;
	volatile uint32_t LSERDY:1;
	volatile uint32_t LSEBYP:1;
	volatile uint32_t Reserved:5;
	volatile uint32_t RTCSEL:2;
	volatile uint32_t Reserved2:5;
	volatile uint32_t RTCEN:1;
	volatile uint32_t BDRST:1;
	volatile uint32_t Reserved3:15;
}BDCR_Struct;

typedef union{
	uint32_t reg;
	BDCR_Struct bit;
}BDCR_Union;

typedef struct{
	volatile uint32_t LSION:1;
	volatile uint32_t LSIRDY:1;
	volatile uint32_t Reserved:24;
	volatile uint32_t RMVF:1;
	volatile uint32_t Reserved2:1;
	volatile uint32_t PINRSTF:1;
	volatile uint32_t PORRSTF:1;
	volatile uint32_t SFTRSTF:1;
	volatile uint32_t IWDGRSTF:1;
	volatile uint32_t WWDGRSTF:1;
	volatile uint32_t LPWRRSTF:1;
}CSR_Struct;

typedef union{
	uint32_t reg;
	BDCR_Struct bit;
}CSR_Union;


typedef struct{
	CR_Union CR;
	CFGR_Union CFGR;
	CIR_Union CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	APB2ENR_Union APB2ENR;
	APB1ENR_Union APB1ENR;
	BDCR_Union BDCR;
	CSR_Union CSR;
}HUY_RCC_Struct;

#define HUY_RCC ((HUY_RCC_Struct *)0x40021000)
#endif


#ifndef GPIO_H
#define GPIO_H

typedef struct{
	volatile uint32_t MODE0:2;
	volatile uint32_t CNF0:2;
	volatile uint32_t MODE1:2;
	volatile uint32_t CNF1:2;
	volatile uint32_t MODE2:2;
	volatile uint32_t CNF2:2;
	volatile uint32_t MODE3:2;
	volatile uint32_t CNF3:2;
	volatile uint32_t MODE4:2;
	volatile uint32_t CNF4:2;
	volatile uint32_t MODE5:2;
	volatile uint32_t CNF5:2;
	volatile uint32_t MODE6:2;
	volatile uint32_t CNF6:2;
	volatile uint32_t MODE7:2;
	volatile uint32_t CNF7:2;
}CRL_Struct;

typedef union {
	uint32_t reg;
	CRL_Struct bit;
}CRL_Union;


typedef struct{
	volatile uint32_t MODE8:2;
	volatile uint32_t CNF8:2;
	volatile uint32_t MODE9:2;
	volatile uint32_t CNF9:2;
	volatile uint32_t MODE10:2;
	volatile uint32_t CNF10:2;
	volatile uint32_t MODE11:2;
	volatile uint32_t CNF11:2;
	volatile uint32_t MODE12:2;
	volatile uint32_t CNF12:2;
	volatile uint32_t MODE13:2;
	volatile uint32_t CNF13:2;
	volatile uint32_t MODE14:2;
	volatile uint32_t CNF14:2;
	volatile uint32_t MODE15:2;
	volatile uint32_t CNF15:2;
}CRH_Struct;

typedef union {
	uint32_t reg;
	CRH_Struct bit;
}CRH_Union;

typedef union{
	uint16_t Data;
	uint32_t reg;
}IDR_Union;

typedef union{
	uint16_t Data;
	uint32_t reg;
}ODR_Union;

typedef struct{
	volatile uint32_t BS0:1;
	volatile uint32_t BS1:1;
	volatile uint32_t BS2:1;
	volatile uint32_t BS3:1;
	volatile uint32_t BS4:1;
	volatile uint32_t BS5:1;
	volatile uint32_t BS6:1;
	volatile uint32_t BS7:1;
	volatile uint32_t BS8:1;
	volatile uint32_t BS9:1;
	volatile uint32_t BS10:1;
	volatile uint32_t BS11:1;
	volatile uint32_t BS12:1;
	volatile uint32_t BS13:1;
	volatile uint32_t BS14:1;
	volatile uint32_t BS15:1;
	volatile uint32_t BR0:1;
	volatile uint32_t BR1:1;
	volatile uint32_t BR2:1;
	volatile uint32_t BR3:1;
	volatile uint32_t BR4:1;
	volatile uint32_t BR5:1;
	volatile uint32_t BR6:1;
	volatile uint32_t BR7:1;
	volatile uint32_t BR8:1;
	volatile uint32_t BR9:1;
	volatile uint32_t BR10:1;
	volatile uint32_t BR11:1;
	volatile uint32_t BR12:1;
	volatile uint32_t BR13:1;
	volatile uint32_t BR14:1;
	volatile uint32_t BR15:1;
}BSRR_Struct;

typedef union {
	uint32_t reg;
	BSRR_Struct bit;
}BSRR_Union;

typedef struct{
	volatile uint32_t BR0:1;
	volatile uint32_t BR1:1;
	volatile uint32_t BR2:1;
	volatile uint32_t BR3:1;
	volatile uint32_t BR4:1;
	volatile uint32_t BR5:1;
	volatile uint32_t BR6:1;
	volatile uint32_t BR7:1;
	volatile uint32_t BR8:1;
	volatile uint32_t BR9:1;
	volatile uint32_t BR10:1;
	volatile uint32_t BR11:1;
	volatile uint32_t BR12:1;
	volatile uint32_t BR13:1;
	volatile uint32_t BR14:1;
	volatile uint32_t BR15:1;
	volatile uint32_t Reserved:16;
}BRR_Struct;

typedef union {
	uint32_t reg;
	BRR_Struct bit;
}BRR_Union;


typedef struct{
	volatile uint32_t LCK0:1;
	volatile uint32_t LCK1:1;
	volatile uint32_t LCK2:1;
	volatile uint32_t LCK3:1;
	volatile uint32_t LCK4:1;
	volatile uint32_t LCK5:1;
	volatile uint32_t LCK6:1;
	volatile uint32_t LCK7:1;
	volatile uint32_t LCK8:1;
	volatile uint32_t LCK9:1;
	volatile uint32_t LCK10:1;
	volatile uint32_t LCK11:1;
	volatile uint32_t LCK12:1;
	volatile uint32_t LCK13:1;
	volatile uint32_t LCK14:1;
	volatile uint32_t LCK15:1;
	volatile uint32_t LCKK:1;
	volatile uint32_t Reserved:15;
}LCKR_Struct;

typedef union {
	uint32_t reg;
	LCKR_Struct bit;
}LCKR_Union;

typedef struct{
	CRL_Union CRL;
	CRH_Union CRH;
	IDR_Union IDR;
	ODR_Union ODR;
	BSRR_Union BSRR;
	BRR_Union BRR;
	LCKR_Union LCKR;
}HUY_GPIO_Struct;

#define HUY_GPIO_PORTA ((HUY_GPIO_Struct *)0x40010800)
#define HUY_GPIO_PORTB ((HUY_GPIO_Struct *)0x40010C00)
#define HUY_GPIO_PORTC ((HUY_GPIO_Struct *)0x40011000)

#endif


#ifndef STK_H
#define STK_H
// Systick
typedef struct{
	volatile uint32_t ENABLE:1;
	volatile uint32_t TICKINT:1;
	volatile uint32_t CLKSOURCE:1;
	volatile uint32_t Reserved:13;
	volatile uint32_t COUNTFLAG:1;
	volatile uint32_t Reserved2:15;
}STK_CTRL_Struct;

typedef union{
	uint32_t reg;
	STK_CTRL_Struct bit;
}STK_CTRL_Union;

//
typedef struct{
	volatile uint32_t RELOAD:24;
	volatile uint32_t Reserved:8;
}STK_LOAD_Struct;

typedef union{
	uint32_t reg;
	STK_LOAD_Struct bit;
}STK_LOAD_Union;

//
typedef struct{
	volatile uint32_t CURRENT:24;
	volatile uint32_t Reserved:8;
}STK_VAL_Struct;

typedef union{
	uint32_t reg;
	STK_VAL_Struct bit;
}STK_VAL_Union;

//
typedef struct{
	volatile uint32_t TENMS:24;
	volatile uint32_t Reserved:6;
	volatile uint32_t SKEW:1;
	volatile uint32_t NOREF:1;
}STK_CALIB_Struct;

typedef union{
	uint32_t reg;
	STK_CALIB_Struct bit;
}STK_CALIB_Union;

//
typedef struct{
	STK_CTRL_Union CTRL;
	STK_LOAD_Union LOAD;
	STK_VAL_Union VAL;
	STK_CALIB_Union CALIB;
}HUY_STK_Struct;


#define HUY_Systick ((HUY_STK_Struct *)0xE000E010)
#endif


#ifndef SPI_H_LIB
#define SPI_H_LIB
/////SPI

typedef struct{
	volatile uint32_t CPHA:1;
	volatile uint32_t CPOL:1;
	volatile uint32_t MSTR:1;
	volatile uint32_t BR:3;
	volatile uint32_t SPE:1;
	volatile uint32_t LSBFIRST:1;
	volatile uint32_t SSI:1;
	volatile uint32_t SSM:1;
	volatile uint32_t RXONLY:1;
	volatile uint32_t DFF:1;
	volatile uint32_t CRCNEXT:1;
	volatile uint32_t CRCEN:1;
	volatile uint32_t BIDIOE:1;
	volatile uint32_t BIDIMODE:1;
	volatile uint32_t Reserved:16;
}SPI_CR1_Struct;

typedef union{
	uint32_t reg;
	SPI_CR1_Struct bit;
}SPI_CR1_Union;


typedef struct{
	volatile uint32_t RXDMAEN:1;
	volatile uint32_t TXDMAEN:1;
	volatile uint32_t SSOE:1;
	volatile uint32_t Reserved:2;
	volatile uint32_t ERRIE:1;
	volatile uint32_t RXNEIE:1;
	volatile uint32_t TXEIE:1;
	volatile uint32_t Reserved2:24;
}SPI_CR2_Struct;

typedef union{
	uint32_t reg;
	SPI_CR2_Struct bit;
}SPI_CR2_Union;


typedef struct{
	volatile uint32_t RXNE:1;
	volatile uint32_t TXE:1;
	volatile uint32_t CHSIDE:1;
	volatile uint32_t UDR:1;
	volatile uint32_t CRCERR:1;
	volatile uint32_t MODF:1;
	volatile uint32_t OVR:1;
	volatile uint32_t BSY:1;
	volatile uint32_t Reserved:24;
}SPI_SR_Struct;

typedef union{
	uint32_t reg;
	SPI_SR_Struct bit;
}SPI_SR_Union;

typedef struct{
	volatile uint32_t CHLEN:1;
	volatile uint32_t DATLEN:2;
	volatile uint32_t CKPOL:1;
	volatile uint32_t I2SSTD:2;
	volatile uint32_t Reserved:1;
	volatile uint32_t PCMSYNC:1;
	volatile uint32_t I2SCFG:2;
	volatile uint32_t I2SE:1;
	volatile uint32_t I2SMOD:1;
	volatile uint32_t Reserved2:20;
}SPI_I2SCFGR_Struct;

typedef union{
	uint32_t reg;
	SPI_I2SCFGR_Struct bit;
}SPI_I2SCFGR_Union;


typedef struct{
	volatile uint32_t I2SDIV:8;
	volatile uint32_t ODD:1;
	volatile uint32_t MCKOE:1;
	volatile uint32_t Reserved2:22;
}SPI_I2SPR_Struct;

typedef union{
	uint32_t reg;
	SPI_I2SPR_Struct bit;
}SPI_I2SPR_Union;


typedef struct{
	SPI_CR1_Union CR1;
	SPI_CR2_Union CR2;
	SPI_SR_Union SR;
	uint32_t DR;
	uint32_t CRCPR;
	uint32_t RXCRCR;
	uint32_t TXCRCR;
	SPI_I2SCFGR_Union I2SCFGR;
	SPI_I2SPR_Union I2SPR;
}HUY_SPI_Struct;

#define HUY_SPI1 ((HUY_SPI_Struct *)0x40013000)
#define HUY_SPI2_I2S ((HUY_SPI_Struct *)0x40003800)
#define HUY_SPI3_I2S ((HUY_SPI_Struct *)0x40003C00)

#endif


#ifndef I2C_H_LIB
#define I2C_H_LIB

typedef struct{
	volatile uint16_t PE:1;
	volatile uint16_t SMBUS:1;
	volatile uint16_t Reserved:1;
	volatile uint16_t SMBTYPE:1;
	volatile uint16_t ENARP:1;
	volatile uint16_t ENPEC:1;
	volatile uint16_t ENGC:1;
	volatile uint16_t NOSTRETCH:1;
	volatile uint16_t START:1;
	volatile uint16_t STOP:1;
	volatile uint16_t ACK:1;
	volatile uint16_t POS:1;
	volatile uint16_t PEC:1;
	volatile uint16_t ALERT:1;
	volatile uint16_t Reserved2:1;
	volatile uint16_t SWRST:1;
}I2C_CR1_Struct;

typedef union{
	I2C_CR1_Struct bit;
	uint32_t reg;
}I2C_CR1_Union;

//
typedef struct{
	volatile uint16_t FREQ:6;
	volatile uint16_t Reserved:2;
	volatile uint16_t ITERREN:1;
	volatile uint16_t ITEVTEN:1;
	volatile uint16_t ITBUFEN:1;
	volatile uint16_t DMAEN:1;
	volatile uint16_t LAST:1;
	volatile uint16_t Reserved2:3;
}I2C_CR2_Struct;

typedef union{
	I2C_CR2_Struct bit;
	uint32_t reg;
}I2C_CR2_Union;

//
typedef struct{
	volatile uint16_t ADD0:1;
	volatile uint16_t ADD1:7;
	volatile uint16_t ADD2:2;
	volatile uint16_t Reserved2:5;
	volatile uint16_t ADDMODE:1;
}I2C_OAR1_Struct;

typedef union{
	I2C_OAR1_Struct bit;
	uint32_t reg;
}I2C_OAR1_Union;

//
typedef struct{
	volatile uint16_t ENDUAL:1;
	volatile uint16_t ADD:7;
	volatile uint16_t Reserved:8;
}I2C_OAR2_Struct;

typedef union{
	I2C_OAR2_Struct bit;
	uint32_t reg;
}I2C_OAR2_Union;

//
typedef struct{
	unsigned char DATA;
	unsigned char Reserved;
}I2C_DR_Struct;

typedef union{
	I2C_DR_Struct bit;
	uint32_t reg;
}I2C_DR_Union;

//
typedef struct{
	volatile uint16_t SB:1;
	volatile uint16_t ADDR:1;
	volatile uint16_t BTF:1;
	volatile uint16_t ADD10:1;
	volatile uint16_t STOPF:1;
	volatile uint16_t Reserved:1;
	volatile uint16_t RXNE:1;
	volatile uint16_t TXE:1;
	volatile uint16_t BERR:1;
	volatile uint16_t ARLO:1;
	volatile uint16_t AF:1;
	volatile uint16_t OVR:1;
	volatile uint16_t PECERR:1;
	volatile uint16_t Reserved2:1;
	volatile uint16_t TIMEOUT:1;
	volatile uint16_t SMBALERT:1;
}I2C_SR1_Struct;

typedef union{
	I2C_SR1_Struct bit;
	uint32_t reg;
}I2C_SR1_Union;

//
typedef struct{
	volatile uint16_t MSL:1;
	volatile uint16_t BUSY:1;
	volatile uint16_t TRA:1;
	volatile uint16_t Reserved:1;
	volatile uint16_t GENCALL:1;
	volatile uint16_t SMBDEFAULT:1;
	volatile uint16_t SMBHOST:1;
	volatile uint16_t DUALF:1;
	volatile uint16_t PEC:8;
}I2C_SR2_Struct;

typedef union{
	I2C_SR2_Struct bit;
	uint32_t reg;
}I2C_SR2_Union;

//
typedef struct{
	volatile uint16_t CCR:12;
	volatile uint16_t Reserved:2;
	volatile uint16_t DUTY:1;
	volatile uint16_t F_S:1;
}I2C_CCR_Struct;

typedef union{
	I2C_CCR_Struct bit;
	uint32_t reg;
}I2C_CCR_Union;

//
typedef struct{
	volatile uint16_t TRISE:6;
	volatile uint16_t Reserved:10;
}I2C_TRISE_Struct;

typedef union{
	I2C_TRISE_Struct bit;
	uint32_t reg;
}I2C_TRISE_Union;


typedef struct{
	I2C_CR1_Union CR1;
	I2C_CR2_Union CR2;
	I2C_OAR1_Union OAR1;
	I2C_OAR2_Union OAR2;
	I2C_DR_Union DR;
	I2C_SR1_Union SR1;
	I2C_SR2_Union SR2;
	I2C_CCR_Union CCR;
	I2C_TRISE_Union TRISE;
}HUY_I2C_Struct;


#define HUY_I2C1 ((HUY_I2C_Struct *)0x40005400)
#define HUY_I2C2 ((HUY_I2C_Struct *)0x40005800)

#endif


#ifndef USART_H
#define USART_H
//// USART

typedef struct{
	volatile uint32_t PE:1;
	volatile uint32_t FE:1;
	volatile uint32_t NE:1;
	volatile uint32_t ORE:1;
	volatile uint32_t IDLE:1;
	volatile uint32_t RXNE:1;
	volatile uint32_t TC:1;
	volatile uint32_t TXE:1;
	volatile uint32_t LBD:1;
	volatile uint32_t CTS:1;
	volatile uint32_t Reserved:22;
}USART_SR_Struct;

typedef union{
	uint32_t reg;
	USART_SR_Struct bit;
}USART_SR_Union;

//

typedef struct{
	volatile uint32_t DR:9;
	volatile uint32_t Reserved:23;
}USART_DR_Struct;

typedef union{
	uint32_t reg;
	USART_DR_Struct bit;
}USART_DR_Union;


//
typedef struct{
	volatile uint32_t DIV_Fraction:4;
	volatile uint32_t DIV_Mantissa:12;
	volatile uint32_t Reserved:16;
}USART_BRR_Struct;

typedef union{
	uint32_t reg;
	USART_BRR_Struct bit;
}USART_BRR_Union;

//

typedef struct{
	volatile uint32_t SBK:1;
	volatile uint32_t RWU:1;
	volatile uint32_t RE:1;
	volatile uint32_t TE:1;
	volatile uint32_t IDLEIE:1;
	volatile uint32_t RXNEIE:1;
	volatile uint32_t TCIE:1;
	volatile uint32_t TXEIE:1;
	volatile uint32_t PEIE:1;
	volatile uint32_t PS:1;
	volatile uint32_t PCE:1;
	volatile uint32_t WAKE:1;
	volatile uint32_t M:1;
	volatile uint32_t UE:1;
	volatile uint32_t Reserved:18;
}USART_CR1_Struct;

typedef union{
	uint32_t reg;
	USART_CR1_Struct bit;
}USART_CR1_Union;


//
typedef struct{
	volatile uint32_t ADD:4;
	volatile uint32_t Reserved:1;
	volatile uint32_t LBDL:1;
	volatile uint32_t LBDIE:1;
	volatile uint32_t Reserved2:1;
	volatile uint32_t LBCL:1;
	volatile uint32_t CBHA:1;
	volatile uint32_t CPOL:1;
	volatile uint32_t CLKEN:1;
	volatile uint32_t STOP:2;
	volatile uint32_t RLINEN:1;
	volatile uint32_t Reserved3:17;
}USART_CR2_Struct;

typedef union{
	uint32_t reg;
	USART_CR2_Struct bit;
}USART_CR2_Union;


//
typedef struct{
	volatile uint32_t EIE:1;
	volatile uint32_t IREN:1;
	volatile uint32_t IRLP:1;
	volatile uint32_t HDSEL:1;
	volatile uint32_t NACK:1;
	volatile uint32_t SCEN:1;
	volatile uint32_t DMAR:1;
	volatile uint32_t DMAT:1;
	volatile uint32_t RTSE:1;
	volatile uint32_t CTSE:1;
	volatile uint32_t CTSEI:1;
	volatile uint32_t Reserved:21;
}USART_CR3_Struct;

typedef union{
	uint32_t reg;
	USART_CR3_Struct bit;
}USART_CR3_Union;

//
typedef struct{
	volatile uint32_t PSC:8;
	volatile uint32_t GT:8;
	volatile uint32_t Reserved:16;
}USART_GTPR_Struct;

typedef union{
	uint32_t reg;
	USART_GTPR_Struct bit;
}USART_GTPR_Union;

//
typedef struct{
	USART_SR_Union SR;
	USART_DR_Union DR;
	USART_BRR_Union BRR;
	USART_CR1_Union CR1;
	USART_CR2_Union CR2;
	USART_CR3_Union CR3;
	USART_GTPR_Union GTPR;
}HUY_USART_Struct;


#define HUY_USART1 ((HUY_USART_Struct *)0x40013800)
#define HUY_USART2 ((HUY_USART_Struct *)0x40004400)
#define HUY_USART3 ((HUY_USART_Struct *)0x40004800)
#define HUY_UART4  ((HUY_USART_Struct *)0x40004C00)
#define HUY_UART5  ((HUY_USART_Struct *)0x40005000)
////

#endif


#ifndef TIMER_H
#define TIMER_H

typedef struct{
	volatile uint32_t CEN:1;
	volatile uint32_t UDIS:1;
	volatile uint32_t URS:1;
	volatile uint32_t OPM:1;
	volatile uint32_t DIR:1;
	volatile uint32_t CMS:2;
	volatile uint32_t APRE:1;
	volatile uint32_t CKD:2;
	volatile uint32_t Reserved:22;
}TIMER1_8_CR1_Struct;

typedef union{
	uint32_t reg;
	TIMER1_8_CR1_Struct bit;
}TIMER1_8_CR1_Union;


typedef struct{
	volatile uint32_t CCPC:1;
	volatile uint32_t Reserved:1;
	volatile uint32_t CCUS:1;
	volatile uint32_t CCDS:1;
	volatile uint32_t MMS:3;
	volatile uint32_t TI1S:1;
	volatile uint32_t OIS1:1;
	volatile uint32_t OIS1N:1;
	volatile uint32_t OIS2:1;
	volatile uint32_t OIS2N:1;
	volatile uint32_t OIS3:1;
	volatile uint32_t OIS3N:1;
	volatile uint32_t OIS4:1;
	volatile uint32_t Reserved2:17;
}TIMER1_8_CR2_Struct;

typedef union{
	uint32_t reg;
	TIMER1_8_CR2_Struct bit;
}TIMER1_8_CR2_Union;


typedef struct{
	volatile uint32_t SMS:3;
	volatile uint32_t Reserved:1;
	volatile uint32_t TS:3;
	volatile uint32_t MSM:1;
	volatile uint32_t ETF:4;
	volatile uint32_t ETPS:2;
	volatile uint32_t ECE:1;
	volatile uint32_t ETP:1;
	volatile uint32_t Reserved2:16;
}TIMER1_8_SMCR_Struct;

typedef union{
	uint32_t reg;
	TIMER1_8_SMCR_Struct bit;
}TIMER1_8_SMCR_Union;


typedef struct{
	volatile uint32_t UIE:1;
	volatile uint32_t CC1IE:1;
	volatile uint32_t CC2IE:1;
	volatile uint32_t CC3IE:1;
	volatile uint32_t CC4IE:1;
	volatile uint32_t COMIE:1;
	volatile uint32_t TIE:1;
	volatile uint32_t BIE:1;
	volatile uint32_t UDE:1;
	volatile uint32_t CC1DE:1;
	volatile uint32_t CC2DE:1;
	volatile uint32_t CC3DE:1;
	volatile uint32_t CC4DE:1;
	volatile uint32_t COMDE:1;
	volatile uint32_t TDE:1;
	volatile uint32_t Reserved2:17;
}TIMER1_8_DIER_Struct;

typedef union{
	uint32_t reg;
	TIMER1_8_DIER_Struct bit;
}TIMER1_8_DIER_Union;

typedef struct{
	volatile uint32_t UIF:1;
	volatile uint32_t CC1IF:1;
	volatile uint32_t CC2IF:1;
	volatile uint32_t CC3IF:1;
	volatile uint32_t CC4IF:1;
	volatile uint32_t COMIF:1;
	volatile uint32_t TIF:1;
	volatile uint32_t BIF:1;
	volatile uint32_t Reserved:1;
	volatile uint32_t CC1OF:1;
	volatile uint32_t CC2OF:1;
	volatile uint32_t CC3OF:1;
	volatile uint32_t CC4OF:1;
	volatile uint32_t Reserved2:19;
}TIMER1_8_SR_Struct;

typedef union{
	uint32_t reg;
	TIMER1_8_SR_Struct bit;
}TIMER1_8_SR_Union;

typedef struct{
	volatile uint32_t UG:1;
	volatile uint32_t CC1G:1;
	volatile uint32_t CC2G:1;
	volatile uint32_t CC3G:1;
	volatile uint32_t CC4G:1;
	volatile uint32_t COMG:1;
	volatile uint32_t TG:1;
	volatile uint32_t BG:1;
	volatile uint32_t Reserved:24;
}TIMER1_8_EGR_Struct;

typedef union{
	uint32_t reg;
	TIMER1_8_EGR_Struct bit;
}TIMER1_8_EGR_Union;

typedef struct{
	volatile uint32_t CC1S:2;
	volatile uint32_t OC1FE:1;
	volatile uint32_t OC1PE:1;
	volatile uint32_t OC1M:3;
	volatile uint32_t OC1CE:1;
	volatile uint32_t CC2S:2;
	volatile uint32_t OC2FE:1;
	volatile uint32_t OC2PE:1;
	volatile uint32_t OC2M:3;
	volatile uint32_t OC2CE:1;
	volatile uint32_t Reserved:16;
}TIMER1_8_CCMR1_OutputMode_Struct;

typedef struct{
	volatile uint32_t CC1S:2;
	volatile uint32_t IC1PSC:2;
	volatile uint32_t IC1F:4;
	volatile uint32_t CC2S:2;
	volatile uint32_t IC2PSC:2;
	volatile uint32_t IC2F:4;
	volatile uint32_t Reserved:16;
}TIMER1_8_CCMR1_InputMode_Struct;

typedef union{
	uint32_t reg;
	TIMER1_8_CCMR1_OutputMode_Struct OutputCompare;
	TIMER1_8_CCMR1_InputMode_Struct InputCapture;
}TIMER1_8_CCMR1_Union;


typedef struct{
	volatile uint32_t CC3S:2;
	volatile uint32_t OC3FE:1;
	volatile uint32_t OC3PE:1;
	volatile uint32_t OC3M:3;
	volatile uint32_t OC3CE:1;
	volatile uint32_t CC4S:2;
	volatile uint32_t OC4FE:1;
	volatile uint32_t OC4PE:1;
	volatile uint32_t OC4M:3;
	volatile uint32_t OC4CE:1;
	volatile uint32_t Reserved:16;
}TIMER1_8_CCMR2_OutputMode_Struct;

typedef struct{
	volatile uint32_t CC3S:2;
	volatile uint32_t IC3PSC:2;
	volatile uint32_t IC3F:4;
	volatile uint32_t CC4S:2;
	volatile uint32_t IC4PSC:2;
	volatile uint32_t IC4F:4;
	volatile uint32_t Reserved:16;
}TIMER1_8_CCMR2_InputMode_Struct;

typedef union{
	uint32_t reg;
	TIMER1_8_CCMR2_OutputMode_Struct OutputCompare;
	TIMER1_8_CCMR2_InputMode_Struct InputCapture;
}TIMER1_8_CCMR2_Union;

typedef struct{
	volatile uint16_t CC1E:1;
	volatile uint16_t CC1P:1;
	volatile uint16_t CC1NE:1;
	volatile uint16_t CC1NP:1;
	volatile uint16_t CC2E:1;
	volatile uint16_t CC2P:1;
	volatile uint16_t CC2NE:1;
	volatile uint16_t CC2NP:1;
	volatile uint16_t CC3E:1;
	volatile uint16_t CC3P:1;
	volatile uint16_t CC3NE:1;
	volatile uint16_t CC3NP:1;
	volatile uint16_t CC4E:1;
	volatile uint16_t CC4P:1;
	volatile uint16_t Reserved:1;
	volatile uint16_t CC4NP:1;
}TIMER1_8_CCER_Struct;

typedef union{
	uint32_t reg;
	TIMER1_8_CCER_Struct bit;
}TIMER1_8_CCER_Union;


typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER1_8_CNT_Union;

typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER1_8_PSC_Union;

typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER1_8_ARR_Union;

typedef union{
	volatile uint8_t REP;
	volatile uint32_t reg;
}TIMER1_8_RCR_Union;

typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER1_8_CCR1_Union;

typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER1_8_CCR2_Union;

typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER1_8_CCR3_Union;

typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER1_8_CCR4_Union;

typedef struct{
	volatile uint32_t DTG:8;
	volatile uint32_t LOCK:2;
	volatile uint32_t OSSI:1;
	volatile uint32_t OSSR:1;
	volatile uint32_t BKE:1;
	volatile uint32_t BKP:1;
	volatile uint32_t AOE:1;
	volatile uint32_t MOE:1;
	volatile uint32_t Reserved:16;
}TIMER1_8_BDTR_Struct;

typedef union{
	uint32_t reg;
	TIMER1_8_BDTR_Struct bit;
}TIMER1_8_BDTR_Union;


typedef struct{
	volatile uint16_t DBA:5;
	volatile uint16_t Reserved:3;
	volatile uint16_t DBL:5;
	volatile uint16_t Reserved2:3;
}TIMER1_8_DCR_Struct;

typedef union{
	uint32_t reg;
	TIMER1_8_DCR_Struct bit;
}TIMER1_8_DCR_Union;

typedef struct{
	TIMER1_8_CR1_Union CR1;
	TIMER1_8_CR2_Union CR2;
	TIMER1_8_SMCR_Union SMCR;
	TIMER1_8_DIER_Union DIER;
	TIMER1_8_SR_Union SR;
	TIMER1_8_EGR_Union EGR;
	TIMER1_8_CCMR1_Union CCMR1;
	TIMER1_8_CCMR2_Union CCMR2;
	TIMER1_8_CCER_Union CCER;
	TIMER1_8_CNT_Union CNT;
	TIMER1_8_PSC_Union PSC;
	TIMER1_8_ARR_Union ARR;
	TIMER1_8_RCR_Union RCR;
	TIMER1_8_CCR1_Union CCR1;
	TIMER1_8_CCR2_Union CCR2;
	TIMER1_8_CCR3_Union CCR3;
	TIMER1_8_CCR4_Union CCR4;
	TIMER1_8_BDTR_Union BDTR;
	TIMER1_8_DCR_Union DCR;
	volatile uint32_t DMAR;
}HUY_TIMER1_8_Struct;

/////////

typedef struct{
	volatile uint32_t CEN:1;
	volatile uint32_t UDIS:1;
	volatile uint32_t URS:1;
	volatile uint32_t OPM:1;
	volatile uint32_t DIR:1;
	volatile uint32_t CMS:2;
	volatile uint32_t APRE:1;
	volatile uint32_t CKD:2;
	volatile uint32_t Reserved:22;
}TIMER2345_CR1_Struct;

typedef union{
	uint32_t reg;
	TIMER2345_CR1_Struct bit;
}TIMER2345_CR1_Union;


typedef struct{
	volatile uint32_t Reserved:3;
	volatile uint32_t CCDS:1;
	volatile uint32_t MMS:3;
	volatile uint32_t TI1S:1;
	volatile uint32_t Reserved2:24;
}TIMER2345_CR2_Struct;

typedef union{
	uint32_t reg;
	TIMER2345_CR2_Struct bit;
}TIMER2345_CR2_Union;


typedef struct{
	volatile uint32_t SMS:3;
	volatile uint32_t Reserved:1;
	volatile uint32_t TS:3;
	volatile uint32_t MSM:1;
	volatile uint32_t ETF:4;
	volatile uint32_t ETPS:2;
	volatile uint32_t ECE:1;
	volatile uint32_t ETP:1;
	volatile uint32_t Reserved2:16;
}TIMER2345_SMCR_Struct;

typedef union{
	uint32_t reg;
	TIMER2345_SMCR_Struct bit;
}TIMER2345_SMCR_Union;


typedef struct{
	volatile uint32_t UIE:1;
	volatile uint32_t CC1IE:1;
	volatile uint32_t CC2IE:1;
	volatile uint32_t CC3IE:1;
	volatile uint32_t CC4IE:1;
	volatile uint32_t Reserved:1;
	volatile uint32_t TIE:1;
	volatile uint32_t Reserved2:1;
	volatile uint32_t UDE:1;
	volatile uint32_t CC1DE:1;
	volatile uint32_t CC2DE:1;
	volatile uint32_t CC3DE:1;
	volatile uint32_t CC4DE:1;
	volatile uint32_t Reserved3:1;
	volatile uint32_t TDE:1;
	volatile uint32_t Reserved4:17;
}TIMER2345_DIER_Struct;

typedef union{
	uint32_t reg;
	TIMER2345_DIER_Struct bit;
}TIMER2345_DIER_Union;

typedef struct{
	volatile uint32_t UIF:1;
	volatile uint32_t CC1IF:1;
	volatile uint32_t CC2IF:1;
	volatile uint32_t CC3IF:1;
	volatile uint32_t CC4IF:1;
	volatile uint32_t Reserved:1;
	volatile uint32_t TIF:1;
	volatile uint32_t Reserved2:2;
	volatile uint32_t CC1OF:1;
	volatile uint32_t CC2OF:1;
	volatile uint32_t CC3OF:1;
	volatile uint32_t CC4OF:1;
	volatile uint32_t Reserved3:19;
}TIMER2345_SR_Struct;

typedef union{
	uint32_t reg;
	TIMER2345_SR_Struct bit;
}TIMER2345_SR_Union;

typedef struct{
	volatile uint32_t UG:1;
	volatile uint32_t CC1G:1;
	volatile uint32_t CC2G:1;
	volatile uint32_t CC3G:1;
	volatile uint32_t CC4G:1;
	volatile uint32_t Reserved:1;
	volatile uint32_t TG:1;
	volatile uint32_t Reserved2:1;
	volatile uint32_t Reserved3:24;
}TIMER2345_EGR_Struct;

typedef union{
	uint32_t reg;
	TIMER2345_EGR_Struct bit;
}TIMER2345_EGR_Union;

typedef struct{
	volatile uint32_t CC1S:2;
	volatile uint32_t OC1FE:1;
	volatile uint32_t OC1PE:1;
	volatile uint32_t OC1M:3;
	volatile uint32_t OC1CE:1;
	volatile uint32_t CC2S:2;
	volatile uint32_t OC2FE:1;
	volatile uint32_t OC2PE:1;
	volatile uint32_t OC2M:3;
	volatile uint32_t OC2CE:1;
	volatile uint32_t Reserved:16;
}TIMER2345_CCMR1_OutputMode_Struct;

typedef struct{
	volatile uint32_t CC1S:2;
	volatile uint32_t IC1PSC:2;
	volatile uint32_t IC1F:4;
	volatile uint32_t CC2S:2;
	volatile uint32_t IC2PSC:2;
	volatile uint32_t IC2F:4;
	volatile uint32_t Reserved:16;
}TIMER2345_CCMR1_InputMode_Struct;

typedef union{
	uint32_t reg;
	TIMER2345_CCMR1_OutputMode_Struct OutputCompare;
	TIMER2345_CCMR1_InputMode_Struct InputCapture;
}TIMER2345_CCMR1_Union;


typedef struct{
	volatile uint32_t CC3S:2;
	volatile uint32_t OC3FE:1;
	volatile uint32_t OC3PE:1;
	volatile uint32_t OC3M:3;
	volatile uint32_t OC3CE:1;
	volatile uint32_t CC4S:2;
	volatile uint32_t OC4FE:1;
	volatile uint32_t OC4PE:1;
	volatile uint32_t OC4M:3;
	volatile uint32_t OC4CE:1;
	volatile uint32_t Reserved:16;
}TIMER2345_CCMR2_OutputMode_Struct;

typedef struct{
	volatile uint32_t CC3S:2;
	volatile uint32_t IC3PSC:2;
	volatile uint32_t IC3F:4;
	volatile uint32_t CC4S:2;
	volatile uint32_t IC4PSC:2;
	volatile uint32_t IC4F:4;
	volatile uint32_t Reserved:16;
}TIMER2345_CCMR2_InputMode_Struct;

typedef union{
	uint32_t reg;
	TIMER2345_CCMR2_OutputMode_Struct OutputCompare;
	TIMER2345_CCMR2_InputMode_Struct InputCapture;
}TIMER2345_CCMR2_Union;

typedef struct{
	volatile uint16_t CC1E:1;
	volatile uint16_t CC1P:1;
	volatile uint16_t Reserved:2;
	volatile uint16_t CC2E:1;
	volatile uint16_t CC2P:1;
	volatile uint16_t Reserved2:2;
	volatile uint16_t CC3E:1;
	volatile uint16_t CC3P:1;
	volatile uint16_t Reserved3:2;
	volatile uint16_t CC4E:1;
	volatile uint16_t CC4P:1;
	volatile uint16_t Reserved4:2;
}TIMER2345_CCER_Struct;

typedef union{
	uint32_t reg;
	TIMER2345_CCER_Struct bit;
}TIMER2345_CCER_Union;


typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER2345_CNT_Union;

typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER2345_PSC_Union;

typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER2345_ARR_Union;


typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER2345_CCR1_Union;

typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER2345_CCR2_Union;

typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER2345_CCR3_Union;

typedef union{
	volatile uint16_t Data;
	volatile uint32_t reg;
}TIMER2345_CCR4_Union;



typedef struct{
	volatile uint16_t DBA:5;
	volatile uint16_t Reserved:3;
	volatile uint16_t DBL:5;
	volatile uint16_t Reserved2:3;
}TIMER2345_DCR_Struct;

typedef union{
	uint32_t reg;
	TIMER2345_DCR_Struct bit;
}TIMER2345_DCR_Union;

typedef struct{
	TIMER2345_CR1_Union CR1;
	TIMER2345_CR2_Union CR2;
	TIMER2345_SMCR_Union SMCR;
	TIMER2345_DIER_Union DIER;
	TIMER2345_SR_Union SR;
	TIMER2345_EGR_Union EGR;
	TIMER2345_CCMR1_Union CCMR1;
	TIMER2345_CCMR2_Union CCMR2;
	TIMER2345_CCER_Union CCER;
	TIMER2345_CNT_Union CNT;
	TIMER2345_PSC_Union PSC;
	TIMER2345_ARR_Union ARR;
	volatile uint32_t Reserved;
	TIMER2345_CCR1_Union CCR1;
	TIMER2345_CCR2_Union CCR2;
	TIMER2345_CCR3_Union CCR3;
	TIMER2345_CCR4_Union CCR4;
	TIMER1_8_DCR_Union DCR;
	volatile uint32_t DMAR;
}HUY_TIMER2345_Struct;

#define HUY_TIMER1 ((HUY_TIMER1_8_Struct *)0x40012C00)
#define HUY_TIMER8 ((HUY_TIMER1_8_Struct *)0x40013400)
#define HUY_TIMER2 ((HUY_TIMER2345_Struct *)0x40000000)
#define HUY_TIMER3 ((HUY_TIMER2345_Struct *)0x40000400)
#define HUY_TIMER4 ((HUY_TIMER2345_Struct *)0x40000800)
#define HUY_TIMER5 ((HUY_TIMER2345_Struct *)0x40000C00)



#endif


#ifndef ADC_H
#define ADC_H

typedef struct{
	volatile uint32_t AWD:1;
	volatile uint32_t EOC:1;
	volatile uint32_t JEOC:1;
	volatile uint32_t JSTRT:1;
	volatile uint32_t STRT:1;
	volatile uint32_t Reserved:27;
}ADC_SR_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_SR_Struct bit;
}ADC_SR_Union;

/////
typedef struct{
	volatile uint32_t AWDCH:5;
	volatile uint32_t EOCIE:1;
	volatile uint32_t AWDIE:1;
	volatile uint32_t JEOCIE:1;
	volatile uint32_t SCAN:1;
	volatile uint32_t AWDSGL:1;
	volatile uint32_t JAUTO:1;
	volatile uint32_t DISCEN:1;
	volatile uint32_t JDISCEN:1;
	volatile uint32_t DISCNUM:3;
	volatile uint32_t DUALMOD:4;
	volatile uint32_t Reserved:2;
	volatile uint32_t JAWDEN:1;
	volatile uint32_t AWDEN:1;
	volatile uint32_t Reserved2:8
}ADC_CR1_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_CR1_Struct bit;
}ADC_CR1_Union;

////
typedef struct{
	volatile uint32_t ADON:1;
	volatile uint32_t CONT:1;
	volatile uint32_t CAL:1;
	volatile uint32_t RSTCAL:1;
	volatile uint32_t Reserved:4;
	volatile uint32_t DMA:1;
	volatile uint32_t Reserved2:2;
	volatile uint32_t ALIGN:1;
	volatile uint32_t JEXTSEL:3;
	volatile uint32_t JEXTTRIG:1;
	volatile uint32_t Reserved3:1;
	volatile uint32_t EXTSEL:3;
	volatile uint32_t EXTTRIG:1;
	volatile uint32_t JSWTART:1;
	volatile uint32_t SWSTART:1;
	volatile uint32_t TSVREFE:1;
	volatile uint32_t Reserved4:8;
}ADC_CR2_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_CR2_Struct bit;
}ADC_CR2_Union;


////
typedef struct{
	volatile uint32_t SMP10:3;
	volatile uint32_t SMP11:3;
	volatile uint32_t SMP12:3;
	volatile uint32_t SMP13:3;
	volatile uint32_t SMP14:3;
	volatile uint32_t SMP15:3;
	volatile uint32_t SMP16:3;
	volatile uint32_t SMP17:3;
	volatile uint32_t Reserved:8;
}ADC_SMPR1_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_SMPR1_Struct bit;
}ADC_SMPR1_Union;

////
typedef struct{
	volatile uint32_t SMP0:3;
	volatile uint32_t SMP1:3;
	volatile uint32_t SMP2:3;
	volatile uint32_t SMP3:3;
	volatile uint32_t SMP4:3;
	volatile uint32_t SMP5:3;
	volatile uint32_t SMP6:3;
	volatile uint32_t SMP7:3;
	volatile uint32_t SMP8:3;
	volatile uint32_t SMP9:3;
	volatile uint32_t Reserved:2;
}ADC_SMPR2_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_SMPR2_Struct bit;
}ADC_SMPR2_Union;


////
typedef struct{
	volatile uint32_t JOFFSET1:12;
	volatile uint32_t Reserved:20;
}ADC_JOFR1_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_JOFR1_Struct bit;
}ADC_JOFR1_Union;

////
typedef struct{
	volatile uint32_t JOFFSET2:12;
	volatile uint32_t Reserved:20;
}ADC_JOFR2_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_JOFR2_Struct bit;
}ADC_JOFR2_Union;



////
typedef struct{
	volatile uint32_t JOFFSET3:12;
	volatile uint32_t Reserved:20;
}ADC_JOFR3_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_JOFR3_Struct bit;
}ADC_JOFR3_Union;


////
typedef struct{
	volatile uint32_t JOFFSET4:12;
	volatile uint32_t Reserved:20;
}ADC_JOFR4_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_JOFR4_Struct bit;
}ADC_JOFR4_Union;

////
typedef struct{
	volatile uint32_t HT:12;
	volatile uint32_t Reserved:20;
}ADC_HTR_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_HTR_Struct bit;
}ADC_HTR_Union;

////
typedef struct{
	volatile uint32_t LT:12;
	volatile uint32_t Reserved:20;
}ADC_LTR_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_LTR_Struct bit;
}ADC_LTR_Union;


////
typedef struct{
	volatile uint32_t SQ13:5;
	volatile uint32_t SQ14:5;
	volatile uint32_t SQ15:5;
	volatile uint32_t SQ16:5;
	volatile uint32_t L:4;
	volatile uint32_t Reserved:8;
}ADC_SQR1_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_SQR1_Struct bit;
}ADC_SQR1_Union;

////
typedef struct{
	volatile uint32_t SQ7:5;
	volatile uint32_t SQ8:5;
	volatile uint32_t SQ9:5;
	volatile uint32_t SQ10:5;
	volatile uint32_t SQ11:5;
	volatile uint32_t SQ12:5;
	volatile uint32_t Reserved:2;
}ADC_SQR2_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_SQR2_Struct bit;
}ADC_SQR2_Union;


////
typedef struct{
	volatile uint32_t SQ1:5;
	volatile uint32_t SQ2:5;
	volatile uint32_t SQ3:5;
	volatile uint32_t SQ4:5;
	volatile uint32_t SQ5:5;
	volatile uint32_t SQ6:5;
	volatile uint32_t Reserved:2;
}ADC_SQR3_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_SQR3_Struct bit;
}ADC_SQR3_Union;

////
typedef struct{
	volatile uint32_t JSQ1:5;
	volatile uint32_t JSQ2:5;
	volatile uint32_t JSQ3:5;
	volatile uint32_t JSQ4:5;
	volatile uint32_t JL:2;
	volatile uint32_t Reserved:10;
}ADC_JSQR_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_JSQR_Struct bit;
}ADC_JSQR_Union;


////
typedef union{
	volatile uint32_t reg;
	volatile uint16_t JDATA;
}ADC_JDR1_Union;


////
typedef union{
	volatile uint32_t reg;
	volatile uint16_t JDATA;
}ADC_JDR2_Union;


////
typedef union{
	volatile uint32_t reg;
	volatile uint16_t JDATA;
}ADC_JDR3_Union;

////
typedef union{
	volatile uint32_t reg;
	volatile uint16_t JDATA;
}ADC_JDR4_Union;


////
typedef struct{
	volatile uint32_t DATA:16;
	volatile uint32_t ADC2DATA:16;
}ADC_DR_Struct;

typedef union{
	volatile uint32_t reg;
	ADC_DR_Struct bit;
}ADC_DR_Union;

typedef struct{
	ADC_SR_Union SR;
	ADC_CR1_Union CR1;
	ADC_CR2_Union CR2;
	ADC_SMPR1_Union SMPR1;
	ADC_SMPR2_Union SMPR2;
	ADC_JOFR1_Union JOFR1;
	ADC_JOFR2_Union JOFR2;
	ADC_JOFR3_Union JOFR3;
	ADC_JOFR4_Union JOFR4;
	ADC_HTR_Union HTR;
	ADC_LTR_Union LTR;
	ADC_SQR1_Union SQR1;
	ADC_SQR2_Union SQR2;
	ADC_SQR3_Union SQR3;
	ADC_JSQR_Union JSQR;
	ADC_JDR1_Union JDR1;
	ADC_JDR2_Union JDR2;
	ADC_JDR3_Union JDR3;
	ADC_JDR4_Union JDR4;
	ADC_DR_Union DR;
}HUY_ADC_Struct;

#define HUY_ADC1 ((HUY_ADC_Struct *)0x40012400)
#define HUY_ADC2 ((HUY_ADC_Struct *)0x40012800)
#define HUY_ADC3 ((HUY_ADC_Struct *)0x40013C00)

#endif
