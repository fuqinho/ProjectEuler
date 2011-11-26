#include <iostream>
#include <vector>
using namespace std;

static const int MAX_I = 5000;
static const int MAX_NUMBER = MAX_I * MAX_I * 4;

int pentag(int n) {
    return n * (n * 3 - 1) / 2;
}

int main() {
    vector<bool> isPentagonal(MAX_NUMBER+1, false);
    for (int i = 1; ; i++) {
        int n = pentag(i);
        if (n <= MAX_NUMBER) {
            isPentagonal[n] = true;
        } else {
            break;
        }
    }
    
    for (int i = 1; i < MAX_I; i++) {
        for (int j = i+1; j < MAX_I; j++) {
            int diff = pentag(j) - pentag(i);
            int sum = pentag(j) + pentag(i);

            if (isPentagonal[diff] && isPentagonal[sum]) {
                cout << pentag(i) << ", " << pentag(j) << endl;
                cout << pentag(j) - pentag(i) << endl;
            }
        }
    }
}

