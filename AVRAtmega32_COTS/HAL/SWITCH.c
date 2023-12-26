/*
 * SWITCH.c
 *
 *  Created on: Dec 17, 2023
 *      Author: Nour Moharram
 */
#include"STD.h"
#include"SWITCH.h"
#include"SWITCH_CONFIG.h"
#include"PORT_CONFIG.h"
#include"PORT.h"
#include"DIO.h"

extern SWITCH_CONFIGURATIONS arrOfSwitches[Number_Of_Switches];


switch_ErrorStates_t SWITCH_Init(void)
{
	switch_ErrorStates_t Error_Status=Switch_OK;

	PORT_CONFIGURATION arrConversion[Number_Of_Switches]={{0}};
	if(Number_Of_Switches<PORT_PA0 || Number_Of_Switches > PORT_PD7)
	{
		Error_Status=Error_NumofSwitches;
	}
	else
	{
		for(u8 Local_counter=0;Local_counter<Number_Of_Switches;Local_counter++)
		{
			if((arrOfSwitches[Local_counter].Switch_Mode != SwitchM_InternalPullUp) && (arrOfSwitches[Local_counter].Switch_Mode != SwitchM_ExternalPullDown))
			{
				Error_Status=Error_SwitchMode;
				break;
			}
			arrConversion[Local_counter].Port_PinDirection=PORT_PINDIR_INPUT;
			arrConversion[Local_counter].PORT_PIN_Number=arrOfSwitches[Local_counter].Switch_Pin;
			if(arrOfSwitches[Local_counter].Switch_Mode==SwitchM_InternalPullUp)
			{
				arrConversion[Local_counter].Port_PinLevelValue=PORT_PIN_LEVEL_HIGH;
			}
			else
			{
				arrConversion[Local_counter].Port_PinLevelValue=PORT_PIN_LEVEL_LOW;
			}
		}
		PORT_vidInit(arrConversion,Number_Of_Switches);

	}



	return Error_Status;
}

switch_ErrorStates_t SWITCH_enuSetSwitchState(u8 Copy_u8SwitchName,u8 *Add_u8State)
{
	switch_ErrorStates_t Error_Status=Switch_OK;
	u8 Port;
	u8 Pin;
	
	if(Copy_u8SwitchName<SWITCH_NUMONE || Copy_u8SwitchName >Number_Of_Switches)
	{
		Error_Status=Error_SwitchID;
	}
	Port=arrOfSwitches[Copy_u8SwitchName].Switch_Pin/8;
	Pin=arrOfSwitches[Copy_u8SwitchName].Switch_Pin%8;
	if(arrOfSwitches[Copy_u8SwitchName].Switch_Mode==SwitchM_InternalPullUp)
	{

		DIO_enumReadState(Port, Pin,Add_u8State);

	}

	return Error_Status;
}
