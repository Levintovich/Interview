//Convert Little Endian to Big Endian
#include <stdio.h>

unsigned int htonl(volatile int *);

unsigned int num = 0x12345678;
#define REG &num

void main()
{
	printf("Register before htonl is:0x%x\n", *REG);	
	printf("Register after htonl is:0x%x\n", htonl(REG));

}

unsigned int htonl(volatile int *preg)
{	
	unsigned int temp = *preg<<24;	
	temp |= ((*preg<<8) & 0x00FF0000);
	temp |= ((*preg>>8) & 0x0000ff00);
	temp |= ((*preg>>24) & 0x000000ff);
	return temp;
}
