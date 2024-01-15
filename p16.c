#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/* demonstrate a nested forloop */
main()
{
 float this_is_a_number, total;
 int i, j;
 total = 0;
/* outer forloop goes round 10 times */
 for (i = 0;i < 10;i++)
 {
 /* inner forloop goes round twice */
 for (j = 0;j < 2;j++)
 {
 printf("Please enter a number:\n ");
 scanf("%f", &this_is_a_number); /* read number in */
 total = total + this_is_a_number;
 }
 }
 printf("Total Sum is = %f\n", total);
}