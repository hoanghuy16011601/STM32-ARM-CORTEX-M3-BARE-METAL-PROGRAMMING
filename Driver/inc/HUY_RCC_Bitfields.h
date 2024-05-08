
/// CMSIS 
#define HUY_RCC_CR_PLLRDY_PLL_UnLocked 0x00U
#define HUY_RCC_CR_PLLRDY_PLL_Locked 0x01U

#define HUY_RCC_CR_PLLON_PLL_OFF 0x00U
#define HUY_RCC_CR_PLLON_PLL_ON 0x01U

#define HUY_RCC_CR_CSSON_Clock_DetectorOFF 0x00U
#define HUY_RCC_CR_CSSON_Clock_DetectorON 0x01U

#define HUY_RCC_CR_HSEBYP_HSE_NotBypass 0x00U
#define HUY_RCC_CR_HSEBYP_HSE_Bypass 0x01U

#define HUY_RCC_CR_HSERDY_HSE_NotReady 0x00U
#define HUY_RCC_CR_HSERDY_HSE_Ready 0x01U

#define HUY_RCC_CR_HSEON_HSE_OFF 0x00U
#define HUY_RCC_CR_HSEON_HSE_ON 0x01U

#define HUY_RCC_CR_HSIRDY_HSI_NotReady 0x00U
#define HUY_RCC_CR_HSIRDY_HSI_Ready 0x01U

#define HUY_RCC_CR_HSION_HSI_OFF 0x00U
#define HUY_RCC_CR_HSION_HSI_ON 0x01U

#define HUY_RCC_CFGR_MCO_NoCLK 0X00U
#define HUY_RCC_CFGR_MCO_SYSCLK_Selected 0X04U
#define HUY_RCC_CFGR_MCO_HSICLK_Selected 0X05U
#define HUY_RCC_CFGR_MCO_HSECLK_Selected 0X06U
#define HUY_RCC_CFGR_MCO_PLLCLK_Divided2_Selected 0X07U

#define HUY_RCC_CFGR_USBPRE_PLL_Divided  0x00U
#define HUY_RCC_CFGR_USBPRE_PLL_NotDivided  0x01U






//// Parameter Drive

#define PLL_Select_HSI_Divided2 0X00U
#define PLL_Select_HSE 0X01U

#define SYSCLK_Select_HSI 0X00U
#define SYSCLK_Select_HSE 0X01U
#define SYSCLK_Select_PLL 0X02U

#define SYSCLK_Selected_HSI 0X00U
#define SYSCLK_Selected_HSE 0X01U
#define SYSCLK_Selected_PLL 0X02U

#define HSE_NotDivided 0X00U
#define HSE_Divided2  0X01U

#define ADC_Prescaler_Divided2 0x00U
#define ADC_Prescaler_Divided4 0x01U
#define ADC_Prescaler_Divided6 0x02U
#define ADC_Prescaler_Divided8 0x03U

#define APB2_Prescaler_NotDivided 0x00U
#define APB2_Prescaler_Divided2 0x04U
#define APB2_Prescaler_Divided4 0x05U
#define APB2_Prescaler_Divided8 0x06U
#define APB2_Prescaler_Divided16 0x07U

#define APB1_Prescaler_NotDivided 0x00U
#define APB1_Prescaler_Divided2 0x04U
#define APB1_Prescaler_Divided4 0x05U
#define APB1_Prescaler_Divided8 0x06U
#define APB1_Prescaler_Divided16 0x07U

#define AHB_Prescaler_NotDivided 0x00U
#define AHB_Prescaler_Divided2 0x08U
#define AHB_Prescaler_Divided4 0x09U
#define AHB_Prescaler_Divided8 0x0AU
#define AHB_Prescaler_Divided16 0x0BU
#define AHB_Prescaler_Divided64 0x0CU
#define AHB_Prescaler_Divided128 0x0DU
#define AHB_Prescaler_Divided256 0x0EU
#define AHB_Prescaler_Divided512 0x0FU

#define PLL_Multiple2   0X000U 
#define PLL_Multiple3   0X001U
#define PLL_Multiple4   0X002U 
#define PLL_Multiple5   0X003U
#define PLL_Multiple6   0X004U 
#define PLL_Multiple7   0X005U
#define PLL_Multiple8   0X006U 
#define PLL_Multiple9   0X007U
#define PLL_Multiple10  0X008U 
#define PLL_Multiple11  0X009U
#define PLL_Multiple12  0X00AU 
#define PLL_Multiple13  0X00BU
#define PLL_Multiple14  0X00CU 
#define PLL_Multiple15  0X00DU
#define PLL_Multiple16  0X00EU 






