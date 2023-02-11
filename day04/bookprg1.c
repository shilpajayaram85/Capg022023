/*
 *
 *
 *
 * Testing for EOF
 *
 *
 *
 * */


#include<stdio.h>


int  main()

{

	int c;
	while((c=getchar())!=EOF){
		putchar(c);
	}
	
	printf("%d\n",c);
	printf("\n\n");
	return 0;
}
	
