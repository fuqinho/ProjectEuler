#include <iostream>
#include <vector>
using namespace std;

static const int MAX_PRIME = 3000000;

int main() {
    vector<bool> isPrime(MAX_PRIME+1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAX_PRIME; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i*2; j <= MAX_PRIME; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < primes.size(); i++) {
        if (primes[i] <= 9) continue;
        int n = primes[i];
        bool isOK = true;
        // right to left
        while (n != 0) {
            if (!isPrime[n]) {
                isOK = false;
                break;
            }
            n /= 10;
        }
        // left to right
        n = primes[i];
        if (!isPrime[n%10] || !isPrime[n%100] || !isPrime[n%1000] || !isPrime[n%10000]
                || !isPrime[n%100000] || !isPrime[n%1000000] || !isPrime[n]) {
            isOK = false;
        }
        if (isOK) {
            cout << primes[i] << endl;
            sum += primes[i];
        }
    }
    cout << "A: " << sum << endl;
}
