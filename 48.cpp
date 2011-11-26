#include "common.h"

static const int MAX_DIGITS = 10;

vector<int> get_vec(int n) {
    vector<int> v(MAX_DIGITS, 0);
    for (int i = 0; i < v.size(); i++) {
        v[i] = n % 10;
        n /= 10;
    }
    return v;
}

vector<int> pow_vec(int a, int b) {
    vector<int> v = get_vec(a);
    for (int i = 0; i < b - 1; i++) {
        int rem = 0;
        for (int j = 0; j < MAX_DIGITS; j++) {
            rem += v[j] * a;
            v[j] = rem % 10;
            rem /= 10;
        }
    }
    return v;
}

void add_vec(vector<int>& v1, const vector<int>& v2) {
    int rem = 0;
    vector<int> v;
    for (int i = 0; i < MAX_DIGITS; i++) {
        rem += v1[i] + v2[i];
        v1[i] = rem % 10;
        rem /= 10;
    }
}

int main() {
    vector<int> v(MAX_DIGITS, 0);
    for (int i = 1; i <= 1000; i++) {
        add_vec(v, pow_vec(i, i));
    }
    for (int i = MAX_DIGITS-1; i>=0; i--) {
        cout << v[i];
    }
    cout << endl;
}
