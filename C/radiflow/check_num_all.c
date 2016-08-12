#include <stdio.h>

/**
 * find_number - Finds and prints the specific number 
 * xx...x that satisfies the following condition: 
 * k*xx...xk = kxx...x, 
 * where xx...x - unknown number with the unknown length.
 * @k: multiplier
 **/
void find_number(int k); 

/*Main */
int main(int argc, char *argv[])
{
	int i;
	
	for(i = 2; i <= 99; i++)	
		find_number(i); 
		
	return 0;
}

void find_number(int k)
{
	int	A[1000] = {0}; //saves number xx...xk
	int	B[1000] = {0}; //saves number kxx...x
	int width, current_val, carry=0;
	width = 1; //starting to check number
	current_val = k * k; //last digit
	carry = current_val / 10;
	A[0] = k;
	if(carry > 0)			
		B[0] = current_val % 10;	
	else //carry = 0	
		B[0] = current_val;	
	A[1] = B[0];
	while(width <= 100)
	{
		current_val = A[width] * k + carry;
		carry = 0;
		if(current_val == k) 
		{			
			B[width] = k;
			break;
		}
		else //Need to grow width
		{			
			width++;
			carry = current_val / 10;			
			if(carry > 0)
				B[width-1] = current_val % 10;
			else //carry = 0
				B[width-1] = current_val;
			A[width] = B[width-1];			
		}		
	} 
	//Printing numbers
	int i;
	printf("%d*", k);
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