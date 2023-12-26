/*
 * SSD.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Nour Moharram
 */
#include "SSD.h"
#include "SSD_CONFIG.h"
#include "PORT_CONFIG.h"
#include "PORT.h"
#include "DIO.h"

extern SSD_CONFIGURATIONS arrOfSSD[Number_Of_SSD];

u8 Seven_Segment_arr[Size_Of_arrofnumbers]={
		0x3F,					// value of decimal '0'
		0x06,					// value of decimal '1'
		0x5B,					// value of decimal '2'
		0x4F,					// value of decimal '3'
		0x66,					// value of decimal '4'
		0x6D,					// value of decimal '5'
		0x7D,					// value of decimal '6'
		0x07,					// value of decimal '7'
		0x7F,					// value of decimal '8'
		0x6F					// value of decimal '9'
};

SSD_ErrorStates_t SSD_Init(void)
{
	SSD_ErrorStates_t Error_status=SSD_OK;
/*check for the number of available SSegments and the required pins for their connection*/
#if(NUMBER_OF_SSD==1)
	PORT_CONFIGURATION arrConversion[ONE_SSD_PINS]={{0}};
	u8 Length_of_arrconversion=ONE_SSD_PINS;
	#define OFFSETA		0
	#define OFFSETB		0
	#define OFFSETC		0
	#define OFFSETD		0

#elif(NUMBER_OF_SSD==2)
	PORT_CONFIGURATION arrConversion[TWO_SSD_PINS]={{0}};
	u8 Length_of_arrconversion=TWO_SSD_PINS;
	#define OFFSETA		0
	#define OFFSETB		1
	#define OFFSETC		16
	#define OFFSETD		17
#elif(NUMBER_OF_SSD==3)
	PORT_CONFIGURATION arrConversion[THREE_SSD_PINS]={{0}};
	u8 Length_of_arrconversion=THREE_SSD_PINS;
#endif
/*Check the configurations of the SSegments*/
	if(Number_Of_SSD < NO_SSD || Number_Of_SSD > MAXIMUM_NO_OF_SSD)
	{
		Error_status=Error_NumofSSD;
	}
	else
	{
		/*Loop over the seven segments to configure them*/
		for(u8 local_counter=0;local_counter<Number_Of_SSD;local_counter++)
		{
			if((arrOfSSD[local_counter].SSD_MODE != Common_Anode) && (arrOfSSD[local_counter].SSD_MODE != Common_Cathode))
			{
				Error_status=Error_SSDMode;
				break;
			}
			else if(arrOfSSD[local_counter].SSD_PORT < SSD_PORTA || arrOfSSD[local_counter].SSD_PORT > SSD_PORTD)
			{
				Error_status=Error_SSDPORT;
				break;
			}
			else
			{
				/*Start of initialization Algorethim*/
				switch(arrOfSSD[local_counter].SSD_PORT)
				{
				case SSD_PORTA:
					for(u8 i=START_OF_PORTA;i<END_OF_PORTA;i++)
					{
						arrConversion[i].PORT_PIN_Number=i;
						arrConversion[i].Port_PinDirection=PORT_PINDIR_OUTPUT;
						arrConversion[i].Port_PinLevelValue=PORT_PIN_LEVEL_LOW;
					}
				break;
				case SSD_PORTB:
					for(u8 i=START_OF_PORTB;i<END_OF_PORTB;i++)
					{
						arrConversion[i-OFFSETB].PORT_PIN_Number=i;
						arrConversion[i-OFFSETB].Port_PinDirection=PORT_PINDIR_OUTPUT;
						arrConversion[i-OFFSETB].Port_PinLevelValue=PORT_PIN_LEVEL_LOW;
					}
				break;
				case SSD_PORTC:
					for(u8 i=START_OF_PORTC;i<END_OF_PORTC;i++)
					{
						arrConversion[i-OFFSETC].PORT_PIN_Number=i;
						arrConversion[i-OFFSETC].Port_PinDirection=PORT_PINDIR_OUTPUT;
						arrConversion[i-OFFSETC].Port_PinLevelValue=PORT_PIN_LEVEL_LOW;
					}
				break;
				case SSD_PORTD:
					for(u8 i=START_OF_PORTD;i<END_OF_PORTD;i++)
					{
						arrConversion[i-OFFSETD].PORT_PIN_Number=i;
						arrConversion[i-OFFSETD].Port_PinDirection=PORT_PINDIR_OUTPUT;
						arrConversion[i-OFFSETD].Port_PinLevelValue=PORT_PIN_LEVEL_LOW;
					}
				break;
				default:
				break;
				}
			}
		}
			PORT_vidInit(arrConversion,Length_of_arrconversion);

		}

	return Error_status;
}

SSD_ErrorStates_t SSD_enuSetValue(u8 Copy_u8SegName,u8 value)
{
	SSD_ErrorStates_t Error_status=SSD_OK;
	u8 binary_value=0;
	if(Copy_u8SegName<NO_SSD || Copy_u8SegName > Number_Of_SSD)
	{
		Error_status=Error_NumofSSD;
	}
	else if(value<START_OF_NUMBERS || value > END_OF_NUMBERS)
	{
		Error_status=Error_SSD_value;
	}
	else
	{
		switch(arrOfSSD[Copy_u8SegName].SSD_MODE)
		{
		case Common_Anode:
			binary_value=~(Seven_Segment_arr[value]);
			DIO_enumAssignPortLogicalStatus(arrOfSSD[Copy_u8SegName].SSD_PORT,binary_value);
		break;
		case Common_Cathode:
			binary_value=Seven_Segment_arr[value];

			DIO_enumAssignPortLogicalStatus(arrOfSSD[Copy_u8SegName].SSD_PORT,binary_value);
		break;
		default:
		break;
		}
	}

	return Error_status;
}

SSD_ErrorStates_t SSDs_SetValue(u8 value)
{
	SSD_ErrorStates_t Error_status=SSD_OK;
	u8 binary_value=0;
	u8 digit=0;
	u8 tens=0;
	if(value<START_OF_NUMBERS || value > END_OF_NUMBERS)
	{
		Error_status=Error_SSD_value;
	}
	else
	{
		digit=value%10;
		tens=value/10;
		for(u8 Local_counter=0;Local_counter<Number_Of_SSD;Local_counter++)
		{
			if(Local_counter==SSD_ONE)
			{
				switch(arrOfSSD[Local_counter].SSD_MODE)
				{
				case Common_Anode:
					binary_value=~(Seven_Segment_arr[tens]);
					DIO_enumAssignPortLogicalStatus(arrOfSSD[Local_counter].SSD_PORT,~Seven_Segment_arr[tens]);
				break;
				case Common_Cathode:
					binary_value=Seven_Segment_arr[tens];

					DIO_enumAssignPortLogicalStatus(arrOfSSD[Local_counter].SSD_PORT,Seven_Segment_arr[tens]);
				break;
				default:
				break;
				}
			}
			else if(Local_counter==SSD_TWO)
			{
				switch(arrOfSSD[Local_counter].SSD_MODE)
				{
				case Common_Anode:
					binary_value=~(Seven_Segment_arr[digit]);
					DIO_enumAssignPortLogicalStatus(arrOfSSD[Local_counter].SSD_PORT,~Seven_Segment_arr[digit]);
				break;
				case Common_Cathode:
					binary_value=Seven_Segment_arr[digit];

					DIO_enumAssignPortLogicalStatus(arrOfSSD[Local_counter].SSD_PORT,Seven_Segment_arr[digit]);
				break;
				default:
				break;
				}
			}


		}
	}
	return Error_status;
}

