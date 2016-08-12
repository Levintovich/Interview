//Revers the sentence like "I love you" to "you love I"
//Compiling:
// gcc reversewords.c -o reversewords
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
	words[i] = (char *)malloc(strlen(token) + 1);
	strcpy(words[i], token);
	i++;
	while (token != NULL) {		
		token = strtok(NULL, WhiteSpace);
		if(token != NULL){
			words[i] = (char *)malloc(strlen(token) + 1);
			strcpy(words[i], token);
			i++;
		}		
	}
	
	i--;
	
	//to print words[] by reverse.
	while (i>=0){
		printf("%s ", words[i]);
		i--;
	}
	printf("\n");
}




