/*
 *
 * control Statements
 *
 * if
 * if else
 * if else ladder
 * swith
 *
 * 1. Simple if
      
	  syntax:
	  
	  if(condition){
 	     statements;
       }
 *
 * 2. if-else
    syntax:

	if(condition){
 *      statements;
 *    }
 *  else
 *  {
 *
 *    statements;
 	}

 * 3. else if ladder

     syntax:

	   if(condition1){
	      cond1 statements;
		}
	   else if(condition2){
	   cond2 statements;
	   }
	   .....
	   else
	      default statement
 *   }
 *       
 * */

#include<stdio.h>
int main()
{

	/*int a=10,b=20;

    if(printf(" ")) // will print space and return 1 
		printf("\nA is biggest\n");

	if(a>b){
		printf("\nA is biggest\n");
	}
	else
	{
		printf("\nB is biggest\n");
	}

	 
	printf("\nBye\n");*/


	int speed=0;
	printf("\nEnter the speed you are riding: ");
	scanf("%d",&speed);

	if((speed>100) && (speed<150))
	{
		printf("\nFuel conusmed is more(less economy))");
		printf("\nWarning: Hitting a red Line\n Warning: Beware of speed breakers");
		printf("\nWarning: There is somebody waiting for you @ home");
	}
	else if((speed>60)&&(speed<100))
	{
		printf("\nFuel consumed is moderate");
		printf("\nWarning: Try to reduce the speed for economy");
	}
    else if((speed>30)&&(speed<60))
	{
		printf("\nEconomical Ride");
		printf("\nThank You for riding in a safe zone");
	}
	else if((speed>10)&&(speed<30))
	{
	 printf("\nFuel consumed is more as you are riding with the first gear");
	 printf("\nChange the gear");
	}
	else
	{
	  printf("\nyour bike is in still mode");
	  printf("or not started\n");
	  printf("\nStart Your Engine");
	}
	printf("\nThank You for using the S/W\n");
	return 0;
}

