#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lsize 1024

void split_words( char (*)[lsize],char *, int *);
void sort_words(char (*)[lsize], int);

int main()
{
	char *str;
	int i;

  	/*char **Words = (char **)malloc(20 * sizeof(char*));
	for(i=0; i<20; i++)
	  *(Words+i) = (char *)malloc(lsize*sizeof(char));*/
	
	char Words[20][lsize];

	int cWords = 0;
	int it;

	str = (char *) malloc(lsize*sizeof(char));
	
	

	fgets(str, lsize, stdin);

	//str[strlen(str)-1] = '\0';

	strcpy(str, strtok(str, "\n"));	
	puts(str);

	printf("\n\nBefore Sorting");

	split_words(Words,str, &cWords);
	
	for(it = 0; it<cWords; it++)
		printf("\n%s", Words[it]);

	printf("\n\nAfter Sorting");

	sort_words(Words, cWords);

	for(it = 0; it<cWords; it++)
		printf("\n%s", Words[it]);
	
	printf("\n\n");
	return EXIT_SUCCESS;
}

void split_words(char (*Words)[lsize],char *str, int *ptr)
{
	
	char *tokens = strtok(str, ",");
	
	int spaces = 0;
	
	int count = 0;

	while(tokens)
	{
	  
	  /*splits = realloc(splits, sizeof(char*) * ++spaces);

	  if(!splits)
	  	return splits;

	  splits[spaces-1] = tokens;*/
		
	   count++;
		
	   strcpy(Words[count-1],tokens);
	 
	   tokens = strtok(NULL, ",");
	}
	
	*ptr = count;
	
//	return splits;

}


void sort_words(char (*words)[lsize], int c)
{

	int i,j;
	
	//int ilen = 0;
	//int jlen = 0;
	
	/*printf("\nIn function sort");

	printf("\n%d  ",c); 
	for(it1=0; it1<c; it1++)
	   printf("\n%s", words[it1]);*/

	
	char *temp = (char *) malloc (lsize*sizeof(char));

	for(i = 0; i<c; i++)
	{
	  for(j = 0; j<c; j++)
	  {
	    memset(temp,'\0', lsize);
		
		if(strcmp(words[i],words[j])>0)
		{
			
			strcpy(temp,words[i]);
			strcpy(words[i],words[j]);
			strcpy(words[j],temp);
			
			/*ilen = strlen(words[i]);
			jlen = strlen(words[j]);
			memcpy(temp, words[i],ilen);
			temp[ilen] = '\0';
			memcpy(words[i],words[j],jlen);
			words[jlen]='\0';
			memcpy(words[j],temp,strlen(temp));;
			words[strlen(temp)] = '\0';*/
		}
	  }
	}
}

