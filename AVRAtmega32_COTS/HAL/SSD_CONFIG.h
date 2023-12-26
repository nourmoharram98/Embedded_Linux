/*
 * SSD_CONFIG.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Nour Moharram
 */

#ifndef HAL_SSD_SSD_CONFIG_H_
#define HAL_SSD_SSD_CONFIG_H_

/*Boundaries for the seven segments that can be embedded in system*/
#define NO_SSD				0
#define MAXIMUM_NO_OF_SSD	4

/*Number of Seven segments in System*/
#define NUMBER_OF_SSD		2

/*Number of pins required for the Seven segments*/
#define ONE_SSD_PINS		7
#define TWO_SSD_PINS		14
#define THREE_SSD_PINS		24

/*Start values for each Port*/
#define START_OF_PORTA		0
#define START_OF_PORTB		8
#define START_OF_PORTC		16
#define START_OF_PORTD		24

/*End values for each Port*/
#define END_OF_PORTA		7
#define END_OF_PORTB		15
#define END_OF_PORTC		23
#define END_OF_PORTD		31

/*Size of array of numbers and its boundaries*/
#define Size_Of_arrofnumbers	10
#define START_OF_NUMBERS		0
#define END_OF_NUMBERS			99


typedef enum
{
	Common_Anode,
	Common_Cathode
}SSD_Mode_t;

typedef enum
{
	SSD_ONE,
	SSD_TWO,
	Number_Of_SSD
}SSD_ID_t;


typedef enum
{
	SSD_PORTA,
	SSD_PORTB,
	SSD_PORTC,
	SSD_PORTD,
}SSD_PORT_t;

typedef struct
{
	SSD_Mode_t SSD_MODE;
	SSD_PORT_t SSD_PORT;
}SSD_CONFIGURATIONS;

#endif /* HAL_SSD_SSD_CONFIG_H_ */
