#include <stdio.h>
#include <stdlib.h>

#define row 5
#define col 5
int main()
{

	int i,j;
	int **ptr = (int **) malloc(row * sizeof(int *));
	
	for(i=0; i<row; i++)
	  ptr[i] = (int*) malloc(col * sizeof(int));


	for(i = 0; i<row; i++)
	{
	 printf("%d -->", &ptr[i]);
	 
	 for(j = 0; j<col; j++)
	 {
			printf("%d  ",& ptr[i][j]);
	 }
	 printf("\n");
	}
	printf("\n\n");
	
	return EXIT_SUCCESS;
}
