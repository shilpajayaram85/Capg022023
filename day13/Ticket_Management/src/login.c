
#include<login.h>
#include<persons.h>
#include<string.h>

int checkCird(PERSON *P, int uid,char *p, int *pid)
{

	int flag=0;
	if(uid == P->uid)
		flag++;
	if(strcmp(p,P->passwd) == 0)
		flag++;
	if(flag==2)
	{
	   *pid = P->pid;	
	   return 0;
	 }
	else
		return 1;
}
