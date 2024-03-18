/*
 * PORT.c
 *
 * Created: 12/2/2023 4:29:08 PM
 *  Author: Nour Moharram
 */ 

#include "STD.h"
#include "MCU_Registers.h"
#include "PORT_CONFIG.h"
#include "PORT.h"
#include "BitMath.h"


/*concatenate function for PRE-compile process*/
#define CONCAT(pin7,pin6,pin5,pin4,pin3,pin2,pin1,pin0)             CONCAT_Helper(pin7,pin6,pin5,pin4,pin3,pin2,pin1,pin0)
#define CONCAT_Helper(pin7,pin6,pin5,pin4,pin3,pin2,pin1,pin0)		0b##pin7##pin6##pin5##pin4##pin3##pin2##pin1##pin0 

/*
#if (COMPILATION_MODE==POSTCOMPILE)
	extern PORT_CONFIGURATION PORT_ARRAY_CONFIGURATIONS[PORT_PIN_CONFIGURATIONS_SIZE];
#endif
*/
/**
 *@brief  : Function to configure MC pins
 *@param  : void
 *@return : void                                               
 */	


void PORT_vidInit(PORT_CONFIGURATION *ptrtoarrOfConfigs, u8 array_size)
{
	/*WRITE CODE HERE*/
	u8 PORT_NUMBER;
	u8 PIN_NUMBER;
	for(u8 i=0;i<array_size;i++)
	{
		PORT_NUMBER=ptrtoarrOfConfigs[i].PORT_PIN_Number/8;
		PIN_NUMBER=ptrtoarrOfConfigs[i].PORT_PIN_Number%8;
		switch(PORT_NUMBER)
		{
			case PORT_PORTA:
				switch(ptrtoarrOfConfigs[i].Port_PinDirection)
				{
					case PORT_PINDIR_OUTPUT:
					SET_BIT(DDRA,PIN_NUMBER);
					break;
					case PORT_PINDIR_INPUT:
					CLR_BIT(DDRA,PIN_NUMBER);
					break;
					default:
					break;
				}
				switch(ptrtoarrOfConfigs[i].Port_PinLevelValue)
				{
					case PORT_PIN_LEVEL_LOW:
					CLR_BIT(PORTA,PIN_NUMBER);
					break;
					case PORT_PIN_LEVEL_HIGH:
					SET_BIT(PORTA,PIN_NUMBER);
					break;
					default:
					break;
				}
			break;
			case PORT_PORTB:
				switch(ptrtoarrOfConfigs[i].Port_PinDirection)
				{
					case PORT_PINDIR_OUTPUT:
					SET_BIT(DDRB,PIN_NUMBER);
					break;
					case PORT_PINDIR_INPUT:
					CLR_BIT(DDRB,PIN_NUMBER);
					break;
					default:
					break;
				}
				switch(ptrtoarrOfConfigs[i].Port_PinLevelValue)
				{
					case PORT_PIN_LEVEL_LOW:
					CLR_BIT(PORTB,PIN_NUMBER);
					break;
					case PORT_PIN_LEVEL_HIGH:
					SET_BIT(PORTB,PIN_NUMBER);
					break;
					default:
					break;
				}
			break;
			case PORT_PORTC:
				switch(ptrtoarrOfConfigs[i].Port_PinDirection)
				{
					case PORT_PINDIR_OUTPUT:
					SET_BIT(DDRC,PIN_NUMBER);
					break;
					case PORT_PINDIR_INPUT:
					CLR_BIT(DDRC,PIN_NUMBER);
					break;
					default:
					break;
				}
				switch(ptrtoarrOfConfigs[i].Port_PinLevelValue)
				{
					case PORT_PIN_LEVEL_LOW:
					CLR_BIT(PORTC,PIN_NUMBER);
					break;
					case PORT_PIN_LEVEL_HIGH:
					SET_BIT(PORTC,PIN_NUMBER);
					break;
					default:
					break;
				}
			break;
			case PORT_PORTD:
				switch(ptrtoarrOfConfigs[i].Port_PinDirection)
				{
					case PORT_PINDIR_OUTPUT:
					SET_BIT(DDRD,PIN_NUMBER);
					break;
					case PORT_PINDIR_INPUT:
					CLR_BIT(DDRD,PIN_NUMBER);
					break;
					default:
					break;
				}
				switch(ptrtoarrOfConfigs[i].Port_PinLevelValue)
				{
					case PORT_PIN_LEVEL_LOW:
					CLR_BIT(PORTD,PIN_NUMBER);
					break;
					case PORT_PIN_LEVEL_HIGH:
					SET_BIT(PORTD,PIN_NUMBER);
					break;
					default:
					break;
				}
			break;
			default:
			break;
		}
	}
}
