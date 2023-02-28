#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct  Data
{

	int a;
	float b;
	char name[20];
};

int main()
{

     struct  Data data1;

     

     data1.b = 25.4;
     data1.a = 20;
     strcpy(data1.name,"shilpa");

     

     
     printf("Memory used by Data: %d", sizeof(data1));
     

     printf("\ndata1.a = %d", data1.a);

     
     printf("\ndata1.b = %f", data1.b);

     
     printf("\ndata1.name = %s", data1.name);


     printf("\n\n");

     return EXIT_SUCCESS;
}




