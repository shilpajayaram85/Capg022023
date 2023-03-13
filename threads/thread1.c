#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *display(void *ptr)
{
	int *ptr1 = (int *)ptr;
	int count = *ptr1;
	while(count >=0)
	{
		printf("\nThie is a Cprogramming class");
		sleep(1);
		count --;
	}

}
		
int main()
{
	pthread_t tid;
	int a = 10;
	printf("\nMain Before thread \n");
	pthread_create(&tid, NULL, display, &a);
	pthread_join(tid,NULL); //help us to execute the thread
	
	pthread_join(tid,NULL); 
	//restrict to join with same pid if it is already joined
	
	printf("\nMain after thread is done\n");
	printf("\n\n");

	return 0;
}
