/*
 * unformatted io statements
 *
 *
 *   getchar()
 *   getc()
 *   gets()
 *   putchar()
 *   putc()
 *   puts()
 *
 *  */

#include<stdio.h>
int main()
{
	char c;

	printf("\nInput a character: ");
	/*c=getchar();
	
	//printf("\nInput Value=%c\tASCII value=%d\n",c,c);

	putchar(c);
	putchar(65);*/


	c=getc(stdin);
	printf("\n Input Value: ");
	putc(c,stdout);
	printf("\n\n");

	return(0);
}
