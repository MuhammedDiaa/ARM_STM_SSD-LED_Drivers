#include "SSD.h"

//Seven segment display lookup table
static const u16 symbols [11] = {
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111,
    0b00000000
};

unsigned char SSD_symbols[SSD_NUMBER]={SSD_NULL};

void SSD_Init(tSSD ssd ,SSD_STATE initial_state , SSD_symbol initial_symbol)
{
	switch(ssd)
	{
		case SSD_L :
		    /*initialize the port that the ssd will be connected on*/
			for(int i = 0;i<16;i++){
				GPIO_InitPortPin(SSD_L_DATA_PORT,i,OUTPUT_10M_PP);
			}

			/*set SSD PORT to null in the beginning*/
		    GPIO_WritePort(SSD_L_DATA_PORT,symbols[SSD_NULL]);

		    /*Init enable pin for the ssd that the user will choose */
			GPIO_InitPortPin(SSD_L_ENABLE_PORT,SSD_L_ENABLE_PIN,OUTPUT_10M_PP);
			break;

		case SSD_R:
			/*initialize the port that the ssd will be connected on*/
			for(int i = 0;i<16;i++){
				GPIO_InitPortPin(SSD_R_DATA_PORT,i,OUTPUT_10M_PP);
			}

			/*set SSD PORT to null in the beginning*/
			GPIO_WritePort(SSD_R_DATA_PORT,symbols[SSD_NULL]);

			/*Init enable pin for the ssd that the user will choose */
			GPIO_InitPortPin(SSD_R_ENABLE_PORT,SSD_R_ENABLE_PIN,OUTPUT_10M_PP);
			break;

		default :
			//shouldn't be here
			break;
	}
        SSD_SET_state(ssd,initial_state);
        SSD_SET_Symbol(ssd,initial_symbol);
}

void SSD_SET_state(tSSD ssd ,SSD_STATE state)
{
    switch(ssd)
        {
            /*init enable pin for the ssd that the user will choose */
            case SSD_L :
                GPIO_WritePortPin(SSD_L_ENABLE_PORT,SSD_L_ENABLE_PIN,state);
                break;
            case SSD_R:
            	GPIO_WritePortPin(SSD_R_ENABLE_PORT,SSD_R_ENABLE_PIN,state);
                break;
            default :
                //shouldn't be here
                break;
        }

}

void SSD_SET_Symbol(tSSD ssd ,SSD_symbol symbol)
{
    SSD_symbols[ssd] = symbol ;
}


SSD_STATE SSD_GET_state(tSSD ssd)
{
    switch(ssd)
        {
            /*init enable pin for the ssd that the user will choose */
            case SSD_L:
                return GPIO_ReadPortPin(SSD_L_ENABLE_PORT,SSD_L_ENABLE_PIN);
                break;
            case SSD_R:
                return GPIO_ReadPortPin(SSD_R_ENABLE_PORT,SSD_R_ENABLE_PIN);
                break;
            default:
                //shouldn't be here
                break;
        }
    return 0;
}

SSD_symbol SSD_GET_Symbol(tSSD ssd){
    return SSD_symbols[ssd];
}


void SSD_update()
{
        static unsigned int counter = 0;

        SSD_SET_Symbol(SSD_L,counter);
        GPIO_WritePort(SSD_L_DATA_PORT ,symbols[SSD_symbols[SSD_L]]);

        if(counter < 9){
            counter ++;
        }else{
            counter = 0;
        }
}
