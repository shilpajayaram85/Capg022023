#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *fptr;
	char *fileName = argv[1];
	char line[1024] = "Shilpa Jayaram";
	int a = 10;
	float b = 23.33;
	char gender = 'x';

	fptr=fopen(fileName,"w");

	if(fptr == NULL)
	{
		perror("fopen error");
		exit(EXIT_FAILURE);
	}

	printf("\nFile opened successfully\n");

	fprintf(fptr, "%s|%c|%d|%f|\n", line,gender,a,b);

	fclose(fptr);
	printf("\n\n");
	return 0;
}

