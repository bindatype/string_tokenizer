#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc,char **argv)
{
	char *token = *(argv+1);
	int comma_array[100];
	int hyphen_array[100];
	int j=0;
	int k=0;

	for (int i = 0;i<strlen(token)+1;i++)
	{
		printf("%c\n",*(token+i));
		if (*(token+i) == 44)
			comma_array[j++]=i;
		if (*(token+i) == 45)
			hyphen_array[k++]=i;

	}

	char **chunk = malloc( (j+1)* sizeof(char*));

	int sum = 0;

	printf("\tIndex Location Character \n");
	for (int i = 0;i<j;i++)
	{
		printf("Comma:  %d \t%d \t%c\n",i,comma_array[i],token[comma_array[i]]);
		*(chunk+i) = token+sum;
		sum = token[comma_array[i]];
	}

	for (int i = 0;i<k;i++)
	{
		printf("Hyphen: %d \t%d \t%c\n",i,hyphen_array[i],token[hyphen_array[i]]);
	}

	printf("\n");
	return 0;
}
