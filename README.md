# Embedded_Linux_Tasks



### By Eng. Nour Alaa-Eldin Hanafy Moharram



## Task 4:

### Generate HEX/ELF file to be flashed on ATmega32 Target to perform the functionality below:

Develop a digital timer featuring an alarm, adjustable via three switches and visual feedback through an LED indicator. The requirements are as follows:
Switch 1: Increment the timer value.
Switch 2: Decrement the timer value.
Switch 3: start the countdown of the timer.
LED Indicator: Illuminate upon the timer reaching zero to signal the activation of the alarm.

#### Steps of solution:

1. First create the Project Directory and within it create MCAL and HAL directory

2. append the .c and .h files for the MCAL and HAL layer in their respective directory

3. append the main.c and application files to the main direcotry along side with the Standard types file

4.  create four global variables in .bashrc file that will hold the path to the avr-gcc , avr-ar , avr-objdump and avr-objcopy 

   ```bash
   cd ~ 
   vim .bashrc
   ##enter edit mode by pressing on i
   export AVR_GCC=/home/nourmoharram/x-tools/avr/bin/avr-gcc
   export AVR_AR=/home/nourmoharram/x-tools/avr/bin/avr-ar
   export AVR_OBJDUMP=/home/nourmoharram/x-tools/avr/bin/avr-objdump
   export AVR_OBJCOPY=/home/nourmoharram/x-tools/avr/bin/avr-objcopy
   ##press esc to exit edit mode
   ## shift + colon then write "wq" to save and exit
   ```

5. move to MCAL directory and compile the .c files

   ```bash
   $AVR_GCC -c *.c -I . -I ../
   $AVR_AR -rcs libMCAL.a *.o
   ```

6. move to HAL directory and compile the .c files

   ```bash
   $AVR_GCC -c *.c -I . -I ../ -I ../MCAL
   $AVR_AR -rcs libHAL.a *.o
   ```

7. copy the the libraries to the main directory using cp command

8. build the main application with the static libraries created for MCAL and HAL layers

   ```bash
   $AVR_GCC main.c APP.c Delayfunc.c -o program.elf -mmcu=atmega32 -I . -I MCAL/ -I HAL/ -L . -lHAL -lMCAL  -DF_CPU=8000000UL 
   ```

9. in order to create .hex file in intel format from the .elf file generated from the build process we will use the objcopy utility 

   ```bash
   $AVR_OBJCOPY -j .text -j .data -O ihex program.elf program.hex
   ```

10. flash the "program.elf" file or "program.hex" file on "proteus" or using usbasp on target.
