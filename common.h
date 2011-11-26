#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;

vector<int> getPrimes(int max) {
    vector<int> primes;
    vector<bool> isPrime(max+1, true);
    for (int i = 2; i <= max; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i*2; j <= max; j+=i) isPrime[j] = false;
        }
    }
    return primes;
}

string int2string(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

