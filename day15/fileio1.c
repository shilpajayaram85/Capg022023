#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *fptr;
	char *fileName = argv[1];
	char line[1024];
	fptr = fopen(fileName, "w");
	if(fptr == NULL)
	{
		//fprintf(stdout, "\nError in Opening file\n");
		fprintf(stderr, "\nError in opening file\n");
		perror("fopen error:  ");
		exit(EXIT_FAILURE);
	}
	
	printf("\nFile opened successfully for write only\n");

	fscanf(stdin,"%[^\n]s",line);
	// while(fgets(line, 1024, fptr))
		// puts(line);

	//fgets(line, 1024, stdin);
	fprintf(fptr, "%s", line);
	fclose(fptr);

	printf("\n\n");
	return EXIT_SUCCESS;
}
