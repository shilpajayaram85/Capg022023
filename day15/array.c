#include <stdio.h>

int main()
{
	int a=10;
	int b[2]={20,30};
	int c=40;

	printf("\n%d %d\n",b[2],b[-1]);
	printf("\n%d %d %d %d\n", b,&b[1],&c,&b[-2]);
	return 0;
}
