/*
 * PORT_CONFIG.h
 *
 * Created: 12/2/2023 4:29:47 PM
 *  Author: Nour Moharram
 */ 


#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/**********************************************************
*														  *
*		Macros Initialization						      *
*														  *
*														  *
***********************************************************/
#define PRECOMPILE				0
#define POSTCOMPILE				1
#define NORMAL_MODE				2
#define FOUR_PORTS				4
#define THREE_PORTS				3
#define TWO_PORTS				2
#define ONE_PORT				1
#define EXISTED					1
#define NOT_EXISTED             0
#define INPUT					0
#define OUTPUT					1
#define LOW						0
#define HIGH					1
/*Macros for size of array of configurations*/
#define FOUR_PORTS_CONFIGURATIONS			32
#define THREE_PORTS_CONFIGURATIONS			24
#define TWO_PORTS_CONFIGURATIONS			16
#define ONE_PORT_CONFIGURATIONS				8
/*Macros for pin configuration*/
#define OUTPUT_LOW							0
#define OUTPUT_HIGH							1
#define INPUT_PULLEDUP						2
#define INPUT_FLOAT							3

/**********************************************************
*	Number of IO Registers:								  *
*		-FOUR_PORTS										  *
*		-THREE_PORTS									  *
*		-TWO_PORTS		                                  *
*		-ONE_PORT										  *
*		 						                          *
***********************************************************/

#define TARGET_IO_PORTS						FOUR_PORTS 


/**********************************************************
*	Mode of Compilation:								  *
*		-PRECOMPILE										  *
*		-POSTCOMPILE								      *
*		 						                          *
***********************************************************/

#define COMPILATION_MODE					POSTCOMPILE

/**********************************************************
*	Number of configuration options:					  *
*		-FOUR_PORTS_CONFIGURATIONS			              *
*		-THREE_PORTS_CONFIGURATIONS						  *
*		-TWO_PORTS_CONFIGURATION	                      *
*		-ONE_PORT_CONFIGURATION						      *
*		 						                          *
***********************************************************/

#define PORT_PIN_CONFIGURATIONS_SIZE		FOUR_PORTS_CONFIGURATIONS



/**********************************************************
*	PIN NO. 6 and PIN NO. 7:							  *
*		-EXISTED										  *
*		-NOT_EXISTED								      *
*		 						                          *
***********************************************************/
#define PIN_NO_SEVEN							EXISTED
#if (PIN_NO_SEVEN==EXISTED)
	#define PIN_NO_SIX	EXISTED        //do not configure
#elif (PIN_NO_SEVEN==NOT_EXISTED)
	#define PIN_NO_SIX							EXISTED   //configure
#endif

