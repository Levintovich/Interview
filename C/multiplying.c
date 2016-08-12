#include <stdio.h>

typedef unsigned int U32;
typedef unsigned char U8;

int multiply(U8 *, U8 *); //multiplying 2 8-bits numbers

int main(void)
{
	U32 result;
	U32 num1, num2;
	printf("Enter 2 numbers for multiplying. Less than 256.\n");
	scanf("%d %d", &num1, &num2); 	
	result = multiply((U8 *)&num1, (U8 *)&num2);
	printf("Result of multiplying is:%d\n", result);
} 

int multiply(U8 *reg1, U8 *reg2)
{
	U32 val1 =(U8) *reg1, val2 =(U8) *reg2;
	U8 mask = 0x01;
	U32 res = 0;
	U8 flag = *reg2;
	while (flag != 0)
	{
		if(val2 & mask)		
			res += val1;

		val1 <<= 1;
		flag >>= 1;
		mask <<= 1;
		
	}

	return res;
}
