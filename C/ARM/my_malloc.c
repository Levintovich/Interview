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
	
}

void my_free(void *ptr)
{
	void *new_ptr;
	new_ptr = (void *)(*((unsigned int *)ptr - 1));
	printf("Address %u is freeing\n", new_ptr);
	free(new_ptr);
	
}