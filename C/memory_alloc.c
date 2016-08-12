//Storage allocator implementation for char
// gcc memory_alloc.c -o memory_alloc
#include <stdio.h>
#include <string.h>

typedef unsigned int uint;

#define BUFFERSIZE  10000
#define SIZE_OFFSET(X)    (X+0)   //Field to save an allocated memory size
#define PREV_OFFSET(X)    (X+1)   //Previous address of the allocated memory
#define NEXT_OFFSET(X)    (X+2)   //Next free address
#define MEMORY_OFFSET(X)  (X+3)  //This address will be returned for user



//Global variables
char buffer[BUFFERSIZE];
char *currptr = NULL;
uint used_memory = 0;

//Prototypes

char *allocate_block(uint nbytes); //allocate memory block of nbytes size
void free(char *p); // to free an allocated memory

int main()
{
    char *buffer1, *buffer2, *buffer3, *buffer4;
	
	printf("Address of buffer is:%d\n", (int)buffer);
    buffer1 = (char *)allocate_block(9995);
	printf("Address of allocated memory is:%d\n", (int)buffer1);
    buffer1 = (char *)allocate_block(300);
	printf("Address of allocated memory is:%d\n", (int)buffer1);
    printf("Next free block is:%d\n", (uint)*currptr);
    return 0;
}

char *allocate_block(uint nbytes)
{
    //char *offset = NULL;
    uint *offset=0;    
    uint value;
    printf("Trying to allocate %d bytes\n",nbytes);
    if((used_memory + nbytes + 12) > BUFFERSIZE){
        printf("No suficient memory\n");
        return NULL;
    }
    used_memory += (nbytes + 12);
    if(currptr == NULL){ //1-st memory allocating
        currptr = buffer; //getting offset
        offset = (uint *)buffer;
        *(SIZE_OFFSET(offset)) = (uint)nbytes; //
        *(PREV_OFFSET(offset)) = (uint)buffer;
        *(NEXT_OFFSET(offset)) = (uint)(MEMORY_OFFSET(offset) + nbytes);
        printf("Address of Size field is %d\n", (uint)SIZE_OFFSET(offset));
        printf("Address of Prev field is %d\n", (uint)PREV_OFFSET(offset));
        printf("Address of Next field is %d\n", (uint)NEXT_OFFSET(offset));
        printf("Address of Memory field is %d\n", (uint)MEMORY_OFFSET(offset));
        value = *(SIZE_OFFSET(offset));
        printf("Size field is %d\n", value);
        
        //currptr = (uint*)*(NEXT_OFFSET(offset));
        return MEMORY_OFFSET(offset);
    }
}

void free(char *p)
{
    
}
