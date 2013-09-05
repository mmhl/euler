#include <stdio.h>
#include <stdlib.h>

static int digits_in_number(int number)
{
	int divisor = 1;
	int i;
	int digits= 0;
	while(number % divisor != number)
	{
		divisor *= 10;
		digits++;	
	}
	return digits;
	
	
}
static int is_palindrome(int number, int digits)
{
	int i, divisor;	
	divisor = 1; //Init
	int ret;
	int *number_digits= calloc(digits, sizeof(int));
	for(i = 0; i < digits; i++)
	{
		number_digits[i] = (number / divisor) % 10;
		divisor *= 10;
	}
	for(i = 0; i < digits; i++)
	{
		if(number_digits[i] == number_digits[digits-i-1]) // off by 1...
		{
			ret = 1;
			continue;		
		}
		else
		{
			ret = 0;
			break;
		}
	}
	free(number_digits);
	return ret;
}

int main(int argc, char *argv[])
{
	long int number;	
	int digits;
	int palindrome, max_palindrome;
	long int multiples= 0;
	palindrome = max_palindrome = 0;
	//Brute force, no idea atm
	int i, j;
	for(i = 999; i > 100; i--)
	{
		for(j = i; j > 100; j--)
		{
			number = i*j;		
			multiples++;	
			digits = digits_in_number(number);
			if(is_palindrome(number, digits)) 
			{
				palindrome = number;
				if(palindrome > max_palindrome)
					max_palindrome = palindrome;
			}

		}
	}
out:
	printf("Got max palindrome %d\n", max_palindrome);
	printf("%ld\n", multiples);
	return 0;
}



