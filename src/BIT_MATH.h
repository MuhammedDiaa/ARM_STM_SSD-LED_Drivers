/*
 * BIT_MATH.h
 *
 *  Created on: Aug 13, 2020
 *      Author: MohamedDiaa
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT)          		VAR |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT)         	    VAR &= ~(1 << (BIT))
#define INSERT_BIT_VALUE(REG, BIT, VAL) ((REG) = (((REG) & (~(1<<BIT))) | ((VAL) << (BIT))))
#define GET_BIT(VAR,BIT)         	    ((VAR >> BIT) & 1  )
#define TOG_BIT(VAR,BIT)        	    VAR ^=  (1 << (BIT))


#endif /* BIT_MATH_H_ */
