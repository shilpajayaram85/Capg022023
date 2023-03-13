#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int x =2;

void* routine1();
void* routine2();
int main()
{

	pthread_t t1,t2;
	if(pthread_create(&t1, NULL, &routine1, NULL)!=0){
		return 1;
	}
	if(pthread_create(&t2, NULL, &routine2, NULL)!=0){
		return 2;
	}
	if(pthread_join(t1,NULL) !=0){
		return 3;
	}
	if(pthread_join(t2,NULL)!=0){
		return 4;
	}

	return EXIT_SUCCESS;
}

void* routine1(){
	//sleep(2);
	x = x + 2;
	printf("\nHello from Threads\n");
	printf("\nProcess id %d\n", getpid());
}
void* routine2(){
	//sleep(2);
	printf("\nValue of x: %d\n", x);
}
