#include<stdio.h>
#include<myHeader.h>
#include<stdlib.h>
#define row 1024

int main()
{
	int n;
	char eName[row][BUFF];

	
	
	printf("\nEnter number of Employees: ");
	scanf("%d",&n);

	/*char **eName =(char**)malloc(n*sizeof(char*));
	for(it=0;it<row;it++)
		eName[it]=(char*)malloc(BUFF*sizeof(char));*/

	getEname(eName,n);

	dispEname(eName,n);

	sortEname(eName,n);
	
	printf("\nSorted List");
	dispEname(eName,n);
	
	/*for(it=0;it<row;it++)
		free(eName[it]);
	free(eName);*/
	
	printf("\n\n");

	return (EXIT_SUCCESS);
}
