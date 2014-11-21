#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <unordered_map>

#ifdef __GNUC__
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
#else
#define likely(x)       (x)
#define unlikely(x)     (x)
#endif

using namespace std;
static unordered_map<int, int> map_steps;

inline int collatz(unsigned int val) {

        if((val==1)) 
                return 1;

        auto got = map_steps.find(val);
        if(got != map_steps.end()) {
                return got->second;
        }

        int val_steps = 1;
        if((val & 1) == 0) 
                val_steps += collatz(val >> 1);
        else 
                val_steps += collatz(3*val+1);

        map_steps[val] = val_steps;
        return val_steps;
}

int main() 
{
        map_steps.reserve(6000000);
        int key, max;
        key = max = 0;
        for(int i = 3; i < 1000000; i += 2) {
                int steps = collatz(i);
                if(unlikely(steps > max)) {
                        //cout << "New score: " << i << " with " << steps << "\n";
                        max = steps;
                        key = i;
                }
        }
        cout << key << " " << max << endl; 
        return 0;
}

