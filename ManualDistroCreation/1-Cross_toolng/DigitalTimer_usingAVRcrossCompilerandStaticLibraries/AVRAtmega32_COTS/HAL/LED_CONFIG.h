/*
 * LED_CONFIG.h
 *
 * Created: 12/2/2023 4:30:32 PM
 *  Author: Nour Moharram
 */





#ifndef LED_CONFIG_
#define LED_CONFIG_


#include "PORT_CONFIG.h"

typedef enum
{
	LED_NO_ONE,
	LED_NO_TWO,
	LED_NO_THREE,
	LED_NO_FOUR,
	Number_of_Leds,
}Led_ID;

/*
 * Enum for Led connection configuration
 * */
typedef enum
{
	Active_High,
	Active_Low
}Led_Mode;


/*
 * Enum for Led status
 * */
typedef enum
{
	Led_OFF,
	Led_ON
}Led_Status;

/*
 * Enum for Led Error State
 * */
typedef enum
{
	Led_Ok,
	Error_Number_of_Leds,
	Error_Mode_of_Leds,
	Error_Status_of_leds,
	Error_LedID,
	Led_Nok,
}Led_Error_Status;

typedef struct
{
	//Port_PortNumber Led_Port;
	Port_PinNumber Led_Pin;
	Led_Mode Led_config;
	Led_Status LedStatus;
}LED_CONFIGURATIONS;




#endif
