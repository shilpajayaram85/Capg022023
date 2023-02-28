
#include <common.h>
#include <login.h>


int dispMain()
{
	int ch;
	printf("\nPress,");
	printf("\n1. SignUp\n2. SignIn\n3. Exit\n Choice: ");
	scanf("%d", &ch);
	return ch;
}

int signUP(PERSON *p)
{

 	int pid=getPDetails(p);

	return pid;
}

int signIN(PERSON *p, LOGIN *l,  int *pid)
{

    
		int flag = checkCird(p, l->uid, l->passwd, pid);
		return flag;
}

int tktBkgMenu()
{
	int ch;
	printf("\nPress,");
	printf("\n1. Book Ticket");
	printf("\n2. Print Ticket");
	printf("\n3. Go Back to Main Menu");
	printf("\n\nChoice: ");
	scanf("%d", &ch);

	return ch;
}
