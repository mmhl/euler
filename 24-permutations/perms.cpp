/*
 * perms.cpp
 *
 *  Created on: 3 wrz 2013
 *      Author: mhl
 */

#include <iostream>
#include <vector>

#define MAX_DIGITS 4

using namespace std;

/*
 * next permutation of vector in written to vector out
 */
void next_permutation(const vector<int> (&in), vector<int> (&out))
{
	int k, l;
	out = in;
	k = MAX_DIGITS-1; // We're looking for largest index k that a[k] < a[k+1]
	l = MAX_DIGITS-1;
	// Looking for k
	for(vector<int>::reverse_iterator it = out.rbegin()+ 1; it != out.rend(); it++)
	{
		if(*it < *(it++))
		{
			cout << *it << endl;
		}
	}



}

int main()
{
	vector<int> numbers(MAX_DIGITS);
	vector<int> output(MAX_DIGITS);
	for(int i=0; i < MAX_DIGITS; i++)
	{
		numbers[i] = i+1;
	}
	next_permutation(numbers, output);
	for(int i= 0; i < MAX_DIGITS; i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
}
