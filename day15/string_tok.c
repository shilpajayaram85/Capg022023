#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

	char s[] = "|1001|Airtel|1002|101|This is a message|";

	char *token;

	int cWords = 0;
/*
	token = strtok(s, " ");
	printf("\nToken 1: %s", token);

	token = strtok(NULL, " ");
	printf("\nToken 2: %s", token);
	
	token = strtok(NULL, " ");
	printf("\nToken 3: %s", token);

	token = strtok(NULL, " ");
	printf("\nToken 4: %s", token);

	token = strtok(NULL, " ");
	printf("\nToken 5: %s", token);
	*/


	token = strtok(s, "|");
	while (token != NULL)
	{
		printf("\nToken %d : %s",cWords+1, token);
		cWords++;
		token = strtok(NULL , "|");
	}

	printf("\nNo of Words in a String are %d", cWords);
	printf("\n\n");
	return EXIT_SUCCESS;
}
