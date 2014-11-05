#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
static unordered_map<int, int> steps;

int collatz(unsigned int val) {
        if(val == 1)
                return 1;

        auto got = steps.find(val);
        if(got != steps.end()) {
                return got->second;
        }

        if(val%2 == 0) {
                int val_steps = 1+collatz(val/2);
                steps[val] = val_steps;
                return steps[val];
        }
        else {
                int val_steps = 1+collatz(3*val+1);
                steps[val] = val_steps;
                return steps[val];
        }
}

int main() 
{
        steps[1] = 0;
        int max = 0;
        for(int i = 2; i < 10000000; i++) {
                int steps = collatz(i);
                if(steps > max) {
                        cout << "New score: " << i << " with " << steps << endl;
                        max = steps;
                }
        }
        return 0;
}

