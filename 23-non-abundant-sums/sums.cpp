#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>


using namespace std;

vector<int> divisors(int num)
{
	vector<int> divs;
	divs.push_back(1); // 1 is divisor of all
	for(int i = 2; i <= num/2; i++)
	{
		if(num%i == 0)  
			divs.push_back(i);
	}	
	return divs;
}

bool is_abundant(int num)
{
	vector<int> divs = divisors(num);
	int div_sum = accumulate(divs.begin(), divs.end(), 0);
	if(div_sum > num)
		return true;
	else
		return false;
}

int main(int argc, char *argvp[])
{
	int num = 12;
	set<int> ab_num;
	set<int> numbers;
	set<int> ab_sum;
	set<int> result;
	for(int i= 1; i <= 28123; i++)
	{
		if(is_abundant(i))
		{
			ab_num.insert(i);
		}
		numbers.insert(i);
	}

	set<int>::iterator it1, it2;
	for(it1 = ab_num.begin(); it1 != ab_num.end(); it1++)
	{
		for(it2 = it1; it2 != ab_num.end(); it2++)
		{
			ab_sum.insert(*it1 + *it2);
		}
	}

	cout << endl;
	set_difference(numbers.begin(), numbers.end(), ab_sum.begin(), ab_sum.end(), inserter(result, result.end()));
	
	for(it1 = result.begin(); it1 != result.end(); it1++)
	{
		cout  << *it1 << ", ";
	}
	cout << endl;
	cout << accumulate(result.begin(), result.end(), 0);
	cout << endl;
}
