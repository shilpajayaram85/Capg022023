#include<myHeader.h>
#include<string.h>
#include<stdio.h>

 void getEname(char (*eName)[BUFF], int row)
{

	int it;
	//printf("\nEnter %d Names:\n",row);
	for(it=0;it<row;it++)
	{
	  //printf("\nEnter name for EMP %d: ",it+1);	
	  fgets(eName[it],BUFF,stdin);
	  eName[it][strlen(eName[it])-1]='\0';
	 }
}


void dispEname(char (*eName)[BUFF], int row)
{
	int it;

	for(it=0;it<row;it++)
	{
		printf("\nEmp Name : %s", eName[it]);
	}
}


void sortEname(char (*eName)[BUFF], int row)
{
	int it1,it2;
	char temp[BUFF];

	for(it1=0;it1<row;it1++)
	{
		for(it2=it1;it2<row;it2++)
		{
			if(strcmp(eName[it1],eName[it2]))
				{
					strcpy(temp,eName[it2]);
					strcpy(eName[it2],eName[it1]);
					strcpy(eName[it1],temp);
				}
		}
	}

	printf("\nNames Sorted");
}
