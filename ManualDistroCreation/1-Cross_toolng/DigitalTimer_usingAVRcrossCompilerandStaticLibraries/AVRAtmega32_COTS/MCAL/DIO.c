/*
 * DIO.c
 *
 * Created: 12/2/2023 4:30:32 PM
 *  Author: Nour Moharram
 */ 



#include "STD.h"
#include "MCU_Registers.h"
#include "BitMath.h"
#include "DIO.h"
#include "PORT_CONFIG.h"


/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Error_Status= DIO_enumOk;
#if(TARGET_IO_PORTS==FOUR_PORTS)
	if(Copy_enumPortNum>DIO_enumPortD || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7 || Copy_enumPinNum < DIO_enumPin0)
	{
		Error_Status = DIO_enumWrongPin;
	}
	else if(Copy_enumLogicState > DIO_enumLogicHigh || Copy_enumLogicState < DIO_enumLogicLow)
	{
		Error_Status = DIO_enumWrongConfig;
	}
	else
	{
		switch(Copy_enumLogicState)
		{
			case DIO_enumLogicHigh:
				switch(Copy_enumPortNum)
				{
					case DIO_enumPortA:
						SET_BIT(PORTA,Copy_enumPinNum);
						break;
					case DIO_enumPortB:
						SET_BIT(PORTB,Copy_enumPinNum);
						break;
					case DIO_enumPortC:
						SET_BIT(PORTC,Copy_enumPinNum);
						break;
					//#if(TARGET_IO_REGISTERS==FOUR_REGISTERS)
					case DIO_enumPortD:
						SET_BIT(PORTD,Copy_enumPinNum);
						break;
					//#endif
					default:
						//no thing 
						break;
				}
				break;
			case DIO_enumLogicLow:
				switch(Copy_enumPortNum)
				{
					case DIO_enumPortA:
						CLR_BIT(PORTA,Copy_enumPinNum);
						break;
					case DIO_enumPortB:
						CLR_BIT(PORTB,Copy_enumPinNum);
						break;
					case DIO_enumPortC:
						CLR_BIT(PORTC,Copy_enumPinNum);
						break;
					case DIO_enumPortD:
						CLR_BIT(PORTD,Copy_enumPinNum);
						break;
					default:
						//do nothing
						break;
				}
				break;
			default:
				//do nothing
				break;
		}
	}
#elif(TARGET_IO_PORTS==THREE_PORTS)
	if(Copy_enumPortNum>DIO_enumPortC || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7 || Copy_enumPinNum < DIO_enumPin0)
	{
		Error_Status = DIO_enumWrongPin;
	}
	else if(Copy_enumLogicState > DIO_enumLogicHigh || Copy_enumLogicState < DIO_enumLogicLow)
	{
		Error_Status = DIO_enumWrongConfig;
	}
	else
	{
		switch(Copy_enumLogicState)
		{
			case DIO_enumLogicHigh:
			switch(Copy_enumPortNum)
			{
				case DIO_enumPortA:
				SET_BIT(PORTA,Copy_enumPinNum);
				break;
				case DIO_enumPortB:
				SET_BIT(PORTB,Copy_enumPinNum);
				break;
				case DIO_enumPortC:
				SET_BIT(PORTC,Copy_enumPinNum);
				break;
				default:
				//no thing
				break;
			}
			break;
			case DIO_enumLogicLow:
			switch(Copy_enumPortNum)
			{
				case DIO_enumPortA:
				CLR_BIT(PORTA,Copy_enumPinNum);
				break;
				case DIO_enumPortB:
				CLR_BIT(PORTB,Copy_enumPinNum);
				break;
				case DIO_enumPortC:
				CLR_BIT(PORTC,Copy_enumPinNum);
				break;
				default:
				//do nothing
				break;
			}
			break;
			default:
			//do nothing
			break;
		}
	}
#elif(TARGET_IO_PORTS==TWO_PORTS)
	if(Copy_enumPortNum>DIO_enumPortB || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7 || Copy_enumPinNum < DIO_enumPin0)
	{
		Error_Status = DIO_enumWrongPin;
	}
	else if(Copy_enumLogicState > DIO_enumLogicHigh || Copy_enumLogicState < DIO_enumLogicLow)
	{
		Error_Status = DIO_enumWrongConfig;
	}
	else
	{
		switch(Copy_enumLogicState)
		{
			case DIO_enumLogicHigh:
			switch(Copy_enumPortNum)
			{
				case DIO_enumPortA:
				SET_BIT(PORTA,Copy_enumPinNum);
				break;
				case DIO_enumPortB:
				SET_BIT(PORTB,Copy_enumPinNum);
				break;
				default:
				//no thing
				break;
			}
			break;
			case DIO_enumLogicLow:
			switch(Copy_enumPortNum)
			{
				case DIO_enumPortA:
				CLR_BIT(PORTA,Copy_enumPinNum);
				break;
				case DIO_enumPortB:
				CLR_BIT(PORTB,Copy_enumPinNum);
				break;
				default:
				//do nothing
				break;
			}
			break;
			default:
			//do nothing
			break;
		}
	}
