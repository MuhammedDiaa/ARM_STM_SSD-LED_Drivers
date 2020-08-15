/*
 * GPIO_program.c
 *
 *  Created on: Aug 14, 2020
 *      Author: MohamedDiaa
 */
#include"GPIO_interface.h"


void GPIO_InitPortPin(GPIO_PORT Copy_Port,PIN_t Copy_Pin,PIN_MODE Copy_Mode)
{
	u32* addr = (u32*)(Copy_Port);
	//store the passed address

	if(Copy_Pin<=7)
	{
		addr += GPIO_CRL_OFFSIT;
		// Add the Proper OFFSIT to the stored address
		GPIO_CONFIG_PIN(*addr,Copy_Pin,Copy_Mode);
		//Configure the passed pin with the passed mode
	}
	else if(Copy_Pin>7)
	{
		addr += GPIO_CRH_OFFSIT;
		// Add the Proper OFFSIT to the stored address
		GPIO_CONFIG_PIN(*addr,Copy_Pin,Copy_Mode);
		//Configure the passed pin with the passed mode
	}
	else
	{
		//return error
	}
}

void GPIO_WritePortPin(GPIO_PORT Copy_Port,PIN_t Copy_Pin,PIN_STATE Copy_State)
{
	u32* addr = (u32*)(Copy_Port + GPIO_ODR_OFFSIT);
	// Add the ODR OFFSIT to the PORT address
	INSERT_BIT_VALUE(*addr,Copy_Pin,Copy_State);
}

u8 GPIO_ReadPortPin(GPIO_PORT Copy_Port,PIN_t Copy_Pin)
{
	u32* addr = (u32*)(Copy_Port + GPIO_IDR_OFFSIT);
	// Add the ODR OFFSIT to the PORT address
	return GET_BIT(*addr,Copy_Pin);
}

void GPIO_WritePort(GPIO_PORT Copy_Port,u32 Copy_u32State)
{
	u32* addr = (u32*)(Copy_Port + GPIO_ODR_OFFSIT);
	// Add the ODR OFFSIT to the PORT address
	*addr = Copy_u32State;
}

u32 GPIO_ReadPort(GPIO_PORT Copy_Port)
{
	u32* addr = (u32*)(Copy_Port + GPIO_IDR_OFFSIT);
	// Add the ODR OFFSIT to the PORT address
	return *addr ;
}
