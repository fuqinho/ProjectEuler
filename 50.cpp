#include "common.h"

static const int MAX_PRIME = 1000000;

int main() {
    vector<bool> isPrime(MAX_PRIME+1, true);
    vector<int> primes;
    for (int i = 2; i <= MAX_PRIME; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i*2; j <= MAX_PRIME; j+=i) isPrime[j] = false;
        }
    }

    cout << primes.size() << endl;
    int maxLen = 1;
    for (int i = 0; i < primes.size(); i++) {
        int sum = 0;
        for (int j = 0; i+j < primes.size(); j++) {
            if (i+j <= MAX_PRIME) {
                sum += primes[i+j];
                if (sum > MAX_PRIME) break;
                if (isPrime[sum] && j+1 > maxLen) {
                    cout << sum << " / " << primes[i] << " to " << primes[i+j] << "(" << j+1 << ")" << endl;
                    maxLen = j+1;
                }
            }

        }
    }
}
