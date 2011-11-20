#include <iostream>
#include <vector>
using namespace std;

static const int MAX_PRIME = 100000;

vector<int> getPrimes() {
    vector<bool> isPrime(MAX_PRIME, true);
    vector<int> primeList;
    for (int i = 2; i <= MAX_PRIME; i++) {
        if (isPrime[i]) {
            primeList.push_back(i);
            for (int j = i * 2; j <= MAX_PRIME; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primeList;
}

int factorNum(int n, vector<int>& primes) {
    int result = 1;
    int primeIndex = 0;
    while (n != 1) {
        int tempFacNum = 0;
        while (n % primes[primeIndex] == 0) {
            n /= primes[primeIndex];
            tempFacNum++;
        }
        result *= (tempFacNum+1);
        primeIndex++;
    }
    return result;
}

int main() {
    vector<int> primeList = getPrimes();

    for (int i = 1; ; i++) {
        int number = i * (i + 1) / 2;
        int result = factorNum(number, primeList);
        if (result >= 500) {
            cout << number << ": " << result << endl;
            break;
        }
    }
}
