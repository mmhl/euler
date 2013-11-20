#include <iostream>
#include <vector>
#include <algorithm>
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
	vector<int> ab_num;
	for(int i= 1; i <= 28123; i++)
	{
		if(is_abundant(i))
		{
			ab_num.push_back(i);
			cout << i << ", ";
		}
	}

}
