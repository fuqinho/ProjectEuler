#include "common.h"

int getPattern(int n) {
    int ans = 0;
    while (n > 0) {
        ans |= (1 << (n % 10));
        n /= 10;
    }
    return ans;
}

int countPattern(int n) {
    int result = 0;
    while (n > 0) {
        if (n & 1) result++;
        n = (n >> 1);
    }
    return result;
}

void printPattern(int n) {
    while (n > 0) {
        cout << (n & 1);
        n = (n >> 1);
    }
    cout << endl;
}

bool isPrime(int n) {
    for (int i = 2; i <= (int)sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    for (int i = 0; i <= 9999; i++) {
        int p1 = getPattern(i);
        if (countPattern(p1) < 3) continue;
        for (int j = 1; i + 2 * j <= 9999; j++) {
            int p2 = getPattern(i+j);
            if (p2 != p1) continue;
            int p3 = getPattern(i+j*2);
            if (p3 != p1) continue;
            if (isPrime(i) && isPrime(i+j) && isPrime(i+j*2))
                cout << i << " " << i+j << " " << i+j*2 << endl;
        }
    }
}
