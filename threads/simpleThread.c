#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>



struct phonebookentry 
{
	char name[64];
	char phonenumber[32];
	char flags[16];
};

void *fetch(struct phonebookentry *arg)
{
struct phonebookentry *nbpe = (struct phonebookentry *)malloc(sizeof(struct phonebookentry));

	/* fetch value from a database */
	sleep(30);
	strcpy(nbpe->name, "shilpa");
	strcpy(nbpe->phonenumber, "9620403621");
	strcpy(nbpe->flags,"Done");
	if (nbpe != NULL)
		*arg = *nbpe;
	pthread_exit(0);
}
int main ()
{
	struct phonebookentry *pbe= (struct phonebookentry *) malloc(sizeof(struct phonebookentry));
	pthread_attr_t tattr;
	pthread_t helper;
	void *status;
	pthread_create(&helper, NULL, fetch, pbe);
	printf("Hello From Main\n");
	pthread_join(helper, &status);
	/* it’s now safe to use result */
	//pthread_exit(NULL);
	printf("Name: %s\n", pbe->name);
	printf("Phone Number: %s\n",pbe->phonenumber);
	printf("Flags : %s\n", pbe->flags);
	pthread_exit(NULL);
	return EXIT_SUCCESS;
}


