#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Employee
{
	int id;
	float sal;
	char name[20];
};

typedef struct Employee EMP;

void getDetails(EMP *);
int writeToFile(FILE *, EMP *);
void printDetails(EMP *);
int readFromFile(FILE *,EMP *);
int main()
{
	
	EMP e;
	FILE *fptr;
	int ch = 1;
	int retValue;
	fptr = fopen("EMP.dat", "r+");
	if (fptr == NULL)
	{
	  perror("fopen: ");
	  exit(EXIT_FAILURE);
	}
	while(1)
	{
	    
		printf("\n1. Get Employee Details");
		printf("\n2. Print EMployee Details");
		printf("\n3. Clear the Screen");
		printf("\n4.Exit");
		printf("\nEnter your Choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
				ch = 1;
				while(ch){
					getDetails(&e);
					retValue = writeToFile(fptr, &e);

					if(retValue == 0)
						{
							perror("Write:");
							exit(EXIT_SUCCESS);
						}
				printf("\nDo you want to add another employee(1/0):");
				scanf("%d",&ch);
				}
				break;
		case 2:		
				while(readFromFile(fptr,&e))
					printDetails(&e);
				break;
		case 3: 
				system("clear");
				break;
		case 4: 
				fclose(fptr);
				exit(EXIT_SUCCESS);
				break;
		default: 
				printf("\nYou Have Entered a wrong Choice");
	  }

    }

	fclose(fptr);
	printf("\n\n");

	return EXIT_SUCCESS;
}

	
void getDetails(EMP *e)
{

   printf("\nEmployee ID: ");
   scanf("%d", &e->id);
   printf("\nEmployee Name: ");
   scanf("%s", e->name);
   printf("\nSalary : ");
   scanf("%f", &e->sal);
}


void printDetails(EMP *e)
{

   printf("\n================Employee Details===================\n");
   printf("\nEmployee ID: ");
   printf("%d", e->id);
   printf("\nEmployee Name: ");
   printf("%s", e->name);
   printf("\nSalary : ");
   printf("%f", e->sal);
   printf("\n===================================================\n");
}

int writeToFile(FILE *fp, EMP *e)
{	

	//fprintf(fp, "%d %s %f", e->id, e->name, e->sal);
	fseek(fp,0L, SEEK_END); //will move file pointer to end
	int ret = fwrite(e, sizeof(EMP), 1, fp);
	return ret;
	//printf("\nRet = %d", ret);
}

int readFromFile(FILE *fp, EMP *e)
{	

	//fprintf(fp, "%d %s %f", e->id, e->name, e->sal);
	int ret = fread(e, sizeof(EMP), 1, fp);
	//printf("\nRet = %d", ret);
	return ret;
}


    
