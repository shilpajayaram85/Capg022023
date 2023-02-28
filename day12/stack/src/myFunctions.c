#include<myHeader.h>
#include<stdio.h>



  void push(int *s, int *TOP)

{
	if(isFull(*TOP))
	{
		printf("\n Stack OverFLow");
	}
	else
	{
		int x;
		printf("\nEnter the element to PUSH");
		scanf("%d",&x);

		*TOP+=1;
		s[*TOP] = x;
	}
	//return TOP;
}



  int pop(int *s, int *TOP)
{


	if(*TOP == -1)
	{
		printf("\nEmpty Stack!!");
		return NULL;
	}
	else
	{
		int x;

		x=s[*TOP];
		 
		*TOP=*TOP-1;

		return x;
	}
}



void display(int *s, int TOP)
{

	if(TOP == -1)
	{
		printf("\nEmpty Stack");
		return;
	}
	else
	{
		int it;
		for(it=0; it<=TOP; it++)
		       printf("%d  ", s[it]);
	}
}	





int isEmpty(int TOP)
{
	if(TOP==-1)
		return 1;
	else
		return 0;
}



int isFull(int TOP)
{
	if(TOP==MAX-1)
		return 1;
	else
		return 0;
}




int peek(int *s, int TOP)
{
	if(TOP==-1)
	{
		printf("\nEmpty Stack\n");
		return NULL;
	}
	else
	{
		return (s[TOP]);
	}	
}

