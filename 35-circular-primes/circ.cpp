#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>

#define NUMBERS 1000000
bool sieve[NUMBERS];
using namespace std;
void init_sieve()
{
	for(int i = 2; i < NUMBERS; i++) sieve[i] = true;
	for(int i = 2; i < sqrt(NUMBERS); i++) {
		if(sieve[i] == true) 
			for(int j=i*i; j<NUMBERS; j += i) {
				sieve[j] = false;
			}
	}
}


int to_int(const int *digits, int len)
{
	int number = 0;
	for(int i = 0; i < len; i++) {
		number += digits[i]*(pow(10,i));
	}
	return number;
}
vector<int> permutations(int num)
{	
	int digit;	
	int number;
	vector<int> digits;
	vector<int> perms;
	while(num > 0) {
		digit = num % 10;
		num /= 10;
		digits.push_back(digit);
	}
	int *digit_array = &digits[0];
	int len = digits.size();
	sort(digit_array, digit_array+len);
	do {
		number = to_int(digit_array, len);
		perms.push_back(number);
	} while(next_permutation(digit_array, digit_array+len));
	cout << "Permutations: "; 
	for(int i = 0; i < len; i++) {
		cout << perms[i] << " " ;
	}
	cout << endl;
	return perms;
}

int main() 
{
	int count = 0;
	init_sieve();
	for(int i = 2; i < NUMBERS; i++) {
		if(sieve[i] == true) {
			vector<int> perms = permutations(i);
			for(int j = 0; j < perms.size(); j++)  {
				if(sieve[perms[j]] == false) break;
			}
			cout << ++count << ": " << i << endl;
		}
	}
}
