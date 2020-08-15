#ifndef __LED_H__
#define __LED_H__

#include "GPIO_interface.h"

#define LED0_PORT   PORTB
#define LED1_PORT   PORTB

#define LED0_PIN    PIN_10
#define LED1_PIN    PIN_1


typedef enum
{
    LED_0,
	LED_1,
}tLED;

typedef enum
{
	LED_OFF,
	LED_ON
}tLED_State;


void LED_Init(tLED led, tLED_State initial_state);
void LED_SetState(tLED led, tLED_State state);
tLED_State LED_GetState(tLED led);
void LED_Toggle(tLED led);
void LED_Update(void);
#endif // __LED_H__
