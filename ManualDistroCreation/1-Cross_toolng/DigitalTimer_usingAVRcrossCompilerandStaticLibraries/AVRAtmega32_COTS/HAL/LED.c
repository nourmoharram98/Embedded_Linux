/*
 * LED.c
 *
 * Created: 12/2/2023 4:30:32 PM
 *  Author: Nour Moharram
 */



#include"STD.h"
#include"LED.h"
#include"LED_CONFIG.h"
#include"PORT.h"
#include"DIO.h"

//static PORT_CONFIGURATION arrLedConversion[Number_of_Leds]={0};

extern LED_CONFIGURATIONS ArrOfLeds[Number_of_Leds];



Led_Error_Status Led_Init(void)
{
	Led_Error_Status Error_status=Led_Ok;
	PORT_CONFIGURATION arrLedConversion[Number_of_Leds]={{0}}; //local array
	if(Number_of_Leds< PORT_PA0 || Number_of_Leds > PORT_PD7)
	{
		Error_status=Error_Number_of_Leds;
	}
	else
	{
		for(u8 local_counter=0;local_counter<Number_of_Leds;local_counter++)
		{
			if((ArrOfLeds[local_counter].Led_config != Active_High) && (ArrOfLeds[local_counter].Led_config != Active_Low))
			{
				Error_status=Error_Mode_of_Leds;
				if(Error_status != Led_Ok)
				{
					break;
				}
			}
			else if(ArrOfLeds[local_counter].LedStatus != Led_ON && ArrOfLeds[local_counter].LedStatus != Led_OFF)
			{
				Error_status=Error_Status_of_leds;
				if(Error_status != Led_Ok)
				{
					break;
				}
			}
			else
			{
				arrLedConversion[local_counter].Port_PinDirection=PORT_PINDIR_OUTPUT;
				arrLedConversion[local_counter].PORT_PIN_Number=ArrOfLeds[local_counter].Led_Pin;
				switch(ArrOfLeds[local_counter].Led_config)
				{
				case Active_High:
					if(ArrOfLeds[local_counter].LedStatus==Led_ON)
					{
						arrLedConversion[local_counter].Port_PinLevelValue=PORT_PIN_LEVEL_HIGH;
					}
					else
					{
						arrLedConversion[local_counter].Port_PinLevelValue=PORT_PIN_LEVEL_LOW;
					}
					break;
				case Active_Low:
					if(ArrOfLeds[local_counter].LedStatus==Led_ON)
					{
						arrLedConversion[local_counter].Port_PinLevelValue=PORT_PIN_LEVEL_LOW;
					}
					else
					{
						arrLedConversion[local_counter].Port_PinLevelValue=PORT_PIN_LEVEL_HIGH;
					}
					break;
				}
			}
		}
		PORT_vidInit(arrLedConversion,Number_of_Leds);

	}


	return Error_status;
}


Led_Error_Status LED_enuSetLedState(Led_ID Copy_u8LedName, Led_Status Copy_u8State)
{
	u8 Port=0;
	u8 Pin=0;
	Led_Error_Status Error_status=Led_Ok;
	if(Copy_u8LedName<LED_NO_ONE || Copy_u8LedName >Number_of_Leds)
	{
		Error_status=Error_LedID;
	}
	else if(Copy_u8State != Led_ON && Copy_u8State != Led_OFF)
	{
		Error_status=Error_Status_of_leds;
	}
	else
	{
		Port=ArrOfLeds[Copy_u8LedName].Led_Pin/8;
		Pin=ArrOfLeds[Copy_u8LedName].Led_Pin%8;
		DIO_enumSetPin(Port,Pin,Copy_u8State);
	}

	return Error_status;
}

Led_Error_Status LED_enuTogLedState(Led_ID Copy_u8LedName)
{
	u8 Port=0;
	u8 Pin=0;
	Led_Error_Status Error_status=Led_Ok;
	if(Copy_u8LedName<LED_NO_ONE || Copy_u8LedName >Number_of_Leds)
	{
		Error_status=Error_LedID;
	}
	else
	{
		Port=ArrOfLeds[Copy_u8LedName].Led_Pin/8;
		Pin=ArrOfLeds[Copy_u8LedName].Led_Pin%8;
		DIO_enumTogglePinState(Port,Pin);
	}

	return Error_status;
}
