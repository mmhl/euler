#include <iostream>
#include <stdio.h>

unsigned int factorials[10];

using namespace std;
unsigned int factorial(int digit)
{
	if(digit == 0) return factorials[digit];
	if(factorials[digit-1] == 0)
		factorial(digit-1);
	factorials[digit] = digit*factorials[digit-1];
	return factorials[digit];
}

bool is_curious_number(int number)
{
	int t = number;
	int sum = 0;
	int fact;
	while(number > 0) {
		int digit = number%10;
		fact = factorial(digit);
		if(fact > t)
			return false;
		sum += fact;
		number = number/10;
	}
	if(sum == t) return true;
	return false;
}

int main()
{
	for(int i = 0; i < 10; i++)
		factorials[i] = 0;
	factorials[0] = 1;
	int sum= 0 ;
	for(int i = 3; i < 99999; i++) {
		if(is_curious_number(i)) {
			cout << i << endl;
			sum += i;
		}
	}
	cout << "SUM: " << sum << endl;

}
