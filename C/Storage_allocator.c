//Storage allocator implementation for char
// gcc Storage_allocator.c -o Storage_allocator
#include <stdio.h>
#include <string.h>

#define BUFFERSIZE  10000

typedef unsigned int uint;

//Global variables
char buffer[BUFFERSIZE];
char *bufptr = buffer;
uint used_memory = 0;

struct header {
    struct header *next; //Next free block
    uint size; //Size of the free block
};
typedef struct header Header;

Header *base = (Header *)buffer; // 
Header *freep = NULL; //start of free list

//Prototypes

char *allocate_block(uint nbytes); //allocate memory block of nbytes size
void free(char *p); // to free an allocated memory

int main()
{
    char *buffer1, *buffer2, *buffer3, *buffer4;
	
	//buffer1 = (char *)allocate_block(100);
	//printf("Address of allocated memory is:%d\n", (int)buffer1); 
    buffer1 = (char *)allocate_block(9995);
	printf("Address of allocated memory is:%d\n", (int)buffer1);
    buffer1 = (char *)allocate_block(300);
	printf("Address of allocated memory is:%d\n", (int)buffer1);
    return 0;
}

char *allocate_block(uint nbytes)
{
	Header *currptr, *prevptr;
    	uint curr_memory;
 	printf("Used memory is:%d\n", used_memory);
	printf("Trying to allocate %d bytes\n",nbytes);
	if(freep == NULL){
		base->next = (Header *)base;
		base->size = 0;
		freep = (Header *)base;		
	}
    //Checking the first allocated memory condition
    if ((freep->next == base)&&(freep->size == 0)){
        curr_memory = used_memory + nbytes + sizeof(Header);
        printf("current memory is %u\n", curr_memory);
        if (curr_memory <= BUFFERSIZE){
            currptr = freep + nbytes + sizeof(Header);
            currptr->next = base;
            used_memory += nbytes + sizeof(Header);
            freep->next = currptr;
            return (char *)currptr;            
        }
        else{
            printf("No sufficient memory!\n");
            return NULL;
        }
    }
	return (char *)base;
}

void free(char *p)
{
}
