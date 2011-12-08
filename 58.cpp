#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool isPrime(long long n) {
    for (long long i = 2; i <= sqrt(n); i++) 
        if (n % i == 0) return false;
    return true;
}

int main() {
    int primeNum = 0;
    int checked = 1;
    for (int i = 2; ; i++) {
        for (int j = 0; j < 4; j++) {
            long long n = (i*2-1) * (i*2-1) - j*(i-1)*2;
            if (n > 1000000000) {
                cerr << "number exceeds MAX" << endl;
                return 1;
            }
            if (isPrime(n)) primeNum++;
            checked++;
        }
        cout << i << ": " << primeNum << "/" << checked << " (";
        cout << (double)primeNum * 100 / checked << ")" << endl;
        if (primeNum * 10 < checked) {
            cout << "A: " << i*2-1 << endl;;
            break;
        }
    }
}
