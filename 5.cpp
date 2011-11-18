#include <iostream>
#include <vector>
using namespace std;

static const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

int main() {
    int primeNum = sizeof(primes) / sizeof(int);
    vector<int> minFactors(primeNum, 0);
    for (int i = 1; i <= 20; i++) {
        int tmp = i;
        for (int j = 0; j < primeNum; j++) {
            int facNum = 0;
            while (tmp != 1 && tmp % primes[j] == 0) {
                tmp /= primes[j];
                facNum++;
            }
            minFactors[j] = max(minFactors[j], facNum);
        }
    }

    long long result = 1;
    for (int i = 0; i < minFactors.size(); i++) {
        for (int j = 0; j < minFactors[i]; j++) {
            result *= primes[i];
        }
    }
    cout << result << endl;
    
}
