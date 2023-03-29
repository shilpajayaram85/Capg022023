include <file1.h>

int add(int a, int b)
{
	return (a + b);
}

int mul(int a, int b)
{
	return (a * b);
}

float div1(int a, int b)
{
	if(b == 0)
		return 0.0;
	else
		return ((float)a/(float)b);
}

int validName(char *name)
{

	return 1;
}
char *getname()
{
	char *name ="\0";
	return name;

}
