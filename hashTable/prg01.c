#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10


typedef struct {
	char name[MAX_NAME];
	int age;
	//... add other struff later
}person;

unsigned int hash(char *name){
	int length = strnlen(name, MAX_NAME);
	unsigned int hash_value = 0;
	int i;
	for(i = 0; i < length; i++)
	{
		hash_value += name[i];
		hash_value = (hash_value * name[i]) % TABLE_SIZE;
	}
	return hash_value;
}
int main()
{
	printf("Jacob => %u\n", hash("Jacob"));
	printf("Natalie => %u\n", hash("Natalie"));
	printf("Sara => %u\n", hash("Sara"));
	printf("Mpho => %u\n", hash("Mpho"));
	printf("Teboqo => %u\n", hash("Teboqo"));
	printf("Ron => %u\n", hash("Ron"));
	printf("Jane => %u\n", hash("Jane"));

	printf("Maren => %u\n", hash("Maren"));
	printf("Bill => %u\n", hash("Bill"));
	return EXIT_SUCCESS;
}
