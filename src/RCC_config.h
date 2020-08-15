/*
 * RCC_config.h
 *
 *  Created on: Aug 13, 2020
 *      Author: MohamedDiaa
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/*SELECT CLOCK SOURCE OPTIONS 1.RCC_HSI
 * 							  2.RCC_HSE_CRYSTAL
 * 							  3.RCC_HSE_RC
 * 							  4.RCC_PLL        */
#define RCC_PLL

/*SELECT RCC_PLL_INPUT if CLOCK SOURCE is RCC_PLL 1.RCC_PLL_IN_HSI_DIV_2
 *  				  							  2.RCC_PLL_IN_HSE_DIV_2
 *   										      3.RCC_PLL_IN_HSE       */
#define RCC_PLL_IN_HSE

/*SELECT RCC_PLL_MUL if CLOCK SOURCE is RCC_PLL ==> PLL_MUL_X : X = [2:16] */
#define RCC_PLL_MUL  PLL_MUL_2


#endif /* RCC_CONFIG_H_ */
