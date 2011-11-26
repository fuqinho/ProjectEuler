#include <iostream>
#include <vector>
using namespace std;

static const int MAX_PRIME = 9999999;

bool isPandigital(int n) {
    int k = n;
    int digits = 0;
    vector<int> used(10, 0);
    while (k > 0) {
        digits ++;
        used[k % 10]++;
        k /= 10;
    }
    /*
    for (int i = 1; i <= digits; i++) {
        cout << used[i];
    }
    cout << endl;
    */
    for (int i = 1; i <= digits; i++) {
        if (used[i] != 1) return false;
    }
    return true;
}

int main() {
    vector<bool> isPrime(MAX_PRIME+1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= MAX_PRIME; i++) {
        if (isPrime[i]) {
            if (isPandigital(i)) cout << i << endl;
            for (int j = i * 2; j <= MAX_PRIME; j += i) isPrime[j] = false;
        }
    }
}
