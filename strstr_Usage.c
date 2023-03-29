#include <string.h>
#include <stdio.h>
 
int main(void)
{
   char *string1 = "needle in a haystack bla bla bla";
   char *string2 = "in";
   char *result;
 
   result = strstr(string1,string2);
   if(result)
   {
   		printf("\nThe Search String is found in %d\n", result);	
		

   }
   else
   {
   	printf("\nThe Search String is not Found\n");
   }

   printf("\n\n");
   return EXIT_SUCCESS;
 
}
