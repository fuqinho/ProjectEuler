#include "common.h"

static const int MAX_PRIME = 1000000;

int getFactorNum(int n, vector<int>& primes) {
    int count = 0;
    for (int i = 0; n != 1 && i < primes.size(); i++) {
        if (n % primes[i] == 0) {
            count++;
            while (n % primes[i] == 0) n /= primes[i];
        }
    }
    return count;
}

int main() {
    vector<bool> isPrime(MAX_PRIME+1, true);
    vector<int> primes;
    for (int i = 2; i <= MAX_PRIME; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i*2; j <= MAX_PRIME; j += i) isPrime[j] = false;
        }
    }

    int duration = 0;
    for (int i = 1; ; i++) {
        if (getFactorNum(i, primes) == 4) {
            duration++;
            if (duration == 4) {
                cout << i-3 << " to " << i << endl;
                break;
            }
        } else {
            duration = 0;
        }
    }
}
