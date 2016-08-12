#include <stdio.h>

void find_number(int index);

int main(int argc, char *argv[])
{
	find_number(4); /*finds number xxxxx where xxxxx4 * = 4xxxxx 
					  where xxxx is some number represenation
					*/	
	return 0;
}

void find_number(int index)
{
	int	A[10] = {0,0,0,0,0,0,0,0,0,0}; //saves number xxxxx4
	int	B[10] = {0,0,0,0,0,0,0,0,0,0}; //saves number 4xxxxx
	int width, current_val, carry=0;
	width = 1; //starting to check number
	current_val = index * index; //last digit
	A[0] = index;
	B[0] = current_val % 10;
	A[1] = B[0];
	carry = current_val / 10;
	while(width <= 10) //max = 4294967296, 10 digits
	{
		current_val = A[width] * index + carry;
		carry = 0;
		if(current_val == index) 
		{
			B[width] = index;
			break;
		}
		else //Need to grow width
		{
			width++;
			B[width-1] = current_val % 10;
			A[width] = B[width-1];
			carry = current_val / 10;
			
		}
		
	} 
	//Printing numbers
	int i;
	printf("%d*", index);
	for(i = width; i >= 0; i--)
	{
		printf("%d", A[i]);
	}
	printf(" = ");
	for(i = width; i >= 0; i--)
	{
		printf("%d", B[i]);
	}
	printf("\n");	
	
}