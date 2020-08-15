/*
 * GPIO_private.h
 *
 *  Created on: Aug 14, 2020
 *      Author: MohamedDiaa
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/*************************************** PORT REGISTERS BASE ADDRESSES *****************************************/
typedef enum{
		PORTA  = 				0x40010800,
		PORTB  = 				0x40010C00,
		PORTC  = 				0x40011000,
		PORTD  = 				0x40011400,
		PORTE  =			    0x40011800,
		PORTF  =	 			0x40011C00,
		PORTG  =	 			0x40012000
}GPIO_PORT;
/*************************************** PORT REGISTER OFFSITS *************************************************/
#define GPIO_CRL_OFFSIT         0x00
#define GPIO_CRH_OFFSIT			0x04
#define GPIO_IDR_OFFSIT         0x08
#define GPIO_ODR_OFFSIT         0x0C


/**************************************** MACRO TO ACCESS GPIO PORT DEFERRENT REGISTERS USING OFFSIT ***********/
#define GPIO_REG(PORT,OFFSIT)           *((volatile u32*)(PORT+OFFSIT))

/**************************************** MACRO TO SET GPIO PIN CONFIGURATIONS & mode *************************/
#define GPIO_CONFIG_PIN(ADDR,PIN,MODE)  ADDR &= ~((0x0000000F)<<(PIN*4));\
										ADDR |= ((MODE & 0x0000000F)<<(PIN*4))


#endif /* GPIO_PRIVATE_H_ */
