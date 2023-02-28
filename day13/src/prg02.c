#include<stdio.h>
#include<stdlib.h>
#include<string.h>

	struct Car
	{
		char Brand[25];
		char Model[25];
		int Year;
		float Cost;
	};


	void dispCar(struct Car *c);

int main()
{

	struct Car c1,c2;



	printf("\nEnter Brand Model Year Cost of the car\n");
	scanf("%s%s%d%f", c1.Brand,c1.Model,&c1.Year,&c1.Cost);

	c2=c1;

	dispCar(&c1);
	dispCar(&c2);

	printf("\n\n");
	return EXIT_SUCCESS;
}

void dispCar(struct Car *c)
{

	printf("\nBrand:%s",c->Brand);
	printf("\nModel:%s",c->Model);
	printf("\nYear:%d",c->Year);
	printf("\nCost:%f",c->Cost);
}

