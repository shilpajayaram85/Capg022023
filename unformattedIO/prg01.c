#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

	char str[1024];
	fgets(str,1024,stdin);

	printf("%s",str);
	printf("Hello");
	return 0;
}
