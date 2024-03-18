/*
 * APP.c
 *
 *  Created on: Dec 19, 2023
 *      Author: Nour Moharram
 */
/*
 * main.c
 *
 *  Created on: Dec 19, 2023
 *      Author: Nour Moharram
 */
#include "STD.h"
#include "APP.h"
#include "LED.h"
#include "SWITCH.h"
#include "SSD.h"
#include "SSD_CONFIG.h"
#include "SWITCH_CONFIG.h"
#include "LED_CONFIG.h"
//#include <util/delay.h>

u8 Global_Timer_value=START_OF_NUMBERS;

u8 Switch_one_status=3;
u8 Switch_two_status=3;
u8 Switch_three_status=3;

u8 Local_PreviousState1;


u8 Local_PreviousState2;


u8 Local_PreviousState3;


u8 digit=0;

u8 tens=0;
void APP_Init(void)
{
	Led_Init();
	SWITCH_Init();
	SSD_Init();
	SSDs_SetValue(START_OF_NUMBERS);

}

void APP_Start(void)
{
	SWITCH_enuSetSwitchState(SWITCH_NUMONE,&Switch_one_status);
	SWITCH_enuSetSwitchState(SWITCH_NUMTWO,&Switch_two_status);
	SWITCH_enuSetSwitchState(SWITCH_NUMTHREE,&Switch_three_status);

	Delay_ms(50);

	if(Switch_one_status==Switch_Pressed_InternalPU)
	{
		Local_PreviousState1 = Switch_one_status;

		SWITCH_enuSetSwitchState(SWITCH_NUMONE,&Switch_one_status);
		if (Switch_one_status == Switch_Released_InternalPU && Local_PreviousState1 == Switch_Pressed_InternalPU)
		{
			Increment_Timer();
			Local_PreviousState1=Switch_Released_InternalPU;

		}

	}
	else if(Switch_two_status==Switch_Pressed_InternalPU)
	{
		Local_PreviousState2 = Switch_two_status;
		SWITCH_enuSetSwitchState(SWITCH_NUMTWO,&Switch_two_status);
		if (Switch_two_status == Switch_Released_InternalPU && Local_PreviousState2 == Switch_Pressed_InternalPU)
		{
			Decrement_Timer();
			Local_PreviousState2=Switch_Released_InternalPU;

		}
	}
	else if(Switch_three_status==Switch_Pressed_InternalPU)
	{
		Local_PreviousState3 = Switch_three_status;
		SWITCH_enuSetSwitchState(SWITCH_NUMTHREE,&Switch_three_status);
		if (Switch_three_status == Switch_Released_InternalPU && Local_PreviousState3 == Switch_Pressed_InternalPU)
		{
			Count_Down();
			Local_PreviousState3=Switch_Released_InternalPU;

		}

	}



}

void Increment_Timer(void)
{
	if(Global_Timer_value==END_OF_NUMBERS)
	{
		Global_Timer_value=START_OF_NUMBERS;
		SSDs_SetValue(Global_Timer_value);
		LED_enuSetLedState(LED_NO_ONE,Led_ON);
	}
	else
	{
		LED_enuSetLedState(LED_NO_ONE,Led_OFF);
	    SSDs_SetValue(++Global_Timer_value);
	}
}

void Decrement_Timer(void)
{
	if(Global_Timer_value==START_OF_NUMBERS)
	{
		Global_Timer_value=END_OF_NUMBERS;
		LED_enuSetLedState(LED_NO_ONE,Led_OFF);
		SSDs_SetValue(Global_Timer_value);
	}
	else
	{
	    SSDs_SetValue(--Global_Timer_value);
	    if(Global_Timer_value==START_OF_NUMBERS)
		{
			LED_enuSetLedState(LED_NO_ONE,Led_ON);
		}
	}


}
int Count_Down(void)
{
	LED_enuSetLedState(LED_NO_ONE,Led_OFF);
	for(u8 local_counter=Global_Timer_value;local_counter>=START_OF_NUMBERS;local_counter--)
	{
		Global_Timer_value=local_counter;
		SSDs_SetValue(Global_Timer_value);
		Delay_ms(3000);
		//_delay_ms(1000);
		SWITCH_enuSetSwitchState(SWITCH_NUMONE, &Switch_one_status);
		SWITCH_enuSetSwitchState(SWITCH_NUMTWO, &Switch_two_status);
		SWITCH_enuSetSwitchState(SWITCH_NUMTHREE, &Switch_three_status);

		if (Switch_one_status == Switch_Pressed_InternalPU || Switch_two_status == Switch_Pressed_InternalPU || Switch_three_status == Switch_Pressed_InternalPU)
		{
			return 0;
		}
		if(local_counter==0)
		{
			LED_enuSetLedState(LED_NO_ONE,Led_ON);
			break;
		}
	}

	return 0;
}

