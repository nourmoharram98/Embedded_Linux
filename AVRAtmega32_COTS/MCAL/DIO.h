/*
 * DIO.h
 *
 * Created: 12/2/2023 4:30:05 PM
 *  Author: Nour Moharram
 */ 


#ifndef DIO_H_
#define DIO_H_


/*Include here Your Standard Types File that contains  typedef, SET,CLEAR,Toggle...etc */
#include "STD.h"

/**
 *@brief : The ports Type of the AVR Atmega32                            
 */
typedef enum
{  
	DIO_enumPortA,
	DIO_enumPortB,
	DIO_enumPortC,
	DIO_enumPortD
}DIO_enumPorts_t;

/**
 *@brief : The Error List Type                                           
 */
typedef enum 
{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	DIO_enumOk, 
	/**
	 *@brief : Everything NOk, initial value.
	 */
	DIO_enumNOk, 
	/**
	 *@brief : if value passed to function out of range.
	 */
	DIO_enumLogicalValueError,                    
	/**
	 *@brief : NULL Pointer is passed.
	 */
	DIO_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	DIO_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	DIO_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	DIO_enumWrongConfig    
	
}DIO_enumError_t;
	
/**
 *@brief : The Configuration Type of Pins to be Input or Output !        
 */
typedef enum
{	
	/**
	 *@brief : Select Pin Configuration to be Output .
	 */
	DIO_enumOutput,
	/**
	 *@brief : Select Pin Configuration to be Input Internal PullUp .
	 */             
	DIO_enumInputInternalPU,
	/**
	 *@brief : Select Pin Configuration to be Input External PullDown
	 */    
	DIO_enumInputExternalPD   
}DIO_enumConfig_t;
	
/**
 *@brief :  Logic State Type : HIGH (5V) or LOW(0V )                     
 */
typedef enum
{   
	DIO_enumLogicLow,
	DIO_enumLogicHigh
}DIO_enumLogicState_t;

/**
 *@brief :  Pins Type                                                    
 */
typedef enum
{
	DIO_enumPin0,
	DIO_enumPin1,
	DIO_enumPin2,
	DIO_enumPin3,
	DIO_enumPin4,
	DIO_enumPin5,
	DIO_enumPin6,
	DIO_enumPin7
}DIO_enumPins_t;


/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState);

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState); 

/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,u8* Add_Pu8PinValue);



/**
 *@brief  : Function to toggle the logic state of the pin.
 *@param  : Port Number & Pin Number.
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumTogglePinState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum);


/**
 *@brief  : Function to set the port to a specific value.
 *@param  : Port Number and value to be assigned to port .
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumAssignPortLogicalStatus(DIO_enumPorts_t Copy_enumPortNum, u8 LogicalValueOfPins);




#endif /* DIO_H_ */
