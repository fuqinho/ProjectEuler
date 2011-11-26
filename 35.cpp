#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int MAX_PRIME = 1000000;

vector<int> convert(int n) {
    vector<int> res;
    while (n != 0){
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}

int convert(const vector<int>& v) {
    int n = 0;
    int digit = 1;
    for (int i = 0; i < v.size(); i++) {
        n += v[i] * digit;
        digit *= 10;
    }
    return n;
}

int main() {
    vector<bool> isPrime(MAX_PRIME+1, true);
    vector<int> primes;
    for (int i = 2; i <= MAX_PRIME; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i*2; j <= MAX_PRIME; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < primes.size(); i++) {
        int n = primes[i];
        vector<int> temp = convert(n);
        bool isOK = true;
        for (int j = 0; j < temp.size(); j++) {
            rotate(temp.begin(), temp.begin()+1, temp.end());
            if (!isPrime[convert(temp)]) {
                isOK = false;
                break;
            }
        }
        if (isOK) answer++;
    }
    cout << "A: " << answer << endl;
}

