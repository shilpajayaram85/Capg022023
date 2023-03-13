#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *fptr;
	char *fileName = argv[1];
	char line[1024];
	fptr=fopen(fileName,"r+");

	if(fptr == NULL)
	{
		perror("fopen error");
		exit(EXIT_FAILURE);
	}

	printf("\nFile opened successfully for read only\n");

	printf("\nFile Pointer is @ %ld position", ftell(fptr));

	fscanf(fptr,"%s",line);  //will read upto blank space

	fprintf(stdout, "\n\n%s\n", line);
	printf("\nFile Pointer is @ %ld Position", ftell(fptr));
	
	fscanf(fptr, "%[^|]s", line); // will read up to | symbol
	fprintf(stdout, "\n\n%s\n", line);

	fseek(fptr,1,SEEK_CUR);
	fprintf(fptr, "S");
	printf("\nFile Pointer is @ %ld Position", ftell(fptr));
	
	rewind(fptr);
	fseek(fptr, 7, SEEK_CUR);
	fprintf(fptr, "ramjaya");
	printf("\nFile Pointer is @ %ld Position", ftell(fptr));

	fseek (fptr, -14, SEEK_CUR);
	
	//fprintf(fptr, "TES");
	//while(fgets(line,1024,fptr))
		//puts(line);
	fprintf(fptr,"vivanRS");
	printf("\nFile Pointer is @ %ld Position", ftell(fptr));

	fclose(fptr);
	printf("\n\n");
	return 0;
}

