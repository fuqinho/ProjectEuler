#include <iostream>
#include <vector>
using namespace std;

/*
 * 1-9 9
 * 10-99 90*2
 * 100-999 900*3
 */
int getDigit(int target) {
    int totalDigits = 0;
    for (int i = 1; i <= 1000000; i++) {
        int digits = 1;
        if (i >= 10) digits++;
        if (i >= 100) digits++;
        if (i >= 1000) digits++;
        if (i >= 10000) digits++;
        if (i >= 100000) digits++;
        if (target > totalDigits && target <= totalDigits + digits) {
            int k = i;
            for (int j = 0; j < totalDigits+digits-target; j++) k /= 10;
            return k % 10;
        }
        totalDigits += digits; 
    }
    return -1;
}

int main() {
    int prod = 1;
    for (int i = 1; i <= 1000000; i *= 10) {
        prod *= getDigit(i);
    }
    cout << prod << endl;
}

