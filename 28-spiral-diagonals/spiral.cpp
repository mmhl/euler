#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char *argv[])
{
	int sum = 1; // Square 1x1 has only one element valued 1
	int to_skip = 0; // how many odds we should skip that are not on diagonals
	int skipped;
	int numbers_in_square = 0; // how many numbers in circumference
	int curr = 1;
	for(int size = 3; size <= 1001; size += 2)
	{
		skipped = 0;
		numbers_in_square = 2*size + 2*(size-2); 	
		//cout << "Square size: " << size << " :";
		for(int i = 0; i < numbers_in_square; i++)
		{
			curr++;
			if((curr%2 != 0) && (skipped++ == to_skip))
			{
				//cout << curr <<  "* ";
				skipped = 0;
				sum += curr;
			}
		}
		to_skip++;
	}
	cout << sum << endl;
}
