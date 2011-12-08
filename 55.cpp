#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printv(vector<int>& v) {
    for (int i = v.size()-1; i >= 0; i--) cerr << v[i];
    cerr << endl;
}

bool isLychrel(int n){
    vector<int> v;
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }

    for (int i = 0; i < 50; i++) {
        vector<int> v_reversed = v;
        reverse(v_reversed.begin(), v_reversed.end());

        // v + v_reversed
        int rem = 0;
        for (int j = 0; j < v.size(); j++) {
            rem += v[j] + v_reversed[j];
            v[j] = rem % 10;
            rem /= 10;
        }
        if (rem > 0) v.push_back(rem);

        // check parindrome
        printv(v);

        vector<int> tmp = v;
        reverse(tmp.begin(), tmp.end());
        if (v == tmp) {
            return false;
        }
    }
    return true;
}

int main() {
    int answer = 0;
    for (int i = 1; i < 10000; i++) {
        cerr << "== checking " << i << "..." << endl;
        if (isLychrel(i)) answer++;
    }
    cout << "A: " << answer << endl;
}
