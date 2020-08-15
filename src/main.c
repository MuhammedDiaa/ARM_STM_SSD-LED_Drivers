#include <stdio.h>
#include <stdlib.h>
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SSD.h"
#include "led.h"

#define PORTA_CRL    *((volatile u32*)0x40010800)

void UTIL_DelayMS(unsigned int delay_ms)
{
    unsigned int x;
    unsigned int y;

    for (x = 0; x < delay_ms; x++)
    {
        for(y = 0; y <delay_ms; y++)
        {
        	asm("NOP");
        }
    }
}

void main()
{
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
	RCC_voidEnableClock(RCC_APB2,RCC_IOPB);

	SSD_Init(SSD_L,SSD_ON,SSD_NULL);
	LED_Init(LED_0,LED_OFF);
	LED_Init(LED_1,LED_OFF);

  while (1)
    {
	  LED_Update();
	  SSD_update();
	  UTIL_DelayMS(5000);
    }
}



