#include<stdio.h>
#include<stdlib.h>


int main()
{
	enum Week {MON=1,TUE,WED,THU,FRI,SAT};

	enum bool { False=0 ,TRUE =1};

	enum Week day1;


	day1=WED;
	
	enum bool flag=TRUE;

	printf("\nflag= %d",flag);

	printf("day1 - %d", day1);

	printf("\n\n");

	return EXIT_SUCCESS;
}

