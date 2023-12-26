/*
 * MCU_Registers.h
 *
 *  Created on: Dec 17, 2023
 *      Author: Dell
 */

#ifndef MCAL_MCU_REGISTERS_H_
#define MCAL_MCU_REGISTERS_H_

/*
 * MCU_Registers.h
 *
 * Created: 12/2/2023 6:31:28 PM
 *  Author: Nour Moharram
 */


#ifndef MCU_REGISTERS_H_
#define MCU_REGISTERS_H_

//#define F_CPU 1000000UL



/*DDR Registers*/
#define DDRA      *((volatile u8 *)0x3A)
#define DDRB      *((volatile u8 *)0x37)
#define DDRC      *((volatile u8 *)0x34)
#define DDRD      *((volatile u8 *)0x31)
/*PORT Registers*/
#define PORTA     *((volatile u8 *)0x3B)
#define PORTB     *((volatile u8 *)0x38)
#define PORTC     *((volatile u8 *)0x35)
#define PORTD     *((volatile u8 *)0x32)
/*PIN Registers*/
#define PINA      *((volatile u8 *)0x39)
#define PINB      *((volatile u8 *)0x36)
#define PINC      *((volatile u8 *)0x33)
#define PIND      *((volatile u8 *)0x30)




#endif /* MCU_REGISTERS_H_ */

#endif /* MCAL_MCU_REGISTERS_H_ */
