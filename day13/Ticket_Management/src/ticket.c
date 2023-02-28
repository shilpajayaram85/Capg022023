#include<stdio.h>
#include<ticket.h>


int bookTkt(TICKET *t, int pid)
{


	int tktid=0;
	t->pid = pid;
	printf("\nEnter ,");
	printf("\nBooking Date");
	scanf("%s", t->bdate);

	printf("\nTraveling Date");
	scanf("%s", t->tdate);

	printf("\nFrom: ");
	scanf("%s",t->src);

	printf("\nTo: ");
	scanf("%s",t->dest);

	printf("\nSeat No: ");
	scanf("%d",&t->sno);

	t->status = 1;
	tktid = 1111;
	t->bid = tktid;

	return tktid;
}


void printTktDet(TICKET *t, int tktid)
{

	printf("\n\n=======Ticket Details=========\n\n");
	printf("\nBooking ID: %d", t->bid);
	printf("\nPID: %d", t->pid);
	printf("\nBooking Date: %s", t->bdate);
	printf("\nTraveling Date: %s", t->tdate);
	printf("\nFrom: %s", t->src);
	printf("\nTo: %s", t->dest);
	printf("\nSeat No: %d", t->sno);
	if(t->status == 1)
		printf("\nStatus: %s", "Booked");
	else
		printf("\nStatus: %s", "Cancelled");
	printf("\n\n");



}
