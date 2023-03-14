#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x = 10;
	printf("\nEnter x value\n");
	scanf("%d", &x);

	if(x < 20)
		printf("\nx is less than 20");
	else if(x < 40)
		printf("\nX is less than 40");
	else
		printf("\nX is greater than 40");
	
	printf("\n\n");
return EXIT_SUCCESS;
}
