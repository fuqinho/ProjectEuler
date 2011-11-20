#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 998; i++) {
        for (int j = i+1; i+j <= 999; j++) {
            int k = 1000 - i - j;
            if (i*i + j*j == k*k) {
                cout << i << "," << j << "," << k << endl;
                cout << i*j*k << endl;
            }
        }
    }
}