#elif(TARGET_IO_PORTS==ONE_PORT)
	if(Copy_enumPortNum>DIO_enumPortA || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7 || Copy_enumPinNum < DIO_enumPin0)
	{
		Error_Status = DIO_enumWrongPin;
	}
	else if(Copy_enumLogicState > DIO_enumLogicHigh || Copy_enumLogicState < DIO_enumLogicLow)
	{
		Error_Status = DIO_enumWrongConfig;
	}
	else
	{
		switch(Copy_enumLogicState)
		{
			case DIO_enumLogicHigh:
			switch(Copy_enumPortNum)
			{
				case DIO_enumPortA:
				SET_BIT(PORTA,Copy_enumPinNum);
				break;
				default:
				//no thing
				break;
			}
			break;
			case DIO_enumLogicLow:
			switch(Copy_enumPortNum)
			{
				case DIO_enumPortA:
				CLR_BIT(PORTA,Copy_enumPinNum);
				break;
				default:
				//do nothing
				break;
			}
			break;
			default:
			//do nothing
			break;
		}
	}
#endif
	return Error_Status;
}

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Error_Status= DIO_enumOk;
#if(TARGET_IO_PORTS==FOUR_PORTS)
	if(Copy_enumPortNum>DIO_enumPortD || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumLogicState > DIO_enumLogicHigh || Copy_enumLogicState < DIO_enumLogicLow)
	{
		Error_Status = DIO_enumWrongConfig;
	}
	else
	{
		switch(Copy_enumLogicState)
		{
			case DIO_enumLogicHigh:
				switch(Copy_enumPortNum)
				{
					case DIO_enumPortA:
						PORTA=REG_HIGH;
						break;
					case DIO_enumPortB:
						PORTB=REG_HIGH;
						break;
					case DIO_enumPortC:
						PORTC=REG_HIGH;
						break;
					case DIO_enumPortD:
						PORTD=REG_HIGH;
						break;
					default:
						//do nothing
						break;
				}
				break;
			case DIO_enumLogicLow:
				switch(Copy_enumPortNum)
				{
					case DIO_enumPortA:
						PORTA= REG_LOW;
						break;
					case DIO_enumPortB:
						PORTB= REG_LOW;
						break;
					case DIO_enumPortC:
						PORTC= REG_LOW;
						break;
					case DIO_enumPortD:
						PORTD= REG_LOW;
						break;
					default:
						//do nothing
						break;
				}
				break;
			default:
				//do nothing
			break;
		}
	}
#elif(TARGET_IO_PORTS==THREE_PORTS)
	if(Copy_enumPortNum>DIO_enumPortC || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumLogicState > DIO_enumLogicHigh || Copy_enumLogicState < DIO_enumLogicLow)
	{
		Error_Status = DIO_enumWrongConfig;
	}
	else
	{
		switch(Copy_enumLogicState)
		{
			case DIO_enumLogicHigh:
			switch(Copy_enumPortNum)
			{
				case DIO_enumPortA:
				PORTA=REG_HIGH;
				break;
				case DIO_enumPortB:
				PORTB=REG_HIGH;
				break;
				case DIO_enumPortC:
				PORTC=REG_HIGH;
				break;
				default:
				//do nothing
				break;
			}
			break;
			case DIO_enumLogicLow:
			switch(Copy_enumPortNum)
			{
				case DIO_enumPortA:
				PORTA= REG_LOW;
				break;
				case DIO_enumPortB:
				PORTB= REG_LOW;
				break;
				case DIO_enumPortC:
				PORTC= REG_LOW;
				break;
				default:
				//do nothing
				break;
			}
			break;
			default:
			//do nothing
			break;
		}
	}
#elif(TARGET_IO_PORTS==TWO_PORTS)
	if(Copy_enumPortNum>DIO_enumPortB || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumLogicState > DIO_enumLogicHigh || Copy_enumLogicState < DIO_enumLogicLow)
	{
		Error_Status = DIO_enumWrongConfig;
	}
	else
	{
		switch(Copy_enumLogicState)
		{
			case DIO_enumLogicHigh:
			switch(Copy_enumPortNum)
			{
				case DIO_enumPortA:
				PORTA=REG_HIGH;
				break;
				case DIO_enumPortB:
				PORTB=REG_HIGH;
				break;
				default:
				//do nothing
				break;
			}
			break;
			case DIO_enumLogicLow:
			switch(Copy_enumPortNum)
			{
				case DIO_enumPortA:
				PORTA= REG_LOW;
				break;
				case DIO_enumPortB:
				PORTB= REG_LOW;
				break;
				default:
				//do nothing
				break;
			}
			break;
			default:
			//do nothing
			break;
		}
	}