#if (COMPILATION_MODE==PRECOMPILE)
	/**********************************************************
	*	     PIN configuration options:					      *
	*		-OUTPUT_LOW                                       *
	*		-OUTPUT_HIGH					                  *
	*		-INPUT_PULLEDUP                                   *
	*		-INPUT_FLOAT					                  *
	*		 						                          *
	***********************************************************/

	/*PORT_A_PINS_CONFIG*/
	#define PORTA_PIN0_CONFIG	OUTPUT_LOW
	#define PORTA_PIN1_CONFIG	OUTPUT_LOW
	#define PORTA_PIN2_CONFIG	OUTPUT_LOW
	#define PORTA_PIN3_CONFIG	OUTPUT_LOW
	#define PORTA_PIN4_CONFIG	INPUT_FLOAT
	#define PORTA_PIN5_CONFIG	INPUT_FLOAT
	#define PORTA_PIN6_CONFIG	INPUT_FLOAT
	#define PORTA_PIN7_CONFIG	INPUT_FLOAT

	#if(TARGET_IO_PORTS != ONE_PORT)
		/*PORT_B_PINS_CONFIG*/
		#define PORTB_PIN0_CONFIG	OUTPUT_LOW
		#define PORTB_PIN1_CONFIG	OUTPUT_LOW
		#define PORTB_PIN2_CONFIG	INPUT_PULLEDUP
		#define PORTB_PIN3_CONFIG	INPUT_FLOAT
		#define PORTB_PIN4_CONFIG	INPUT_FLOAT
		#define PORTB_PIN5_CONFIG	INPUT_FLOAT
		#define PORTB_PIN6_CONFIG	INPUT_FLOAT
		#define PORTB_PIN7_CONFIG	INPUT_FLOAT
	#endif

	#if(TARGET_IO_PORTS != TWO_PORTS || TARGET_IO_PORTS != ONE_PORT)
		/*PORT_C_PINS_CONFIG*/
		#define PORTC_PIN0_CONFIG	INPUT_FLOAT
		#define PORTC_PIN1_CONFIG	INPUT_FLOAT
		#define PORTC_PIN2_CONFIG	INPUT_FLOAT
		#define PORTC_PIN3_CONFIG	INPUT_FLOAT
		#define PORTC_PIN4_CONFIG	INPUT_FLOAT
		#define PORTC_PIN5_CONFIG	INPUT_FLOAT
		#define PORTC_PIN6_CONFIG	INPUT_FLOAT
		#define PORTC_PIN7_CONFIG	INPUT_FLOAT
	#endif

	#if(TARGET_IO_REGISTERS == FOUR_PORTS)
		/*PORT_D_PINS_CONFIG*/
		#define PORTD_PIN0_CONFIG	INPUT_FLOAT
		#define PORTD_PIN1_CONFIG	INPUT_FLOAT
		#define PORTD_PIN2_CONFIG	INPUT_FLOAT
		#define PORTD_PIN3_CONFIG	INPUT_FLOAT
		#define PORTD_PIN4_CONFIG	INPUT_FLOAT
		#define PORTD_PIN5_CONFIG	INPUT_FLOAT
		#define PORTD_PIN6_CONFIG	INPUT_FLOAT
		#define PORTD_PIN7_CONFIG	INPUT_FLOAT
	#endif
	
	

#elif (COMPILATION_MODE==POSTCOMPILE)
	/**
	 *@brief :  Port and Pins Numbers                                                   
	 */
	typedef enum{
		PORT_PA0 ,
		PORT_PA1 ,
		PORT_PA2 ,
		PORT_PA3 ,
		PORT_PA4 ,
		PORT_PA5 ,
		PORT_PA6 ,
		PORT_PA7 ,
		PORT_PB0 ,
		PORT_PB1 ,
		PORT_PB2 ,
		PORT_PB3 ,
		PORT_PB4 ,
		PORT_PB5 ,
		PORT_PB6 ,
		PORT_PB7 ,
		PORT_PC0 ,
		PORT_PC1 ,
		PORT_PC2 ,
		PORT_PC3 ,
		PORT_PC4 ,
		PORT_PC5 ,
		PORT_PC6 ,
		PORT_PC7 ,
		PORT_PD0 ,
		PORT_PD1 ,
		PORT_PD2 ,
		PORT_PD3 ,
		PORT_PD4 ,
		PORT_PD5 ,
		PORT_PD6 ,
		PORT_PD7,

	}Port_PinNumber;


	/**
	 *@brief :  Port number
	 */
	typedef enum{
		PORT_PORTA= 0,
		PORT_PORTB,
		PORT_PORTC,
		PORT_PORTD,

	}Port_PortNumber;


	/**
	 *@brief :  PIN Direction                                                   
	 */
	typedef enum{
		PORT_PINDIR_INPUT,
		PORT_PINDIR_OUTPUT,

	}Port_PinDirectionType;

	/**
	 *@brief :  Pin Polarity                                                   
	 */
	typedef enum{
		PORT_PIN_LEVEL_LOW,
		PORT_PIN_LEVEL_HIGH

	}Port_LevelType;

	typedef struct
	{
		Port_PinNumber PORT_PIN_Number;  // PORT and PIN number
		Port_LevelType           Port_PinLevelValue; //high or low initial value
		Port_PinDirectionType    Port_PinDirection; // input or output	
	}PORT_CONFIGURATION;
	
#endif


#endif /* PORT_CONFIG_H_ */
