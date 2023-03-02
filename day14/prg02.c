#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
	int id;
	int salary;
	char name[25];
};
typedef struct employee EMP;

void printDetails(EMP*);


int main(int argc, char **argv)
{

	EMP e;

	if (argc >=4)
	{
	    e.id = atoi(argv[1]);
		e.salary = atoi(argv[3]);
		strcpy(e.name, argv[2]);
		printDetails(&e);
	}
	else
	   printf("\nNot sufficient arguments");
	
  printf("\n\n");
  return EXIT_SUCCESS;	
}

void printDetails(EMP *e)
{
	printf("\nEmployee ID: %d", e->id);
	printf("\nEmployee Name: %s", e->name);
	printf("\nEmployee Salary: %d", e->salary);
}

