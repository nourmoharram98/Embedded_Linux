/*
 * STD.h
 *
 * Created: 11/26/2023 9:14:48 PM
 *  Author: Nour Moharram
 */ 


#ifndef STD_H_
#define STD_H_

typedef unsigned char       u8;
typedef signed char         s8;
typedef unsigned short int u16;
typedef signed short int   s16;
typedef unsigned long int  u32;
typedef signed long int    s32;
typedef float              f32;
typedef double             f64;

#define NULL  (void *)0

#define OK    0
#define NOK   1
#define REG_HIGH  0xFF
#define REG_LOW   0x00


void Delay_ms(u32 Time_in_ms);

#endif /* STD_H_ */