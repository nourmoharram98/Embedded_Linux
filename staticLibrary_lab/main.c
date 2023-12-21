#include<stdio.h>
#include"addition.h"
#include"division.h"
#include"modulus.h"
#include"multiplication.h"
#include"subtraction.h"



int main(void)
{

    int num1=10;
    int num2=5;
    float result=0;
    printf("*****Program Start*****\n");
    result=add_numbers(num1,num2);
    printf("the addition of %d & %d = %0.1f \n",num1,num2,result);
    result=Subtract_numbers(num1,num2);
    printf("the subtraction of %d & %d = %0.1f \n",num1,num2,result);
    result=Multiplicat_numbers(num1,num2);
    printf("the multiplication of %d & %d = %0.1f \n",num1,num2,result);
    result=Modulus_num(num1,num2);
    printf("the Modulus of %d & %d = %0.1f \n",num1,num2,result);
    result=Division_numbers(num1,num2);
    printf("the Division of %d & %d = %0.1f \n",num1,num2,result);
    
    return 0;
}
