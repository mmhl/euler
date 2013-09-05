#include <stdio.h>
#include <stdlib.h>



int *numbers_count; // Numbers excluded from multiplication
static void increase_count(int number)
{
	numbers_count[number-1]++;
}
static void decrease_count(int number)
{
	numbers_count[number-1]--;
}
static void decrease_count_by(int amount, int num)
{
	numbers_count[num-1] -= amount;	
}
	
//Get number count
static int get_count(int number)
{
	return numbers_count[number-1];
}

// Returns true if all numbers are present at least once
static int all_nums_present(int len)
{
	int i;
	int ret = 1;
	for(i = 1; i < len; i++)
	{
		if(get_count(i)== 0)
		{
			ret = 0;
			break;
		}
		else
			continue;
			
	}

	if(ret) printf("All coeffs are present at least once!\n");
	return ret;
}

static void print_list(int len)
{
	int i;
	for(i = 0; i < len; i++)
		printf("%3d", i+1);
	printf("\n");
	for(i = 0; i < len; i++)
	{
		printf("%3d", numbers_count[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int number;
	long int result = 1;
	if(argc != 2)
	{
		return -1;
	}	
	number = strtol(argv[1], NULL, 0);
	numbers_count = calloc(number, sizeof(int)); // How many times does numer appeared?
	numbers_count[0] = 1; //Leave poor 1 alone
	printf("%d\n", number);

	int i,j;
	int mod;
	int all_good = 0;
	for(i = number; i > 1; i--)
	{
		for(j = i; j > 1; j--)
		{
			
			mod = i%j;
			if(mod == 0)
			{
				increase_count(j);
				printf("\n%d%%%d==0. Adding number %d to list\n", i,j,j);
				print_list(number);
				
			}
		}	
		if(all_nums_present(number)) // We got all coeffs! But we can not have
			break;
		result *= i;
		if(all_good)
			break;
	}
// Last step. divide number by outstanding coefficients. We only need one.	
	printf("Result before division: %ld\n", result);
	int coef_count;
	for(i = number; i > 1; i--)
	{
		if((coef_count = get_count(i)) > 1)	
		{
			result /= ((coef_count-1)* i);
			decrease_count_by(coef_count-1, i);			
		}
		print_list(number);
		printf("\n");
	}
	
	printf("\n%ld\n", result);
	
	for(i = number; i > 1; i--)
	{
		printf("\n%d%%%d=%d", result, i, result%i);
		if(result%i != 0) printf(" Test failed!");
	}

	printf("\n");
}
