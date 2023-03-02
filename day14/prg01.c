#include<stdio.h>

#include<stdlib.h>
#include<string.h>

int main(int argc, char  **argv)
{

	int result = 0;
	int val1 = atoi(argv[1]);
	int val2 = atoi(argv[2]);
	printf("How Many args main got: %d", argc);
	
	printf("\n1 arc: %s", argv[0]);
	
	result = val1 + val2;
	printf("\nResult = %d" ,result);
	

	printf("\n\n");
	return EXIT_SUCCESS;
}
