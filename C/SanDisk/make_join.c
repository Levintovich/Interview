//This program join 2 short variables a, b and returns integer 
// wit result: all bit is joined.
// a=1111, b=0000. Result will be 10101010

//Compile: gcc make_join.c -o make_join

#include <stdio.h>

unsigned int join (unsigned short a, unsigned short b);

int main(void)
{
	unsigned short a,b;
	unsigned int result;
	a = 0xffff, b = 0x0000;
	printf("a=0x%x, b = 0x%x\n", a, b);
	printf("Result = 0x%x\n", join(a,b));
	
	a = 0x0000, b = 0xffff;
	printf("a=0x%x, b = 0x%x\n", a, b);
	printf("Result = 0x%x\n", join(a,b));
	
	a = 0x00ff, b = 0xff00;
	printf("a=0x%x, b = 0x%x\n", a, b);
	printf("Result = 0x%x\n", join(a,b));
    
	return 0;
}

unsigned int join (unsigned short a, unsigned short b){
	unsigned int result=0;
	unsigned int x = (unsigned int)a;
	unsigned int y = (unsigned int)b;
	
	x = x|(x<<16);
	y = y|(y<<16);
	x = x&0xaaaaaaaa;
	y = y&0x55555555;	
	
	result = x|y;
	
	return result;
	
}
		   		   		  