#elif(TARGET_IO_PORTS==ONE_PORT)
	if(Copy_enumPortNum>DIO_enumPortA || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumLogicState > DIO_enumLogicHigh || Copy_enumLogicState < DIO_enumLogicLow)
	{
		Error_Status = DIO_enumWrongConfig;
	}
	else
	{
		switch(Copy_enumLogicState)
		{
			case DIO_enumLogicHigh:
			switch(Copy_enumPortNum)
			{
				case DIO_enumPortA:
				PORTA=REG_HIGH;
				break;
				default:
				//do nothing
				break;
			}
			break;
			case DIO_enumLogicLow:
			switch(Copy_enumPortNum)
			{
				case DIO_enumPortA:
				PORTA= REG_LOW;
				break;
				default:
				//do nothing
				break;
			}
			break;
			default:
			//do nothing
			break;
		}
	}
#endif
	return Error_Status;
}


/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,u8* Add_Pu8PinValue)
{
	DIO_enumError_t Error_Status= DIO_enumOk;
#if(TARGET_IO_PORTS==FOUR_PORTS)
	if(Copy_enumPortNum>DIO_enumPortD || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7 || Copy_enumPinNum < DIO_enumPin0)
	{
		Error_Status = DIO_enumWrongPin;
	}
	else if(Add_Pu8PinValue == NULL)
	{
		Error_Status= DIO_enumNullPointer;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
				*Add_Pu8PinValue=READ_BIT(PINA,Copy_enumPinNum); 
				break;
			case DIO_enumPortB:
				*Add_Pu8PinValue=READ_BIT(PINB,Copy_enumPinNum);
				break;
			case DIO_enumPortC:
				*Add_Pu8PinValue=READ_BIT(PINC,Copy_enumPinNum);
				break;
			case DIO_enumPortD:
				*Add_Pu8PinValue=READ_BIT(PIND,Copy_enumPinNum);
				break;
			default:
				//do nothing
				break;
		}
	}
#elif(TARGET_IO_PORTS==THREE_PORTS)
	if(Copy_enumPortNum>DIO_enumPortC || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7 || Copy_enumPinNum < DIO_enumPin0)
	{
		Error_Status = DIO_enumWrongPin;
	}
	else if(Add_Pu8PinValue == NULL)
	{
		Error_Status= DIO_enumNullPointer;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			*Add_Pu8PinValue=READ_BIT(PINA,Copy_enumPinNum);
			break;
			case DIO_enumPortB:
			*Add_Pu8PinValue=READ_BIT(PINB,Copy_enumPinNum);
			break;
			case DIO_enumPortC:
			*Add_Pu8PinValue=READ_BIT(PINC,Copy_enumPinNum);
			break;
			default:
			//do nothing
			break;
		}
	}
#elif(TARGET_IO_PORTS==TWO_PORTS)
	if(Copy_enumPortNum>DIO_enumPortB || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7 || Copy_enumPinNum < DIO_enumPin0)
	{
		Error_Status = DIO_enumWrongPin;
	}
	else if(Add_Pu8PinValue == NULL)
	{
		Error_Status= DIO_enumNullPointer;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			*Add_Pu8PinValue=READ_BIT(PINA,Copy_enumPinNum);
			break;
			case DIO_enumPortB:
			*Add_Pu8PinValue=READ_BIT(PINB,Copy_enumPinNum);
			break;
			default:
			//do nothing
			break;
		}
	}
#elif(TARGET_IO_PORTS==ONE_PORT)
	if(Copy_enumPortNum>DIO_enumPortA || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7 || Copy_enumPinNum < DIO_enumPin0)
	{
		Error_Status = DIO_enumWrongPin;
	}
	else if(Add_Pu8PinValue == NULL)
	{
		Error_Status= DIO_enumNullPointer;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			*Add_Pu8PinValue=READ_BIT(PINA,Copy_enumPinNum);
			break;
			default:
			//do nothing
			break;
		}
	}
#endif

	return Error_Status;
}


