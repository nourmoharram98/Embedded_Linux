/*
 * DelayFunc.c
 *
 * Created: 11/28/2023 12:34:01 PM
 *  Author: Nour Moharram
 */ 
#include "STD.h"

/*
Function that take time from user in msec
*/
void Delay_ms(u32 Time_in_ms)
{
	u32 i=0,j=0;
	if(Time_in_ms <=0)
	{
		//do nothing
	}
	else
	{
		for(i=0;i<Time_in_ms;i++)
		{
			for(j=0;j<80;j++)
			{
				
			}
		}
	}
}