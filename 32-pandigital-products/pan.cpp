#include <iostream>
#include <stdio.h>
#include <vector>
#include <assert.h>
#include <math.h>
using namespace std;
#define MAX_NUMBERS 1000000
#define MAX_MULTIPLIER 9999
#define MULTIPLIERS 2

int pan_numbers[MAX_NUMBERS]; // indexed by product of multipliers
int multipliers_done[MAX_MULTIPLIER+1][MAX_MULTIPLIER+1];

vector<int> get_digits(int number) 
{
	vector<int> digits;
	while(number > 0) {
		digits.push_back(number%10);
		number = number/10;
	}
	return digits;
}

bool multipliers_computed(int i, int j) 
{
	return multipliers_done[i][j];
}

//Returns -1 if not, else returns product
int produces_pandigit(int x, int y) 
{
	int digits[10]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	vector<int> mul_digits = get_digits(x);
	for(int i = 0; i < mul_digits.size(); i++) {
		digits[mul_digits[i]]++;
	}
	mul_digits = get_digits(y);
	for(int i = 0; i< mul_digits.size(); i++) {
		digits[mul_digits[i]]++;
	}
	for(int i = 0; i <= 9; i++) 
		if(digits[i] > 1) return -1;
	int product = x*y;
	vector<int> product_digits = get_digits(product);
	for(int i = 0; i< product_digits.size(); i++) {
		digits[product_digits[i]]++;
	}
	for(int i = 1; i <= 9; i++) {
		if(digits[i] != 1 || digits[0] > 0) return -1;
	}
	return product;
}

int main() 
{
	//initialize arrays
	for(int i = 0; i < MAX_NUMBERS; i++) {
		pan_numbers[i]= 0;
	}
	for(int i = 1; i <= MAX_MULTIPLIER; i++) {
		for(int j=1; j<=MAX_MULTIPLIER; j++) {
			multipliers_done[i][j] = 0;
		}
	}

	int product;
	for(int i = 1; i <= sqrt(MAX_MULTIPLIER); i++) {
		for(int j = sqrt(MAX_MULTIPLIER); j <= MAX_MULTIPLIER; j++) {
			if(multipliers_computed(i, j)) continue;
			//mark as done
			multipliers_done[i][j] = multipliers_done[j][i] = 1;
			if((product = produces_pandigit(i, j)) != -1) {
				if(pan_numbers[product] == 1) continue;
				cout << "Pandigit: " << product << " " << i << "*" << j << endl;
				pan_numbers[product]++;				
				assert(pan_numbers[product] == 1);
			}
			
		}
	}
	int sum = 0;
	for(int i = 0; i< MAX_NUMBERS; i++) {
		sum += pan_numbers[i] > 0 ? i : 0;
	}
	cout << sum << endl;
}





