#include<stdio.h>

ind add(int a, int b)
{
	return (a+b);
}

int sub(int a,int b)
{
	if(a>=b)
		return(a-b);
	else 
		return (b-a);
}


int mul(int a,int b)
{

	return (a*b);
}


double mul(int a,int b)
{
	if(a>=b)
		return ((double)a/(double)b);
	else
		return ((double)/(double)a);
}