/**
 *@brief  : Function to toggle the logic state of the pin.
 *@param  : Port Number & Pin Number.
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumTogglePinState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum)
{
	DIO_enumError_t Error_Status= DIO_enumOk;
#if(TARGET_IO_PORTS==FOUR_PORTS)
	if(Copy_enumPortNum>DIO_enumPortD || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7 || Copy_enumPinNum < DIO_enumPin0)
	{
		Error_Status = DIO_enumWrongPin;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
				TOG_BIT(PORTA,Copy_enumPinNum);
				break;
			case DIO_enumPortB:
				TOG_BIT(PORTB,Copy_enumPinNum);
				break;
			case DIO_enumPortC:
				TOG_BIT(PORTC,Copy_enumPinNum);
				break;
			case DIO_enumPortD:
				TOG_BIT(PORTD,Copy_enumPinNum);
				break;
			default:
				//do nothing
				break;
		}
	}
#elif(TARGET_IO_PORTS==THREE_PORTS)
	if(Copy_enumPortNum>DIO_enumPortC || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7 || Copy_enumPinNum < DIO_enumPin0)
	{
		Error_Status = DIO_enumWrongPin;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			TOG_BIT(PORTA,Copy_enumPinNum);
			break;
			case DIO_enumPortB:
			TOG_BIT(PORTB,Copy_enumPinNum);
			break;
			case DIO_enumPortC:
			TOG_BIT(PORTC,Copy_enumPinNum);
			break;
			default:
			//do nothing
			break;
		}
	}
#elif(TARGET_IO_PORTS==TWO_PORTS)
	if(Copy_enumPortNum>DIO_enumPortB || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7 || Copy_enumPinNum < DIO_enumPin0)
	{
		Error_Status = DIO_enumWrongPin;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			TOG_BIT(PORTA,Copy_enumPinNum);
			break;
			case DIO_enumPortB:
			TOG_BIT(PORTB,Copy_enumPinNum);
			break;
			default:
			//do nothing
			break;
		}
	}
#elif(TARGET_IO_PORTS==ONE_PORT)
	if(Copy_enumPortNum>DIO_enumPortA || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7 || Copy_enumPinNum < DIO_enumPin0)
	{
		Error_Status = DIO_enumWrongPin;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			TOG_BIT(PORTA,Copy_enumPinNum);
			break;
			default:
			//do nothing
			break;
		}
	}
#endif
	return Error_Status;

}

DIO_enumError_t DIO_enumAssignPortLogicalStatus(DIO_enumPorts_t Copy_enumPortNum, u8 LogicalValueOfPins)
{
	DIO_enumError_t Error_Status= DIO_enumNOk;
#if(TARGET_IO_PORTS==FOUR_PORTS)
	if(Copy_enumPortNum>DIO_enumPortD || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(LogicalValueOfPins < REG_LOW || LogicalValueOfPins > REG_HIGH)
	{
		Error_Status= DIO_enumLogicalValueError;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
				PORTA=LogicalValueOfPins;
			break;
			case DIO_enumPortB:
				PORTB=LogicalValueOfPins;
			break;
			case DIO_enumPortC:
				PORTC=LogicalValueOfPins;
			break;
			case DIO_enumPortD:
				PORTD=LogicalValueOfPins;
			break;
			default:
			//do nothing
			break;
		}
		Error_Status = DIO_enumOk;
	}
#elif(TARGET_IO_PORTS==THREE_PORTS)
	if(Copy_enumPortNum>DIO_enumPortC || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(LogicalValueOfPins < REG_LOW || LogicalValueOfPins > REG_HIGH)
	{
		Error_Status= DIO_enumLogicalValueError;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			PORTA=LogicalValueOfPins;
			break;
			case DIO_enumPortB:
			PORTB=LogicalValueOfPins;
			break;
			case DIO_enumPortC:
			PORTC=LogicalValueOfPins;
			break;
			default:
			//do nothing
			break;
		}
		Error_Status = DIO_enumOk;
	}
#elif(TARGET_IO_PORTS==TWO_PORTS)
	if(Copy_enumPortNum>DIO_enumPortB || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(LogicalValueOfPins < REG_LOW || LogicalValueOfPins > REG_HIGH)
	{
		Error_Status= DIO_enumLogicalValueError;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			PORTA=LogicalValueOfPins;
			break;
			case DIO_enumPortB:
			PORTB=LogicalValueOfPins;
			break;
			default:
			//do nothing
			break;
		}
		Error_Status = DIO_enumOk;
	}
#elif(TARGET_IO_PORTS==ONE_PORT)
	if(Copy_enumPortNum>DIO_enumPortA || Copy_enumPortNum < DIO_enumPortA)
	{
		Error_Status= DIO_enumWrongPort;
	}
	else if(LogicalValueOfPins < REG_LOW || LogicalValueOfPins > REG_HIGH)
	{
		Error_Status= DIO_enumLogicalValueError;
	}
	else
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			PORTA=LogicalValueOfPins;
			break;
			default:
			//do nothing
			break;
		}
		Error_Status = DIO_enumOk;
	}
#endif
	return Error_Status;
}
