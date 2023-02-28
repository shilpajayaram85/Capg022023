#include<stdio.h>
#include<stdlib.h>
#include<myHeader.h>



int main()
{
	int stack[MAX];
	int TOP;
	int x;
	int choice;
	TOP = -1;

	while(1)
	{
		printf("\n1.PUSH\n2.POP\n3.PEEK\n4.Display\n");
		printf("5.Check if stack is empty\n6.Check if stack is full\n7.Exit\n");
		printf("Enter your Choice:  ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				push(stack, &TOP);
				break;
			case 2:
				x=pop(stack, &TOP);
				if(x!=NULL)
					printf("\nPopped element is %d", x);
				break;
			case 3: 
				x=peek(stack ,TOP);
				if(x!=NULL)
					printf("\nTop Most element is %d", x);
				break;
			case 4:
				display(stack, TOP);
				break;
			case 5:
				if(isEmpty(TOP))
					printf("\nStack is empty");
				else
					printf("\nStack is not empty");
				break;
			case 6:
				if(isFull(TOP))
					printf("\nStack is Full");
				else
					printf("\nStack is not Full");
				break;
			case 7: 
				exit(EXIT_SUCCESS);

			default:
				printf("\nYou have entered wrong choice\n");
		}

	}
}
