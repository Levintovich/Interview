//To make reverse string without variables
#include <stdio.h>

void printReverse(char *);

int main(void)
{
	char str[20] = {'\0'};
	printf("Please enter a string\n");
	gets(str);
	printf("Reversed string is:\n");
	printReverse(str);
	printf("\n");
	
	return 0;
}

void printReverse(char *str)
{	
	if(*str == '\0')
		return;
	if(*(str + 1) == '\0'){
		printf("%c", *str);
		return;
	}
	else{
		printReverse(str + 1);
		printf("%c", *str);
	}
}