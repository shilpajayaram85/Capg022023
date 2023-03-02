#include<stdio.h>
#include<stdlib.h>

int main()
{

	printf("Namasate BinatyExe LLC\n");
	
	int count;
	int *heap_loc = (int*)malloc(sizeof(int)*10);

	if(!heap_loc) return -1;
	for(count=0; count<11; count++)
		heap_loc[count] = count;
	for(count=0; count<11; count++)
		printf("%d  ", heap_loc[count]);
	free(heap_loc);

	return EXIT_SUCCESS;
}
