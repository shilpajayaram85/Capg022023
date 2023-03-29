#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int main()
{

	int a[SIZE] = { 10, 20};

	int index;


	for(index = 0; index < SIZE; index++)

			printf("%d ", a[index]);

	printf("\n\n");
	return EXIT_SUCCESS;
}
