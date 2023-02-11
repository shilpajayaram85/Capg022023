#include<stdio.h>


int main()


{
	/*long nc=0;

	while(getchar()!=EOF)
		nc++;
	printf("%ld\n",nc);	*/


/*	double nc;
	for(nc=0;getchar()!=EOF;++nc)
		;

	printf("%.0f\n",nc);*/

	int c,n1,blank,tab;

	n1=0;
	while((c=getchar())!=EOF)
	{
		if(c=='\n')
			++n1;
		if(c==' ')
			blank++;
		if(c=='\t')
			tab++;
	}

	printf("line count=%d\n",n1);
	printf("Blank count=%d\n",blank);
	printf("Tab count=%d\n",tab);

	printf("\n\n");

	return 0;
}

