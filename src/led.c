#include "led.h"

void LED_Init(tLED led, tLED_State initial_state)
{
    /* Initialize led pin as an output */
    switch(led)
    {
    case LED_0:
        GPIO_InitPortPin(LED0_PORT,LED0_PIN,OUTPUT_10M_PP);
        break;
    case LED_1:
        GPIO_InitPortPin(LED1_PORT,LED1_PIN,OUTPUT_10M_PP);
        break;
    default:
        /* Should not be here */
        break;
    }
    /* Set led state with initial_state */
    LED_SetState(led, initial_state);
}

tLED_State LED_GetState(tLED led)
{
    tLED_State ret = LED_OFF;

    switch(led)
    {
    case LED_0:
        ret = GPIO_ReadPortPin(LED0_PORT,LED0_PIN);
        break;
    case LED_1:
        ret = GPIO_ReadPortPin(LED1_PORT,LED1_PIN);
        break;
    default:
        /* Should not be here */
        break;
    }

    return ret;

}
void LED_SetState(tLED led, tLED_State state)
{
    switch(led)
    {
    case LED_0:
        GPIO_WritePortPin(LED0_PORT,LED0_PIN,state);
        break;
    case LED_1:
        GPIO_WritePortPin(LED1_PORT,LED1_PIN,state);
        break;
    default:
        /* Should not be here */
        break;
    }

}

void LED_Toggle(tLED led)
{
    if (LED_GetState(led) == LED_ON)
    {
        LED_SetState(led, LED_OFF);
    }
    else
    {
        LED_SetState(led, LED_ON);
    }
}

void LED_Update(void)
{
	LED_SetState(LED_0,LED_ON);
	LED_SetState(LED_1,LED_ON);
}
