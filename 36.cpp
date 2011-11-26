#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(int n, int base) {
    int reversed = 0;
    int k = n;
    while (k != 0) {
        reversed = reversed * base + k % base;
        k /= base;
    }
    return n == reversed;
}

int makePalindromeBase2(int n, bool isOddLength) {
    int res = n;
    if (isOddLength) n = (n >> 1);
    while (n > 0) {
        res = (res << 1) + (n & 1);
        n = (n >> 1);
    }
    return res;
}

int main() {
    int sum = 0;
    /*
    for (int i = 1; i < 1000000; i++) {
        if (isPalindrome(i, 10) && isPalindrome(i, 2)) {
            cout << i << endl;
            sum += i;
        }
    }
    */
    int i = 1;
    int p = makePalindromeBase2(i, true);
    while (p < 1000000) {
        if (isPalindrome(p, 10)) sum += p;
        i++;
        p = makePalindromeBase2(i, true);
    }
    i = 1;
    p = makePalindromeBase2(i, false);
    while (p < 1000000) {
        if (isPalindrome(p, 10)) sum += p;
        i++;
        p = makePalindromeBase2(i, false);
    }

    cout << "A: " << sum << endl;
}
