/*
 * LED.h
 *
 * Created: 12/2/2023 4:30:32 PM
 *  Author: Nour Moharram
 */



#ifndef LED_H_
#define LED_H_

#include"LED_CONFIG.h"


/**
 *@brief  : Function to initialize the Leds configuration
 *@param  : void
 *@return : Error State
 */
Led_Error_Status Led_Init(void);


/**
 *@brief  :Function to turn on or turn off a specific led
 *@param  : Led Id, state required (on or off)
 *@return : Error State
 */
Led_Error_Status LED_enuSetLedState(Led_ID Copy_u8LedName, Led_Status Copy_u8State);


/**
 *@brief  :Function to toggle the led state
 *@param  :LED ID
 *@return : Error State
 */
Led_Error_Status LED_enuTogLedState(Led_ID Copy_u8LedName);










#endif
