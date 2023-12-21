# Embedded_Linux_Tasks



### By Eng. Nour Alaa-Eldin Hanafy Moharram

## Task1: 

Create Calculator Library and application for it using :

* ### Static Library

1. First: create the .c files required for the math operations Library and save them in directory Li

2. second: compile the .c files to generate the object files required for library using command below:

   * ###### gcc -c *.c

3. third: create the static library called mathOperations using command below:

   * ###### ar -rcs libmathOperations.a *.o

4. fourth: create the header files for the created operations and save them in directory Include

5. fifth: link the static library with the main.c file after compiling it with the command below:

   * ###### gcc main.c -L ./Lib -lmathOperations -o operations -static

* ### Dynamic Library

1. First: create the .c files required for the math operations Library and save them in directory Li

2. second: compile the .c files to generate the object files required for library using command below:

   * ###### gcc -c *.c

3. third: create the dynamic library called mathOperations using command below:

   * gcc --shared -fPIC libmathOperations.so *.o

4. ###### fourth: copy the dynamic library to the /usr/lib in root system in order to be linked to program by system loader in runtime

   * sudo cp ./Lib/lib*.so /usr/lib

   * sudo chmod 0755 /usr/lib/lib*.so

   * ###### sudo ldconfig (to update the cash file in /etc/ld.so.cache)

5. fifth: compile the main.c and link it to the dynamic library using command below

   * ###### gcc main.c -L ./Lib -lmathOperations -o operations -I ./Include

* ### Comparison between two libraries

​	1- use ldd command to test .elf files if it is statically linked or dynamically linked

​	2- use file command to test the libraries if it static or dynamic

​	3- use the objdump -T and -x to display the symbol table for each executable