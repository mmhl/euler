#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int is_first(int number)
{
	int i, result = 1;
	int max_div;
	if(number%2 == 0)
		return 0;
	max_div = sqrt(number);
	for(i = max_div; i > 2; i--)
	{
		if(number % i == 0)
			return 0;
		else 
			continue;
	}
	return 1;
}

static int prime_nth(int number)
{
	int primes = 1; // because of 2	
	int i = 2;
	while(1)
	{
		i++;
		if(is_first(i))
		{
			primes++;
			if(primes==number)
				break;
		}
	}
	return i;
}


int main()
{
	int number = 10001;
	printf("%d\n", prime_nth(number));
}
