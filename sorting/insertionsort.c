#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int);
int main()
{
	int *arr;
	int i, j, N;
	printf("How Many Elements?");
	scanf("%d",&N);
	arr = (int *) malloc (N * sizeof(int));
	printf("\nEnter Elements:");
	for(i = 0; i < N; i++)
	scanf("%d", &arr[i]);
	printf("\nBefore Sorting\n");
	for(i = 0; i < N; i++)
		printf("%d  ",arr[i]);
	insertionSort(arr,N);
	printf("\nAfter Sorting\n");
	for(i = 0; i < N; i++)
	printf("%d ", arr[i]);
	
	printf("\n\n");
	return EXIT_SUCCESS;
}

void insertionSort(int *arr, int N)
{

}
