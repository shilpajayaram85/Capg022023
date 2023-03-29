#include <stdio.h>
#include <stdlib.h>

int main()
{

	int a = 10;
	char name[8] = "shilpa";
	int b = 20;
	int *ptr = NULL;

	printf("\n a address = %u and its value = %d", &a, a);
	printf("\n name address = %u and its value = %s", &name[0], &name[0]);
	printf("\n b address = %u and its value = %d", &b, b);
	
	printf("\nBefore Pointing");
	printf("\n ptr address = %u and its value = %u", &ptr, ptr);
	
	ptr = &a;
	
	printf("\nAfter Pointing");
	printf("\n ptr address = %u and its value = %u", &ptr, ptr);

	printf("\nBefore Pointing");
	printf("\n ptr address = %u and its value = %u", &ptr, ptr);
	
	ptr = &name[0];
	
	printf("\nAfter Pointing");
	printf("\n ptr address = %u and its value = %u", &ptr, ptr);

	printf("\nBefore Pointing");
	printf("\n ptr address = %u and its value = %u", &ptr, ptr);
	
	ptr = &b;
	
	printf("\nAfter Pointing");
	printf("\n ptr address = %u and its value = %u", &ptr, ptr);

//printf("\n a address = %ls and its value = %d", &a, a);
	
	printf("\n\n");
	return EXIT_SUCCESS;
}
