/*
 * RCC_private.h
 *
 *  Created on: Aug 13, 2020
 *      Author: MohamedDiaa
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#include "RCC_config.h"

/************************************************** REGISTER MAP **********************************************/
#define RCC_CR         *((volatile u32*)0x40021000)
#define RCC_CFGR       *((volatile u32*)0x40021004)
#define RCC_AHBENR     *((volatile u32*)0x40021014)
#define RCC_APB2ENR    *((volatile u32*)0x40021018)
#define RCC_APB1ENR    *((volatile u32*)0x4002101C)

#define RCC_BUS_BASE   0x40021014

/************************************************** DATA TYPES **********************************************/
typedef enum{
	RCC_AHB  = 0,
	RCC_APB1 = 8,
	RCC_APB2 = 4
}BUSID;
typedef enum {
	/*AHB PERIPHERALS*/
	RCC_DMA1 =  0,
	RCC_DMA2 =  1,
	RCC_SRAM =  2,
	RCC_FLTF =  4,
	RCC_CRC  =  6,
	RCC_FSMC =  8,
	RCC_SDIO = 10,
   /*APB1 PERIPHERALS*/
	RCC_TMR2   = 0,
	RCC_TMR3   = 1,
	RCC_TMR4   = 2,
	RCC_TMR5   = 3,
	RCC_TMR6   = 4,
	RCC_TMR7   = 5,
	RCC_TMR12  = 6,
	RCC_TMR13  = 7,
	RCC_TMR14  = 8,
	RCC_WTD    = 11,
	RCC_SPI2   = 14,
	RCC_SPI3   = 15,
	RCC_USART2 = 17,
	RCC_USART3 = 18,
	RCC_USART4 = 19,
	RCC_USART5 = 20,
	RCC_I2C1   = 21,
	RCC_I2C2   = 22,
	RCC_USB    = 23,
	RCC_CAN    = 25,
	RCC_BKP    = 27,
	RCC_PWR    = 28,
	RCC_DAC    = 29,
   /*APB2 PERIPHERALS*/
	RCC_TMR11  = 21,
	RCC_TMR10  =20,
	RCC_TIM9   =19,
	RCC_ADC3   =15,
	RCC_USART1 =14,
	RCC_TMR8   =13,
	RCC_SPI1   =12,
	RCC_TMR1   =11,
	RCC_ADC2   =10,
	RCC_ADC1   =9,
	RCC_IOPG   =8,
	RCC_IOPF   =7,
	RCC_IOPE   =6,
	RCC_IOPD   =5,
	RCC_IOPC   =4,
	RCC_IOPB   =3,
	RCC_IOPA   =2,
	RCC_AFIO   =0,
}PERID;

typedef enum {
	PLL_MUL_2,
	PLL_MUL_3,
	PLL_MUL_4,
	PLL_MUL_5,
	PLL_MUL_6,
	PLL_MUL_7,
	PLL_MUL_8,
	PLL_MUL_9,
	PLL_MUL_10,
	PLL_MUL_11,
	PLL_MUL_12,
	PLL_MUL_13,
	PLL_MUL_14,
	PLL_MUL_15,
	PLL_MUL_16
}PLL_MUL;

/************************************************** CONFIGURATIONS RESULT **********************************************/
#ifdef RCC_HSI
#define CTRL	 0x00000081  				 //enable HSI && TRIM INITIALIZATION
#define CONFIG   0x00000000					 //SELECT HSI as a SYS CLK
#endif

#ifdef RCC_HSE_CRYSTAL
#define CTRL     0x00010000				    //enable HSE as CRYSTAL
#define CONFIG   0x00000001				    //SELECT HSI as a SYS CLK
#endif

#ifdef RCC_HSE_RC
#define CTRL     0x00050000				   //enable HSE as BYBASS
#define CONFIG   0x00000001				   //SELECT HSE as a SYS CLK
#endif


#ifdef RCC_PLL
		#ifdef RCC_PLL_IN_HSI_DIV_2
			#define CTRL     0x01000081    //enable PLL ON && HSI
			#define CONFIG   0x00000002    //SELECT PLL as a SYS CLK && SELECT HSI/2
		#endif
		#ifdef RCC_PLL_IN_HSE_DIV_2
			#define CTRL     0x01010000   //enable PLL ON && HSE && DISABLE HSE BYPASS
			#define CONFIG   0x00030002   //SELECT PLL as a SYS CLK && SELECT HSE/2
		#endif
		#ifdef RCC_PLL_IN_HSE
			#define CTRL     0x01010000   //enable PLL ON && HSE && DISABLE HSE BYPASS
			#define CONFIG   0x00010002   //SELECT PLL as a SYS CLK && SELECT HSE NOT DIVIDED
		#endif
#endif



#endif /* RCC_PRIVATE_H_ */
