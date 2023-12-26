/*
 * BitMath.h
 *
 * Created: 11/26/2023 9:21:28 PM
 *  Author: Nour Moharram
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_
//set bit
#define SET_BIT(REG,BIT)   (REG |= 1<<(BIT))
//clear bit
#define CLR_BIT(REG,BIT)   (REG &= ~(1<<(BIT)))
//toggle bit
#define TOG_BIT(REG,BIT)   (REG ^= 1<<(BIT))
//read bit
#define READ_BIT(REG,BIT)  (REG>>(BIT)) & 1


// Set high nibble in REG
#define SET_HIGH_NIB(REG)            REG |= 0xF0;
// Clear high nibble in REG
#define CLR_HIGH_NIB(REG)            REG &= 0x0F;
// Get high nibble in REG
#define GET_HIGH_NIB(REG)            REG & 0xF0;
// Toggle high nibble in REG
#define TGL_HIGH_NIB(REG)            REG ^= 0xF0;
// Set low nibble in REG
#define SET_LOW_NIB(REG)             REG |= 0x0F;
// Clear low nibble in REG
#define CLR_LOW_NIB(REG)             REG &= 0xF0;
// Get low nibble in REG
#define GET_LOW_NIB(REG)             REG & 0x0F;
// Toggle low nibble in REG
#define TGL_LOW_NIB(REG)             REG ^= 0x0F;

// Assign VALUE to REG
#define ASSIGN_REG(REG,VALUE)        REG = VALUE;
// Assign VALUE to high nibble REG
#define ASSIGN_HIGH_NIB(REG,VALUE)   REG = (REG & 0x0F) | ((VALUE & 0x0F)<<4);
// Assign VALUE to low nibble REG
#define ASSIGN_LOW_NIB(REG,VALUE)    REG = (REG & 0xF0) | ((VALUE & 0x0F));
// Right shift by NO in REG
#define RSHFT_REG(REG, NO)           REG <<= NO;
// Left shift by NO in REG
#define LSHFT_REG(REG, NO)           REG >>=NO;
// Circular right shift by NO in REG
#define CRSHFT_REG(REG, NO)          REG = (REG>>NO) | (REG<<(8-NO));
// Circular left shift by NO in REG
#define CLSHFT_REG(REG,NO)           REG = (REG<<NO) | (REG>>(8-NO));


#endif /* BITMATH_H_ */