#include <stdio.h>

#define MONTHS 12

int main()

{


	const int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};

	int index;

	for(index = 0; index < MONTHS; index++)

		printf("Month %d has %d days\n",  index+1, days[index]);
	printf("\n\n");
	return 0;
}
