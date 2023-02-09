#include<stdio.h>
#include<ctype.h>
int main()
{
	int i;
	printf("All graphics characters in c program\n");
	for(i=0;i<128;i++)
	{
		if(isgraph(i)!=0)
			printf("%c\n",i);
	}
	return 0;
}
