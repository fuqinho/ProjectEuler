#include <iostream>
#include <vector>
using namespace std;

int getCycle(int n) {
    vector<int> nums;
    int rem = 1;
    int cycle = 0;
    while (true) {
        nums.push_back(rem);
        cycle ++;
        rem = rem * 10 % n;
        if (find(nums.begin(), nums.end(), rem) != nums.end()) {
            return nums.end() - find(nums.begin(), nums.end(), rem);
        }
        if (rem == 0) {
            return 0;
        }
    }
}

int main() {
    int maxCycle = 0;
    int numForMaxCycle = 0;
    for (int i = 2; i <= 1000; i++) {
        int cycle = getCycle(i);
        cerr << i << ": " << cycle << endl;
        if (cycle > maxCycle) {
            maxCycle = cycle;
            numForMaxCycle = i;
        }
    }
    cout << "==== answer =====" << endl;
    cout << numForMaxCycle << ": " << maxCycle << endl;
}

