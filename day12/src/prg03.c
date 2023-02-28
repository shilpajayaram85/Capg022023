#include<myHeader.h>
#include<stdio.h>
#include<stdlib.h>
#define aSize 5
int main()
{
	
	int choice;
	int arr[aSize];

	getValArr(arr,aSize);

	dispArr(arr,aSize);

	while(1){

	printf("\nSort the array in:\n1. Ascending order\n2.Descending Order");
	printf("\n3.Display\n4.Exit\n");
	printf("Choice:  ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			sortAArr(arr,aSize);
			break;
		case 2: 
			sortDArr(arr,aSize);
			break;
		case 3:
		        dispArr(arr,aSize);
	       		break;
	 	case 4:		
			printf("\nThank You for using this Software\n\n");
			exit(EXIT_SUCCESS);//kill you program in agood way
		default:
			printf("\nWrong Choice Entered");
	}

    }
	printf("\n\nBye");

}
