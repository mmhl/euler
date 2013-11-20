/*
 * =====================================================================================
 *
 *       Filename:  sum.c
 *
 *    Description:  Sum of primes to number provided
 *
 *        Version:  1.0
 *        Created:  13.06.2013 14:14:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int global_num_root; 
int is_prime(long int num)
{
	long int i;
	if(num % 2 == 0 && num != 2 ||
	   num % 3 == 0 && num != 3 || 
	   num % 5 == 0 && num != 5 ||
	   num % 7 == 0 && num != 7 ||
	   num % 11== 0 && num != 11 ||
	   num % 13 ==0 && num != 13)
		return 0;
	for(i = sqrt(num); i > 2; i--)
	{
		if (num % i == 0) return 0;
		else continue;
	}

	return num;
}

int main(int argc, char *argv[])
{
	long int number, sum;
	if(argc != 2)
		return -1;

	number = strtol(argv[1], NULL, 0);
	
	long int i = number;
	long int t = i;	
	long int temp;
	sum = 0;
	for(i = number; t > 1; t--)
	{
		if((temp = is_prime(t)))
		{
			t = temp;
			sum += t;
		}
	}	
	printf("%ld\n", sum);
}
