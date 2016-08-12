#include <stdio.h>
#include <string.h>

#define MAX_SIZE 5
int FIFO[MAX_SIZE];
int _head, _tail;

void Reset_FIFO(void);
int isEmpty(void);
void PrintFIFO(void);
void PrintHelp(void);
int Pop(void);
void Push(int value);
int isFull(void);

int main(int argc, char *argv[])
{
	int val;
	char command[6] = {'\0'};	
	Reset_FIFO();
	PrintHelp();
	while(1){
		if (scanf("%s", command)){
			if(!strcmp(command, "exit")){
				printf("GoodBye!\n");
				return 0;
			}
			else if(!strcmp(command, "help")){
				PrintHelp();
				printf(">");
			}
			else if(!strcmp(command, "print")){
				PrintFIFO();
				printf(">");
			}
			else if(!strcmp(command, "reset")){
				Reset_FIFO();
				PrintFIFO();
				printf(">");
			}
			else if(!strcmp(command, "pop")){
				Pop();
				printf(">");
			}
			else if(!strcmp(command, "push")){
				int val;
				scanf("%d", &val);
				Push(val);
				printf(">");
			}
			else
				printf("Unknown command\n>");
		}
	}
	
}

void Reset_FIFO(void)
{
	_head = _tail = -1;
}

int isEmpty(void)
{	
	return(_head == _tail );
}

int isFull(void)
{	
	return ((_tail - MAX_SIZE) == _head);
}

void PrintFIFO(void)
{
	if(isEmpty())
		printf("FIFO is empty.\n");
	else {
		int i;
		printf("FIFO:\n");
		if (_head < 0){
			for(i = 0; i <= _tail; i++)
				printf("%d ", FIFO[i]);
		}
		else{
			for(i = _head; i <= _tail; i++)
				printf("%d ", FIFO[i]);
		}
		printf("\n");
	}
}
		   
void PrintHelp(void)
{
	printf("HELP MENU:\n");
	printf("Please make the following commands:\n");
	printf("	help - Help Menu\n");
	printf("	reset - Reset the FIFO\n");
	printf("	print - Print the FIFO\n");
	printf("	push [val] - To push value into the FIFO\n");
	printf("	pop [val] - To pop value from the FIFO\n");
	printf("	exit - Exit the program\n");
	printf("\n>");
}



int Pop(void)
{
	if(isEmpty()){
		printf("FIFO is empty.\n");
		return 0xffffffff;
	}
	printf("_head = %d, _tail = %d\n", _head, _tail); 	
	_head++;
	int val = FIFO[_head % MAX_SIZE];
	printf("Value is %d out\n");
	printf("_head = %d, _tail = %d\n", _head, _tail); 
	printf("Line = %d\n", __LINE__); 
	PrintFIFO();
	return val;
}

void Push(int value)
{
	if(isFull()){
		printf("FIFO is full.\n");
		return;
	}
	printf("FIFO status: %d\n",isEmpty());	
		//FIFO is not empty
		_tail++;
		FIFO[_tail % MAX_SIZE] = value;		
		PrintFIFO();	
}