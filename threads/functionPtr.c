#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;

ULL sumOdd = 0;
ULL sumEven = 0;
void findEven(ULL, ULL);
void findOdd(ULL, ULL);
int main()
{
	
	int var = 10;
	int *ptr = &var;
	ULL start = 0;
	ULL end = 190000000;
	
	//syntax for function pointer
	//void (*fun_ptr)(args) = &nameFunction;
	//void is the return type of nameFunction you have to change accordingly

	void(*fptr)(ULL,ULL) = &findOdd;  //this is not calling function
	//assigning stack frame address to pointer
	

	//calling function

	// normally  findOdd(start , end);

	// using function pointer (*fptr)(start, end);
	
	(*fptr)(start,end);
	
	printf("\nSum Odd = %llu", sumOdd);
	printf("\n\n");
	return EXIT_SUCCESS;
}

void findOdd(ULL start, ULL end)
{
	ULL i;
	for(i = start;i<=end;i++)
	{
		if((i & 1) == 1)
		{
			sumOdd += i;
			// sleep(1);
		}
	}
}

void findEven(ULL start, ULL end)
{
	ULL i;
	for(i=start;i<=end;i++)
	{
		if((i & 1) == 0)
		{
			sumEven += i;
		}
	}
}
