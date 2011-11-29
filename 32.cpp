#include <iostream>
#include <set>
using namespace std;

int getMask(int n) {
    int res = 0;
    while (n != 0) {
        res |= (1 << ((n%10)-1));
        n /= 10;
    }
    return res;
}

void showMask(int n) {
    for (int i = 0; i < 9; i++) {
        cout << (n & 1);
        n = n >> 1;
    }
    cout << endl;
}

bool isPandigital(int i, int j, int k) {
    int mask = getMask(i) | getMask(j) | getMask(k);
    return mask == (1<<9)-1;
}

int main() {
    set<int> res;

    // 2x3=4
    for (int i = 10; i <= 99; i++) {
        for (int j = 100; j <= 999; j++) {
            int prod = i * j;
            if (prod >= 1000 && prod <= 9999) {
                if (isPandigital(i, j, prod)) {
                    cout << i << " x " << j << " = " << prod << endl;
                    res.insert(prod);
                }
            }
            
        }
    }
    // 1x4=4
    for (int i = 1; i <= 9; i++) {
        for (int j = 1000; j <= 9999; j++) {
            int prod = i * j;
            if (prod >= 1000 && prod <= 9999) {
                if (isPandigital(i, j, prod)) {
                    cout << i << " x " << j << " = " << prod << endl;
                    res.insert(prod);
                }
            }
        }
    }
    int sum = 0;
    set<int>::iterator it = res.begin();
    while (it != res.end()) {
        sum += *it;
        it++;
    }

    cout << sum << endl;
}
