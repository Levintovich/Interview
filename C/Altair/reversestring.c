//Revers the string like "abcd" to "dcba"
#include <stdio.h>
#include <string.h>

//Prototypes 
void ReverseString (char *str);
void ReverseDoubleString (char *str);

int main()
{
	char buffer[15];	
	
	while(1)
	{
		printf("Enter a string. bye to terminate\n");
		//fgets(buffer, sizeof(buffer),stdin);
		scanf("%s", buffer);
		
		if(strcmp(buffer,"bye") == 0)
		   break;
		   
		printf("String before reverse is %s\n", buffer);
		ReverseString(buffer);
		ReverseDoubleString (buffer);

	}
	return 0;
}

void ReverseString (char *str)
{
	char *temp = str;
	
	printf("String after reverse is:\n");
	temp += strlen(str);
	while (temp >= str){
		printf("%c", *temp);
		temp--;e
	}
	printf("\n");
}

void ReverseDoubleString (char *str)
{
	char *temp = str;
	
	printf("String after double reverse is:\n");
	temp += strlen(str);
	while (temp >= str){
		printf("%c", *temp);
		printf("%c", *temp);
		temp--;
	}
	printf("\n");
}


