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
	while (first < last){
		temp = buf[first];
		buf[first] = buf[last];
		buf[last] = temp;
		first++; 
		last--;		
	}
}

void ReverseWords(char *buf)
{
	int first_pos = 0, last_pos = 0;
	while(last_pos < strlen(buf)){
		if (buf[last_pos] == ' '){
			ReverseString(buf, first_pos, last_pos - 1);
			last_pos++;
			first_pos = last_pos;
		}
		else
			last_pos++;
	}
	ReverseString(buf, first_pos, last_pos - 1);
}