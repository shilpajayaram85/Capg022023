#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
	struct Employee
	{
		int empID;
		int empPhone;
		float empSalary;
		char empName[25];
	};

	struct Employee emp1;

	scanf("%d%d%f%s",&emp1.empID,&emp1.empPhone,&emp1.empSalary,emp1.empName);

	printf("\nName: %s", emp1.empName);
	printf("\nID: %d", emp1.empID);
	printf("\nPhone: %d", emp1.empPhone);
	printf("\nSalary: %f",emp1.empSalary);

	printf("\n\n");

	return EXIT_SUCCESS;
}

