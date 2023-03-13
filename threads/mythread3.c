#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int mails = 0;
pthread_mutex_t mutex;
void* routine();
int main()
{
	pthread_t p1, p2, p3, p4;

	pthread_mutex_init(&mutex, NULL);

	if(pthread_create(&p1, NULL, &routine, NULL)!=0){
		return 1;
	}
	if(pthread_create(&p2, NULL, &routine, NULL)!=0){
		return 2;
	}
	if(pthread_create(&p3, NULL, &routine, NULL)!=0){
		return 1;
	}
	if(pthread_create(&p4, NULL, &routine, NULL)!=0){
		return 2;
	}
	if(pthread_join(p1, NULL)!=0){
		return 3;
	}

	if(pthread_join(p2, NULL)!=0){
		return 4;
	}
	if(pthread_join(p3, NULL)!=0){
		return 3;
	}

	if(pthread_join(p4, NULL)!=0){
		return 4;
	}
	




	
		pthread_mutex_destroy(&mutex);
	printf("\nNumber of Mails : %d\n", mails);
	return EXIT_SUCCESS;
}
void* routine(){
int i;
for(i = 0; i < 1000000; i++){
	pthread_mutex_lock(&mutex);
	mails++;
	pthread_mutex_unlock(&mutex);
}
}
