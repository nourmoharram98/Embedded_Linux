/*
 * SWITCH.h
 *
 *  Created on: Dec 17, 2023
 *      Author: Nour Moharram
 */

#ifndef HAL_SWITCH_SWITCH_H_
#define HAL_SWITCH_SWITCH_H_


typedef enum
{
	Switch_OK,
	Error_NumofSwitches,
	Error_SwitchMode,
	Error_SwitchID
}switch_ErrorStates_t;


/**
 *@brief  : Function to Initialize the switch configurations
 *@param  : void
 *@return : Error State
 */
switch_ErrorStates_t SWITCH_Init(void);


/**
 *@brief  : Function to read the state of switch
 *@param  : switch ID and pointer to address where state will be assigned
 *@return : Error State
 */
switch_ErrorStates_t SWITCH_enuSetSwitchState(u8 Copy_u8SwitchName,u8 *Add_u8State);



#endif /* HAL_SWITCH_SWITCH_H_ */
