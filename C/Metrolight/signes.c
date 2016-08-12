#include <stdio.h>

int main(void)
{
	unsigned char a = 150;
	char b = 150;
	unsigned int c = 150;
	int d = 150;
	
	
	printf("Numbers representations in hex\n");
	printf("unsigned char a = 0x%X\n", a);
	printf("char b = 0x%X\n", b);
	printf("\n");
	printf("Numbers representations in decimal\n");
	printf("unsigned char a = %d\n", a);
	printf("char b = %d\n", b);
	
	printf("Numbers representations in hex\n");
	printf("unsigned char c = 0x%X\n", c);
	printf("char d = 0x%X\n", d);
	printf("\n");
	printf("Numbers representations in decimal\n");
	printf("unsigned char c = %d\n", c);
	printf("char d = %d\n", d);
	
	a = a << 7;
	b = b << 7;	
	printf("\n");
	printf("After shifting left in hex\n");
	printf("unsigned char a = 0x%X\n", a);
	printf("char b = 0x%X\n", b);
	
	a = 150, b = 150;
	a = a >> 7;
	b = b >> 7;	
	printf("\n");
	printf("After shifting right in hex\n");
	printf("unsigned char a = 0x%X\n", a);
	printf("char b = 0x%X\n", b);
	c = 0xF0000000, d = 0xF0000000;
	printf("unsigned char c = %d\n", c);
	printf("char d = %d\n", d);
	printf("unsigned char c = 0x%X\n", c);
	printf("char d = 0%X\n", d);
	
	c = c >> 31;
	d = d >> 31;
	printf("unsigned char c = %d\n", c);
	printf("char d = %d\n", d);
	printf("unsigned char c = 0x%X\n", c);
	printf("char d = 0%X\n", d);
	
	return 0;
}