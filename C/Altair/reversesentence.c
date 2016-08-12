//Revers the sentence like "I love you" to "you love I"
//Compiling:
// gcc reversesentence.c -o reversesentence
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define NUMBER_OF_WORDS 10

//Prototypes 
void ReverseSent (char *str);


int main()
{
	char buffer[100];
	const char EndOfLine[2] = "\n";
	char *token;
	
	while(1)
	{
		printf("Enter a sentence. bye to terminate\n");
		fgets(buffer, sizeof(buffer),stdin);
		//to delete "end of line" from buffer
		token = strtok(buffer, EndOfLine);
		
		if(strcmp(token,"bye") == 0)
		   break;
		   
		printf("Sentence before reverse is %s\n", buffer);
		ReverseSent(buffer);
	}
	return 0;
}

void ReverseSent (char *str)
{	
	const char WhiteSpace[2] = " ";
	char *token;
	char *words[NUMBER_OF_WORDS];
	int i=0;
	
	printf("Sentence after reverse is:\n");
	
	//To delimeter words and copy them to array *words[]
	token = strtok(str, WhiteSpace);
	printf("token = %s\n", token);
	words[i] = (char *)malloc(strlen("token") + 1);
	strcpy(words[i], token);
	printf("%s\n", words[i]);
	i++;
	while (token != NULL) {		
		token = strtok(NULL, WhiteSpace);
		printf("token = %s\n", token);
		words[i] = (char *)malloc(strlen("token") + 1);
		strcpy(words[i], token);
		printf("%s\n", words[i]);
		i++;
	}
	
	i--;
	
	//to print words[] by reverse.
	while (i>=0){
		printf("%s\n", words[i]);
		i--;
	}
}




