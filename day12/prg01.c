#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define row 3
#define col 30
#define BUFF 1024

int main()
{
	int i,j;

	char eName[row][BUFF];

	/*strcpy(eName[0],"Raghu");
	strcpy(eName[1],"Shilpa");
	strcpy(eName[2],"Vivan");


	printf("\nEmp Name : %s", eName[0]);
	printf("\nEmp Name : %s", eName[1]);
	printf("\nEmp Name : %s", eName[2]);*/


	for(i=0;i<row;i++)
	{
		printf("Enter Name of Emp %d: ",(i+1));
		//scanf("%[^\n]s", eName[i]); //To keep on scannig characters untill a new line. 
		//scanf(" ");
		fgets(eName[i],BUFF,stdin);
		eName[i][strlen(eName[i])-1]='\0';// fgets will read newline too so to avoid that use the code in next line
	}

//	for(i=0;i<row;i++)
//	   printf("\nEmp Name : %s", eName[i]);




	for(i=0;i<row;i++)
	{
		for(j=0;j<=strlen(eName[i]);j++)
			{
			   printf("\n%c = %d Address=%u", eName[i][j], eName[i][j],&eName[i][j]);
			}
	}
	printf("\n\n");
	return EXIT_SUCCESS;
}	
