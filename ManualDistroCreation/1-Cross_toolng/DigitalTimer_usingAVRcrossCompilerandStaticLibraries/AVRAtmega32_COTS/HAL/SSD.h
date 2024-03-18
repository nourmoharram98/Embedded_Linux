/*
 * SSD.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Nour Moharram
 */

#ifndef HAL_SSD_SSD_H_
#define HAL_SSD_SSD_H_

#include "STD.h"


typedef enum
{
	SSD_OK,
	Error_NumofSSD,
	Error_SSDMode,
	Error_SSDPORT,
	Error_SSD_value,
}SSD_ErrorStates_t;

/**
 * @brief Function used to Initialize seven segments in system
 *
 * @return
 */
SSD_ErrorStates_t SSD_Init(void);

/**
 * @brief Function used to display number on seven segment
 *
 * @param Copy_u8SegName
 * @param value
 * @return
 */
SSD_ErrorStates_t SSD_enuSetValue(u8 Copy_u8SegName,u8 value);

/**
 * @brief function used to display number on more than one seven segment
 *
 * @param Value
 * @return
 */
SSD_ErrorStates_t SSDs_SetValue(u8 value);

#endif /* HAL_SSD_SSD_H_ */
