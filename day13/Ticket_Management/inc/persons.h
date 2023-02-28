#ifndef PERSONS_H
#define PERSONS_H
struct person
{
	int pid;
	char name[20];
	char emailid[20];
	int phno;
	char gender;
	int uid;//login id
	char passwd[20];
	int age;
	char address[50];
};

typedef struct person PERSON;

int getPDetails(PERSON *);
void printPDetails(PERSON *);
int getPID(PERSON *, int); //struct and uid

#endif

