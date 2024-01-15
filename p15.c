/* Add two floating point numbers */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
 float this_is_a_number1, this_is_a_number2, total;
 printf("Please enter a number:\n ");
 scanf("%f", &this_is_a_number1); /* read decimal number in */
 printf("You entered %f\n", this_is_a_number1);
 printf("Please enter another number: \n");
 scanf("%f", &this_is_a_number2); /* read decimal number in */
 printf("You entered %f\n", this_is_a_number2);
Chapter 1 Introduction to C
6
 total = this_is_a_number1 + this_is_a_number2;/* add the numbers */
 printf("total is %f\n", total);
 return 0;
}
