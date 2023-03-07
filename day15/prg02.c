#include <stdio.h>
#include <stdlib.h>


struct employee
{
	int id;
	char Name[20];
	struct employee *ptr;
};

typedef struct employee EMP;


void readDetails(int , EMP **);
void printDetails(EMP *);

int main()
{

	EMP *head = NULL;
	//EMP *newNode = NULL;
	//EMP *temp = NULL;

	int n, it;

	printf("Enter number of Employees\n");
	scanf("%d", &n);
	
	readDetails(n,&head);

	printDetails(head);

	printf("\n\n");
	return EXIT_SUCCESS;
}

void readDetails(int n, EMP **head)
{
	
	int it;
	EMP *newNode = NULL;
	EMP *temp = NULL;
	for(it=0; it<n; it++)
	{

		
		newNode = (EMP *) malloc(1*sizeof(EMP));
		if(newNode == NULL)
		{
			printf("\n malloc() - failed\n");
			exit(EXIT_FAILURE);
		}

		printf("\nEnter the id, name of Employee %d\n" ,it+1);
		scanf("%d%s",&newNode->id,newNode->Name);
		
		newNode->ptr = NULL;

		if(*(head) == NULL)
		{

			//list empty
			*(head) = newNode;
			temp = newNode;
		}

		else
		{
			temp->ptr = newNode;
			temp = newNode;
		}

	}
	printDetails(*head);
}

void printDetails(EMP *head)
{


    EMP *temp = head;
	int it = 0;
	if(head == NULL)
	 printf("\nList Empty!!");
	else
	{
		printf("\n================== Employee List =====================\n");
		while(temp != NULL)
		{

			printf("\nEmployee %d", ++it);
			printf("\nEmployee ID: %d", temp->id);
			printf("\nEmployee Name: %s",temp->Name);
			temp = temp ->ptr;
		}
	}
}
