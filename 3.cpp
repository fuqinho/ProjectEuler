#include <iostream>
#include <cmath>
using namespace std;

long long findFactor(long long n) {
    for (int i = 2; i <= (int)sqrt(n); i++) 
        if (n % i == 0) return i;
    return -1;
}

int main() {
    long long maxFactor = 1;
    long long n = 600851475143;
    while (n > 1) {
        long long factor = findFactor(n);
        cerr << "factor: " << factor << endl;
        if (factor == -1) {
            maxFactor = max(maxFactor, n);
            break;
        } else {
            maxFactor = max(maxFactor, factor);
            n /= factor;
        }
    }
    cout << maxFactor << endl;
}
