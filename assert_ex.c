#include<assert.h>
#include<stdio.h>
int main()
{
 int a;
 short int b;
 long long int c;

 double d1;
 short  d2;
 printf("\nsize of integer is %zu\n",sizeof(a));
 printf("\nSize of short integer is %zu\n",sizeof(b));
 printf("\nSize of long integer is %zu\n",sizeof(c));
 printf("\nSize of double %zu\n ",sizeof(d1));
 printf("\nsize of double short %zu\n", sizeof(d2));

/* scanf("%d",&a);
 assert(a>=10);
 printf("Integer Entered is %d\n",a);*/
 return 0;
}
