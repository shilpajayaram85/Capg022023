#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int count = 0;

void *show_var(void *name)
{

	printf("%s %p\n", name,&name);
	count++;
	return NULL;
}

int main()
{

	pthread_t th;
	show_var("orig");
	show_var("orig2");
	pthread_create(&th, NULL, show_var, "new");
	sleep(1);
	printf("%d\n", count);
	return 0;
}
