#include <stdio.h>
#include <iostream>

#define COINS 3
using namespace std;
int coin_values[COINS] = {1, 2, 5};

int get_change(int value, int coins)
{
	int table[value+1][coins];
	for(int i = 0; i < coins ; i++) // one solution for table[0][j]
		table[0][i] = 1;
	//rest of solution
	for(int i = 1; i < value+1; i++) {
		for(int j = 0; j < coins; j++) {
			//Case including coins[j]
			int x = (i - coin_values[j] >= 0) ? table[i - coin_values[j]][j] : 0;
			//Case excluding coins[j]
			int y = (j >= 1) ? table[i][j-1] : 0;
			table[i][j] = x+y;
			cout << "table: " << table[i][j] << endl;
		}
	}
	return table[value][coins-1];
}

int main()
{
	cout << get_change(7, COINS) << endl;
}