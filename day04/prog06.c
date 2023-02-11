#include<stdio.h>
int main()
{

   int number;

   printf("\nEnter any value between (3-7):  ");
   scanf("%d",&number);
   switch(number)
   {

   		case 3: 
			   printf("\nYou have entered %d number", number);
			   break;
		case 4:
		      printf("\nYou have entered %d number", number);
              break;
		case 5:
			  printf("\nYou have entered %d number", number);
			  break;
		case 6:
			 printf("\nYou have entered %d number", number);
			 break;
	    case 7:
			printf("\nYou have entered %d number", number);
			break;
		default:
		    printf("\nYou have entered a number which is out of range!");
	}


printf("\n\n");
	return 0;
}


