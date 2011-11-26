#include "common.h"

static const int MAX = 1000000;

int main() {
    vector<bool> isPrime(MAX+1, true);
    isPrime[0] = isPrime[1] = false;
    vector<int> primes;
    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i*2; j <= MAX; j+=i) {
                isPrime[j] = false;
            }
        } else {
            if (i % 2 == 1) {
                bool isOK = false;
                for (int j = 1; j*j*2 < i; j++) {
                    if (isPrime[i-j*j*2]) {
                        isOK = true;
                        break;
                    }
                }
                if (!isOK) cout << i << endl;
            }
        }
    }
}
