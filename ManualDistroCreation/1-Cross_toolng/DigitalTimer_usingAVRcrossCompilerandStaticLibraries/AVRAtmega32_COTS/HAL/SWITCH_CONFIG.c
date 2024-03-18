/*
 * SWITCH_CONFIG.c
 *
 *  Created on: Dec 17, 2023
 *      Author: Dell
 */

#include"SWITCH_CONFIG.h"


SWITCH_CONFIGURATIONS arrOfSwitches[Number_Of_Switches]={
		[SWITCH_NUMONE]={PORT_PB0,SwitchM_InternalPullUp},
		[SWITCH_NUMTWO]={PORT_PB1,SwitchM_InternalPullUp},
		[SWITCH_NUMTHREE]={PORT_PB2,SwitchM_InternalPullUp}
};


