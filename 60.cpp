#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

static const long long MAX_PRIME = 100000;
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

bool isPrime(long long n, const vector<long long>& primes) {
    if (n <= MAX_PRIME) {
        if (find(primes.begin(), primes.end(), n) != primes.end())
            return true;
        else
            return false;
    } else {
        for (long long i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}

bool isOK(const vector<long long>& primes, vector<long long>& v, long long n) {
    for (long long i = 0; i < v.size(); i++) {
        if (isPrime(concat(primes[v[i]], n), primes) == false) return false;
        if (isPrime(concat(n, primes[v[i]]), primes) == false) return false;
    }
    return true;
}


void dfs(const vector<long long>& primes, vector<long long> v, int sum) {
    long long start = v[v.size()-1] + 1;
    for (long long i = start; i < primes.size() && sum + primes[i] < upperBound; i++) {
        long long n = primes[i];
        if (isOK(primes, v, n)) {
            v.push_back(i);
            if (v.size() >= 5) {
                int ans = 0;
                for (long long j = 0; j < v.size(); j++) {
                    cout << primes[v[j]] << " ";
                    ans += primes[v[j]];
                }
                cout << endl;
                cout << "A: " << ans << endl;
                upperBound = min(upperBound, ans);
            }
            dfs(primes, v, sum + n);
        }
    }
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

    for (long long i = 0; i < primes.size(); i++) {
        vector<long long> v(1, i);
        dfs(primes, v, primes[i]);
    }
}
