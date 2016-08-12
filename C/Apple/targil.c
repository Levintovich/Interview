#include <stdio.h>
#include <string.h>

void ReverseString(char *buf, int first, int last);
void ReverseWords(char *buf);

int main(void)
{
    char buffer[50] = {'\0'};
	while(strcmp(buffer, "-1")){
    	printf("Enter the sentence. -1 to end\n");
		gets(buffer);	
		buffer[strlen(buffer)] = '\0';
		ReverseString(buffer, 0, (strlen(buffer)-1));
		ReverseWords(buffer);
		printf("After reversing words: %s\n", buffer);
	}
	
	printf("Good Bye!\n");
		  
	return 0;
}

void ReverseString(char *buf, int first, int last)
{
    char temp;
	while(first < last){
        printf("first = %d last = %d\n", first, last);

        temp = buf[first];
        printf("temp = %c\n", temp);
        buf[first] = buf[last];
        buf[last] = temp;
        first++;
        last--;
    }
}

void ReverseWords(char *buf)
{
    char current_char;
    int first = 0;
    int current = 0;
    while(current < strlen(buf)){
        current_char = buf[current];
        if (current_char == ' '){
            printf("Current state:%s\n", buf);
            ReverseString(buf[first], first, current - 1);
            printf("Current state:%s\n", buf);
            current++;
            first = current;
        }
        else{
            current++; 
        }
    }
    printf("first = %d current = %d\n", first, current);  
    ReverseString(buf[first], first, current - 1);    
}