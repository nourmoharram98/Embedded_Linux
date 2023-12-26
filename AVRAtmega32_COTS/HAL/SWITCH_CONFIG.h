/*
 * SWITCH_CONFIG.h
 *
 *  Created on: Dec 17, 2023
 *      Author: Nour Moharram
 */

#ifndef HAL_SWITCH_SWITCH_CONFIG_H_
#define HAL_SWITCH_SWITCH_CONFIG_H_

#include"PORT_CONFIG.h"

typedef enum
{
	SWITCH_NUMONE,
	SWITCH_NUMTWO,
	SWITCH_NUMTHREE,
	Number_Of_Switches
}switch_IDs_t;

typedef enum
{
	Switch_Pressed_InternalPU,
	Switch_Released_InternalPU,
}Switch_stateInternalPU_t;


typedef enum
{
	Switch_Released_ExternalPD,
	Switch_Pressed_ExternalPD,
}Switch_stateExternalPD_t;

typedef enum
{
	SwitchM_InternalPullUp,
	SwitchM_ExternalPullDown
}switch_ModeType_t;

typedef struct
{
	Port_PinNumber Switch_Pin;
	switch_ModeType_t Switch_Mode;
}SWITCH_CONFIGURATIONS;

#endif /* HAL_SWITCH_SWITCH_CONFIG_H_ */
