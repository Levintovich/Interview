//Implementaion Queue by array. Using multithreading.
// gcc queue.c -lpthread -o queue

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

#define N 10
//Global variables

int Arr[N];
int count = 0;
int rear = -1, front = -1;


//Prototypes
int isEmpty(void);
int isFull(void);
void QueueStatus(void);
void *write_queue(void *arg);
void *read_queue(void *arg); 

int main(void)
{
	pthread_t write_thread_id;
	pthread_t read_thread_id;

	int write_arg;
	int read_arg;

	while(1)
	{
		if(count == 10)	
			count=0;
		write_arg = count;
		count++;
		pthread_create (&write_thread_id, NULL, &write_queue, &write_arg);	
	//	pthread_create (&read_thread_id, NULL, &read_queue, &read_arg);
		sleep(3);
		QueueStatus();	
	}
	return 0;
}

int isEmpty(void)
{
	if((rear == -1)&&(front == -1))
		return 1;
	return 0;
}

int isFull(void)
{
	printf("rear = %d", rear);
	if(rear == sizeof(Arr)-1)
	{
		printf("The Queue is full!\n");
		return 1;
	}
	return 0;
}

void QueueStatus(void)
{
	int i;
	printf("***********************************************\n");
	printf("front = %d, rear = %d, count = %d\n", front, rear, count);
	for (i=0;i<10;i++)
		printf("%d ", Arr[i]);
	printf("\n");

}


void *write_queue(void *arg)
{
	int *param = (int *)arg;
	printf("Write to queue:%d\n", *param);
	printf("function:%s, line is %d, rear = %d\n", __FUNCTION__, __LINE__, rear);
	if(rear == sizeof(Arr)-1)
	{
		printf("The Queue is full!\n");
		return;
	}
	
	if ((rear == -1)&&(front == -1)){
		front = 0;
		rear = 0;
		Arr[rear]= *param;
	}
	else {
		rear = (rear+1)%sizeof(Arr);
		Arr[rear]= *param;
	}
	
}
		
void *read_queue(void *arg)
{
	int val;
	if((rear == -1)&&(front == -1)){
		printf("Queue is empty\n");
		return;
	}
	if(front == rear){
		front = -1;
		rear = -1;
	}
	else{
		front = (front+1)%sizeof(Arr);
	} 
	printf("Read from queue:%d\n", Arr[front]);
	arg = (void *)Arr[front];
}
