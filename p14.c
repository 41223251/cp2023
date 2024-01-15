#include <stdio.h>
/* read and display a number */
int main () {
 char c;
 printf("Enter character: ");
 c = getchar(); /* read the character in */
 printf("Character entered: ");
 putchar(c); /* write the character */
 return(0);
}