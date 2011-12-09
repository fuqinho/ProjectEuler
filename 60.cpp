#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

static const long long MAX_PRIME = 10000;
int upperBound = 100000;

long long concat(long long a, long long b) {
    long long res = a;
    long long n = b;
    while (n > 0) {
        res *= 10;
        n /= 10;
    }
    return res + b;
}

bool isPrime(long long n) {
    for (long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool canAdd(vector<int>& v, int n) {
    for (int i = 0; i < v.size(); i++) {
        if (isPrime(concat(v[i], n)) == false) return false;
        if (isPrime(concat(n, v[i])) == false) return false;
    }
    return true;
}

void printAnswer(vector<int> v) {
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        cerr << v[i] << " ";
        ans += v[i];
    }
    cout << endl;
    cout << "A: " << ans << endl;

}

int main() {
    vector<bool> isPrime(MAX_PRIME+1, true);
    vector<long long> primes;
    for (long long i = 2; i <= MAX_PRIME; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = i*2; j <= MAX_PRIME; j+=i) isPrime[j] = false;
        }
    }
    
    vector<int> v;
    for (int i = 0; i < primes.size(); i++) {
        v.push_back(primes[i]);
        for (int j = i+1; j < primes.size(); j++) {
            if (!canAdd(v, primes[j])) continue;
            v.push_back(primes[j]);
            for (int k = j+1; k < primes.size(); k++) {
                if (!canAdd(v, primes[k])) continue;
                v.push_back(primes[k]);
                for (int l = k+1; l < primes.size(); l++) {
                    if (!canAdd(v, primes[l])) continue;
                    v.push_back(primes[l]);
                    for (int m = l+1; m < primes.size(); m++) {
                        if (!canAdd(v, primes[m])) continue;
                        v.push_back(primes[m]);
                        printAnswer(v);
                        v.pop_back();
                    }
                    v.pop_back();
                }
                v.pop_back();
            }
            v.pop_back();
        }
        v.pop_back();
    }
}
