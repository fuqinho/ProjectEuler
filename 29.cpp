#include <iostream>
#include <vector>
#include <set>
using namespace std;

static const int MAX_PRIME = 100;

vector<int> makeExpList(int a, int b, const vector<int>& primes) {
    vector<int> res;
    for (int i = 0; i < primes.size(); i++) {
        int exp = 0;
        while (a % primes[i] == 0) {
            exp++;
            a /= primes[i];
        }
        res.push_back(exp);
        if (a == 1) break;
    }
    for (int i = 0; i < res.size(); i++) {
        res[i] *= b;
    }
    return res;
}

int main() {
    vector<bool> isPrime(MAX_PRIME+1, true);
    vector<int> primes;
    for (int i = 2; i <= MAX_PRIME; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i*2; j <= MAX_PRIME; j+=i) isPrime[j] = false;
        }
    }

    set< vector<int> > sets;
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            vector<int> expList = makeExpList(a, b, primes);
            sets.insert(expList);
        }
    }

    cout << "A: " << sets.size() << endl;
}

