#include <iostream>
#include <vector>
using namespace std;

void printv(vector<int>& v) {
    for (int i = v.size()-1; i >= 0; i--) cerr << v[i];
    cerr << endl;
}

vector<int> makeBigInt(int a, int b) {
    vector<int> v;
    int n = a;
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }

    for (int i = 1; i < b; i++) {
        int rem = 0;
        for (int j = 0; j < v.size(); j++) {
            rem += v[j] * a;
            v[j] = rem % 10;
            rem /= 10;
        }
        while (rem > 0) {
            v.push_back(rem % 10);
            rem /= 10;
        }
    }
    return v;
}

int countDigits(const vector<int>& v) {
    int res = 0;
    for (int i = 0; i < v.size(); i++) res += v[i];
    return res;
}

int main() {
    int maxDigits = 0;
    for (int a = 1; a < 100; a++) {
        for (int b = 1; b < 100; b++) {
            vector<int> v = makeBigInt(a, b);
            maxDigits = max(maxDigits, countDigits(v));
        }
    }
    cout << "A: " << maxDigits << endl;
}



