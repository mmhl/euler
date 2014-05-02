#include <stdio.h>
#include <iostream>

#define COINS_COUNT 8
using namespace std;
int coins[COINS_COUNT] = {1, 2, 5, 10, 20, 50, 100, 200};

int get_change(int value, int count)
{
	if(value == 0)	
		return 1;
	if(value < 0)
		return 0;
	if(count <= 0 && value >= 1)
		return 0;
	return get_change(value, count-1) + get_change(value-coins[count-1], count);
}

int main()
{
	cout << get_change(200, COINS_COUNT) << endl;
	return 0;
}