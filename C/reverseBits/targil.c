/*
//This program takes the integer number and reverses their bits
*/

#include <stdio.h>
#include <string.h>

void printBits(int *ptr);
void reverseBits(int num);

int main(void)
{
	int num;
	while(1){
		printf("Please enter a number. To end press -1\n");
		scanf("%d", &num);
		if (num == 0xffffffff)
			break;
		printBits(&num);
		reverseBits(num);
	}
	printf("Good Bye!\n");
	return 0;
}

void printBits(int *ptr)
{
	int bynary_arr[32] = {0};
	int i;
	for(i = 0; i < 32; i++){
		if(*ptr & (1 << i)) 
			bynary_arr[i] = 1;
		else
			bynary_arr[i] = 0;
	}
	printf("Binary representation:\n");
	for (i = 31; i >= 0; i--){
		printf("%d", bynary_arr[i]);
	}
	printf("\n");
}

void reverseBits(int num)
{	
	num = (num & 0xaaaaaaaa >> 1) | (num & 0x55555555 << 1);
	num = (num & 0xcccccccc >> 2) | (num & 0x33333333 << 2);
	num = (num & 0xf0f0f0f0 >> 4) | (num & 0x0f0f0f0f << 4);
	num = (num & 0xff00ff00 >> 8) | (num & 0x00ff00ff << 8);
	num = (num >> 16) | (num << 16);
}
