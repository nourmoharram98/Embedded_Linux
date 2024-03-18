#include"add.h"
#include"division.h"
#include"mult.h"
#include"sub.h"
#include<stdio.h>
int main(void)
{

    int x=0;
    
    x=add_numbers(5,10);
    printf("the number = %d \n",x);

    x=sub_numbers(10,13);
    printf("the number = %d \n",x);

    x=division_numbers(25,5);
    printf("the number = %d \n",x);

    x=mult_numbers(5,5);
    printf("the number = %d \n",x);

    return 0;
}