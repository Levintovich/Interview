#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//Using alligned to 16 malloc

void *my_malloc(unsigned int bytes);
void my_free(void *ptr);

int main(void)
{
	unsigned int temp = (unsigned int *)my_malloc(1000);
	printf("New alligned address is %u\n", temp);
	my_free(temp);
	
	return 0;	
}

void *my_malloc(unsigned int bytes)
{
	void *ptr1, *ptr2;
	ptr1 = (void *)malloc(bytes + 16 + sizeof(int));
	if(ptr1 == NULL){
		printf("No sufficient memory!!!\n");
		return 1;
	}
	printf("Allocated memory address is %u\n", ptr1);
	
	unsigned int addr = ptr1 + 16 + sizeof(int);
	ptr2 = (void *)(addr - addr % 16);
	*((unsigned int *)ptr2 - 1) = (unsigned int *)ptr1;
	return ptr2;
}

void my_free(void *ptr)
{
	return ((void *)(*((unsigned int *)ptr - 1)));
	
}
