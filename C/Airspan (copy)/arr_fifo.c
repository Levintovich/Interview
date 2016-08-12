//FIFO implementation by using array
//gcc arr_fifo.c -o arr_fifo

#include <stdio.h>

#define MAX_SIZE 10

// Define TRUE and FALSE if they have not already been defined
#ifndef FALSE
#define FALSE (0)
#endif
#ifndef TRUE
#define TRUE (!FALSE)
#endif

#endif // End of queue header

//Global variables

int head, tail;	// Declare global indices to head and tail of queue
int theQueue[MAX_SIZE];	// The queue

// List Function Prototypes
void InitQueue();             // Initialize the queue
void ClearQueue();            // Remove all items from the queue
int Enqueue(int);         	  // Enter an item in the queue
int Dequeue();               // Remove an item from the queue
int isEmpty();                // Return true if queue is empty
int isFull();                 // Return true if queue is full

int main(void)
{

	return 0;
}

//--------------------------------------------
// Function: InitQueue()
// Purpose: Initialize queue to empty.
// Returns: void
//--------------------------------------------
void InitQueue()
{
	head = tail = -1;
}

//--------------------------------------------
// Function: ClearQueue()
// Purpose: Remove all items from the queue
// Returns: void
//--------------------------------------------
void ClearQueue()
{
	head = tail = -1; // Reset indices to start over
}

//--------------------------------------------
// Function: Enqueue()
// Purpose: Enqueue an item into the queue.
// Returns: TRUE if enqueue was successful
//		or FALSE if the enqueue failed.
// Note: We let head and tail continuing 
//		increasing and use [head % MAX_SIZE] 
//		and [tail % MAX_SIZE] to get the real
//		indices.  This automatically handles
//		wrap-around when the end of the array
//		is reached.
//--------------------------------------------
int Enqueue(int val)
{
	// Check to see if the Queue is full
	if(isFull()) return FALSE;

	// Increment tail index
	tail++;
	// Add the item to the Queue
	theQueue[tail % MAX_SIZE] = val;
	return TRUE;
}

//--------------------------------------------
// Function: Dequeue()
// Purpose: Dequeue an item from the Queue.
// Returns: TRUE if dequeue was successful
//		or FALSE if the dequeue failed.
//--------------------------------------------
char Dequeue()
{
	int val;

	// Check for empty Queue
	if(isEmpty()){
		printf("Queue is empty\n");
		return -1;		
	}
	else
	{
		head++;
		val = theQueue[head % MAX_SIZE];		// Get character to return
		return val;				// Return popped number
	}
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: Return true if the queue is empty
// Returns: TRUE if empty, otherwise FALSE
// Note: C has no boolean data type so we use
//	the defined int values for TRUE and FALSE
//	instead.
//--------------------------------------------
int isEmpty()
{
	return (head == tail);
}

//--------------------------------------------
// Function: isFull()
// Purpose: Return true if the queue is full.
// Returns: TRUE if full, otherwise FALSE
// Note: C has no boolean data type so we use
//	the defined int values for TRUE and FALSE
//	instead.
//--------------------------------------------
int isFull()
{
	// Queue is full if tail has wrapped around
	//	to location of the head.  See note in
	//	Enqueue() function.
	return ((tail - MAX_SIZE) == head);
}
