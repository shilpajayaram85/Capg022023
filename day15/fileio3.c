#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *fptr;
	char *fileName = argv[1];
	char line[1024];
	fptr=fopen(fileName,"w");

	if(fptr == NULL)
	{
		perror("fopen error");
		exit(EXIT_FAILURE);
	}

	printf("\nFile opened successfully for write operation\n");

	fscanf(stdin,"%[^\n]s",line); //using fscanf we can avoid new line

    //fgets(line,1024,stdin); //fgets will read new line too

	fprintf(fptr, "%s", line);

	fclose(fptr);
	printf("\n\n");
	return 0;
}

