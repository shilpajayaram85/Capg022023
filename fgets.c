#include<stdio.h>
#include<string.h>
#define MAX 500

int main()
{
	char arr[MAX];
	printf("\n enter sentence:\n");
	fgets(arr,MAX,stdin);
	printf("sentence is : %s", arr);
	printf("Hello");
	return 0;
}
