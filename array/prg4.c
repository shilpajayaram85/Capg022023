#include <stdio.h>
#include <stdlib.h>

int arr_size(int []);
int main()
{


	int arr[10];
	int size, index;
	int len;

	printf("\nHow many Elements: ");
	scanf("%d", &size);

	//arr = (int *) malloc(size * sizeof(int));

	/*printf("%d", sizeof(arr));
	printf("\nEnter array elements");
	for(index = 0; index < size; index++)
		scanf("%d", &arr[index]);*/
	
	//printf("\n %d  %d  \n", sizeof(arr) , sizeof(int));

	//len = sizeof(arr)/sizeof(arr[0]);

	len = arr_size(arr);
	printf("\nLength = %d", len);

	printf("\n\n");
	return EXIT_SUCCESS;
}


int arr_size(int arr[])
{

	int len = sizeof(arr)/sizeof(arr[0]);
	//printf("\n  %d  %d  \n", sizeof(arr), sizeof(arr[0]));
	return len;
}
