/*
 * LED_CONFIG.c
 *
 * Created: 12/2/2023 4:30:32 PM
 *  Author: Nour Moharram
 */



#include "STD.h"
#include"LED_CONFIG.h"



LED_CONFIGURATIONS ArrOfLeds[Number_of_Leds]={
		[LED_NO_ONE]={PORT_PA0,Active_High,Led_OFF},
		[LED_NO_TWO]={PORT_PA1,Active_High,Led_OFF},
		[LED_NO_THREE]={PORT_PA2,Active_High,Led_OFF},
		[LED_NO_FOUR]={PORT_PA3,Active_High,Led_OFF},
};
