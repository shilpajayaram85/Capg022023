#include<stdio.h>

#include "userheader.h"
int main()
{
	greeter_func();

	
	printf("\nAdding 5 and 10 together gives us %d\n",add(5,10));
	printf("\nSubtracting 10 from 32 results in %d\n",sub(10,32));
	printf("\nMultiplying 43 and 2 together gives us %d\n",mul(43,2));
	printf("\nResult of dividing 78 from 2 gives us %f\n",div(78,2));
	

	return 0;
}
