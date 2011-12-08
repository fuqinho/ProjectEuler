#include <iostream>
#include <vector>
using namespace std;

void printv(vector<int>& v) {
    for (int i = v.size()-1; i >= 0; i--) cerr << v[i];
    cerr << endl;
}

vector<int> sum(const vector<int>& v1, const vector<int>& v2) {
    int rem = 0;
    vector<int> v;
    for (int i = 0; i < v1.size() || i < v2.size(); i++) {
        rem += (i < v1.size() ? v1[i] : 0) + (i < v2.size() ? v2[i] : 0);
        v.push_back(rem % 10);
        rem /= 10;
    }
    while (rem > 0) {
        v.push_back(rem % 10);
        rem /= 10;
    }
    return v;
}

void mul(vector<int>& v, int m) {
    int rem = 0;
    for (int i = 0; i < v.size(); i++) {
        rem += v[i] * m;
        v[i] = rem % 10;
        rem /= 10;
    }
    while (rem > 0) {
        v.push_back(rem % 10);
        rem /= 10;
    }
}

int main() {
    int ans = 0;

    vector<int> n(1, 2);
    vector<int> d(1, 5);
    for (int i = 2; i <= 1000; i++) {
        vector<int> numerator = sum(d, n);
        vector<int> denominator = d;
        bool isMoreDigits = numerator.size() > denominator.size();
        if (isMoreDigits) ans ++;

        cout << "[" << i << "] ";
        printv(numerator);
        cout << "/";
        printv(denominator); 
        cout << (isMoreDigits ? " *" : "") << endl;

        // plus 2 and invert
        vector<int> d2 = d;
        mul(d2, 2);
        n = sum(n, d2);
        vector<int> tmp = d;
        d = n;
        n = tmp;
    }

    cout << "A: " << ans << endl;
}
