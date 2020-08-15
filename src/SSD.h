#include "GPIO_interface.h"

#define SSD_NUMBER (2)

#define SSD_L_DATA_PORT 		PORTA
#define SSD_R_DATA_PORT 		PORTC

#define SSD_L_ENABLE_PORT		PORTB
#define SSD_R_ENABLE_PORT		PORTB

#define SSD_L_ENABLE_PIN		PIN_0
#define SSD_R_ENABLE_PIN		PIN_1

typedef enum {
    SSD_L,
    SSD_R
}tSSD ;

typedef enum {
    SSD_0,
    SSD_1,
    SSD_2,
    SSD_3,
    SSD_4,
    SSD_5,
    SSD_6,
    SSD_7,
    SSD_8,
    SSD_9,
    SSD_NULL
}SSD_symbol;


typedef enum {
    SSD_OFF,
    SSD_ON
} SSD_STATE ;


void SSD_Init(tSSD ssd ,SSD_STATE initial_state , SSD_symbol initial_symbol);

void SSD_SET_Symbol(tSSD ssd ,SSD_symbol symbol);
void SSD_SET_state(tSSD ssd ,SSD_STATE state);

SSD_STATE SSD_GET_state(tSSD ssd);
SSD_symbol SSD_GET_Symbol(tSSD ssd);

void SSD_update(void);
