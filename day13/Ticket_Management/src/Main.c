#include<stdio.h>
#include<stdlib.h>

#include<persons.h>
#include<common.h>
#include<ticket.h>
#include<login.h>

int main()
{
	
	
	PERSON p;
	LOGIN l;
	TICKET t;
	int pid = 0, lflag = 0;
	int tktid = 0;
	int flag = 0;

	while(1)
	{
	switch(dispMain())
	{
		case 1: 
			   pid = signUP(&p);
			   printPDetails(&p);
			   break;
		case 2:
				printf("\nEnter, ");
				printf("\nUID:  ");
				scanf("%d", &l.uid);
				printf("\nPassword: ");
				scanf("%s",l.passwd);
				lflag = signIN(&p,&l,&pid);
				if(lflag)
					printf("\nLogin Unsuccessfull\n");
				else
				{
					printf("\nLogin Success!\n");
					switch(tktBkgMenu())
					{
						case 1:
								tktid = bookTkt(&t, pid);
								break;
						case 2: 
								printTktDet(&t, tktid);
								break;
						case 3: 
								flag = 1;
								break;

						default: 
								printf("\nWrong Choice");
					}
				 if(flag == 1)
				        break;
				}
										
				break;
		case 3: exit(EXIT_SUCCESS);
				break;
		default:
				printf("You have entered a wron choice\n");
	}
  }
}
