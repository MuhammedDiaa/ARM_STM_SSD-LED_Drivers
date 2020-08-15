/*
 * RCC_interface.h
 *
 *  Created on: Aug 13, 2020
 *      Author: MohamedDiaa
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/********************************************* FUNCTION PROTOTYPES ***********************************************/
void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(BUSID Copy_BusId, PERID Copy_PerId);
void RCC_voidDisableClock(BUSID Copy_BusId, PERID Copy_PerId);

#endif /* RCC_INTERFACE_H_ */
