/*
 * GPIO_interface.h
 *
 *  Created on: Aug 14, 2020
 *      Author: MohamedDiaa
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_private.h"
#include "GPIO_config.h"
/************************************************ PIN MODES **************************************************/
typedef enum{
	INPUT_ANALOG,
	OUTPUT_10M_PP,
	OUTPUT_2M_PP,
	OUTPUT_50M_PP,
	INPUT_FLOAT,
	OUTPUT_10M_OD,
	OUTPUT_2M_OD,
	OUTPUT_50M_OD,
	INPUT_PU_PD,
	OUTPUT_10M_AF_PP,
	OUTPUT_2M_AF_PP,
	OUTPUT_50M_AF_PP,
	RESERVED,
	OUTPUT_10M_AF_OD,
	OUTPUT_2M_AF_OD,
	OUTPUT_50M_AF_OD,
}PIN_MODE;

/************************************************ PINS **************************************************/
typedef enum{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15,
}PIN_t;

/************************************************ PINS STATES**********************************************/
typedef enum{
	LOW,
	HIGH
}PIN_STATE;

/*********************************************FUNCTIONS PROTOTYPES****************************************/
void GPIO_InitPortPin(GPIO_PORT Copy_Port,PIN_t Copy_Pin,PIN_MODE Copy_Mode);
void GPIO_WritePortPin(GPIO_PORT Copy_Port,PIN_t Copy_Pin,PIN_STATE Copy_State);
u8   GPIO_ReadPortPin(GPIO_PORT Copy_Port,PIN_t Copy_Pin);
void GPIO_WritePort(GPIO_PORT Copy_Port,u32 Copy_u32State);
void GPIO_WriteHaIfPort(GPIO_PORT Copy_Port,u32 Copy_u32State);
u32  GPIO_ReadPort(GPIO_PORT Copy_Port);


#endif /* GPIO_INTERFACE_H_ */
