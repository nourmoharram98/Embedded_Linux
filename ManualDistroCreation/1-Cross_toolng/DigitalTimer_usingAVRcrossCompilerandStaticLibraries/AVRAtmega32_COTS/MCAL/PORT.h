/*
 * PORT.h
 *
 * Created: 12/2/2023 4:29:33 PM
 *  Author: Dell
 */ 


#ifndef PORT_H_
#define PORT_H_

#include"PORT_CONFIG.h"
/**
 *@brief  : Function to configure MC pins
 *@param  : void
 *@return : void                                               
 */	
//void PORT_vidInit(void);

void PORT_vidInit(PORT_CONFIGURATION *ptrtoarrOfConfigs, u8 array_size);


#endif /* PORT_H_ */
