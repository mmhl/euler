#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <deque>
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
int to_int(deque<int> digits)
{
	int len = digits.size();
	int number=0;
	for(int i = 0; i < len; i++) {
		number += digits[i]*(pow(10,len-i-1));
	}
	return number;
}

deque<int> to_digit_array(int number)
{
	deque<int> digits;
	while(number > 0) {
		int digit = number%10;
		number /= 10;
		digits.push_front(digit);
	}
	return digits;
}

vector<int> get_rotations(int num) 
{
	vector<int> vec;
	deque<int> digits = to_digit_array(num);
	int origin = num;
	do {
		vec.push_back(to_int(digits));
		rotate(digits.begin(), digits.begin()+1, digits.end());	
	} while(origin != to_int(digits));
	return vec;
}
int main() 
{
	int count = 0;
	init_sieve();
	for(int i = 2; i < NUMBERS; i++) {
		if(sieve[i] == true) {
			bool ok = true;
			vector<int> rotations = get_rotations(i);
			for(int j = 0; j < rotations.size(); j++)  {
				if(sieve[rotations[j]] == false) { 
					ok =false;
					break;
				}
			}
			if(ok)
				cout << ++count << ": " << i << endl;
		}
	}
}
