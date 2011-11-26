#include <iostream>
#include <vector>
using namespace std;

vector<int> digitsList(int n) {
    vector<int> v(10, 0);
    while (n > 0) {
        v[n % 10] ++;
        n /= 10;
    }
    return v;
}

int main() {
    for (int i = 0; i < 1000000; i++) {
        vector<int> v = digitsList(i);
        if (digitsList(i*2) == v && digitsList(i*3) == v && digitsList(i*4) == v
                && digitsList(i*5) == v && digitsList(i*6) == v) {
            cout << i << endl;
        }
    }
}

