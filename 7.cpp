#include <iostream>
#include <vector>
using namespace std;

static const int MAX_N = 1000000;

int main() {
    vector<bool> isPrime(MAX_N+1, true);
    int primeNum = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (isPrime[i]) {
            primeNum++;
            if (primeNum == 10001) {
                cout << i << endl;
                break;
            }
            for (int j = i; j < MAX_N; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}


