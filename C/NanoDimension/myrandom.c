#include <stdio.h>
#include <time.h>

#define SET_BIT(num, bitnum) (num |= (1 << bitnum))

int random(void); //to get a random number 0 or 1.
unsigned int my_random(void); //to get a random number between 0 and [n-1].


int main(void)
{
	int k = 0;
	while(1){
		printf("%u\n", my_random());
		k++;
		if(k > 5)
			break;
	}
	return 0;	
}

int random(void)
{
	clock_t current = clock();
	
	return (current % 2);
}
unsigned int my_random(void)
{
	int i;
	unsigned int number = 0;
	int high = 31, low = 0;
	while(high > low) {
		if(random()
	}
	
	return number;
}