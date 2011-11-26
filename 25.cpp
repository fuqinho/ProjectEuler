#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a(1000, 0);
    vector<int> b(1000, 0);
    vector<int> c(1000, 0);
    a[0] = 1;
    b[0] = 1;
    
    int termIndex = 2;

    while (c[999] == 0) {
        termIndex ++;
        int rem = 0;
        for (int i = 0; i < 1000; i++) {
            rem += a[i] + b[i];
            c[i] = rem % 10;
            rem /= 10;
        }
        a = b;
        b = c;
    }
    cout << "F" << termIndex << ": ";
    for (int i = 999; i >= 0; i--) cout << c[i];
    cout << endl;
}

