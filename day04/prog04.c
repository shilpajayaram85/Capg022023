#include<stdio.h>
#include<string.h>

int main()
{
	char str[100];//= "This is to test string";//declera with initilization
	
	//strcpy(str,"This is to test string");

	fgets(str,100,stdin);
	
	//printf("\n%s",str);
	
	//printf("\nLength is %ld\n",strlen(str));
	
	puts(str);

	printf("str[0]=%c\tstr[1]=%c\n",str[0],str[1]);

	printf("\nstr[strlen-1]=%c and its ascii value=%d",str[strlen(str)-1],str[strlen(str)]-1);

	printf("\n\n");

	return 0;
}

	
