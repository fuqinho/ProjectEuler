#include "common.h"

static const int MAX_PRIME = 1000000;


int extract(int n, int digit) {
    int t = 0;
    int d = 1;
    while (n > 0) {
        if (n % 10 == digit) {
            t += d;
        }
        d *= 10;
        n /= 10;
    }
    return t;
}

int main() {
    vector<bool> isPrime(MAX_PRIME+1, true);
    isPrime[0] = isPrime[1] = false;
    vector<int> primes;
    for (int i = 2; i <= MAX_PRIME; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i*2; j <= MAX_PRIME; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    
    for (int i = 0; i < primes.size(); i++) {
        int n = primes[i]; 
        int temp = extract(n, 1);
        if (temp != 0) {
            int target = n - temp ; 
            int count = 0;
            for (int i = 0; i <= 9; i++) {
                if (isPrime[target]) count++;
                target += temp;
            }
            if (count >= 8) {
                cout << n << " (" << temp << ")" << endl;
                for (int i = 0; i <= 9; i++) {
                    if (isPrime[(n - temp) + temp * i])
                    cout << (n - temp) + temp * i << " ";
                }
                cout << endl;
            }
        }
    }
}
