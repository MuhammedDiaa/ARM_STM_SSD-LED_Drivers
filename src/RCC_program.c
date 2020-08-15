/*
 * RCC_program.c
 *
 *  Created on: Aug 13, 2020
 *      Author: MohamedDiaa
 */
#include "RCC_interface.h"


void RCC_voidInitSysClock(void)
{
		RCC_CFGR = CONFIG;
		#ifdef RCC_PLL
			RCC_CFGR |= ((RCC_PLL_MUL & 0x0000000F)<<18); //MASK FOR ASSIGN PLL MUL BITS WITH THE DESIRED NUMBER
		#endif
		RCC_CR   = CTRL;
}



void RCC_voidEnableClock(BUSID Copy_BusId, PERID Copy_PerId)
{
	u32* addr = (u32 *)(RCC_BUS_BASE + Copy_BusId) ;

	if (Copy_PerId <= 31)
	{
		SET_BIT(*addr,Copy_PerId);
	}
	else
	{
		/* Return Error*/
	}

}


void RCC_voidDisableClock(BUSID Copy_BusId, PERID Copy_PerId)
{
	u32* addr = (u32 *)(RCC_BUS_BASE + Copy_BusId) ;

	if (Copy_PerId <= 31)
	{
		CLR_BIT(*addr,Copy_PerId);
	}
	else
	{
		/* Return Error*/
	}
}

