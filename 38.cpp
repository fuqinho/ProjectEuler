#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

bool addToVec(vector<int>& v, int n) {
    bool isOverflow = false;
    while (n > 0) {
        v[n % 10]++;
        if (v[n % 10] > 1) isOverflow = true;
        n /= 10;
    }
    return isOverflow;
}

void printVec(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) cout << v[i];
    cout << endl;
}

string makePandigital(int d, int n) {
    stringstream ss;
    for (int i = n; i >= 1; i--) {
        int k = d * i;
        while (k > 0) {
            ss << (k % 10);
            k /= 10;
        }
    }
    string s = ss.str();
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    vector<int> goal(10, 1);
    goal[0] = 0;
    printVec(goal);

    string max = "123456789";
    for (int i = 2; i <= 9999; i++) {
        for (int j = 1; j <= 9; j++) {
            vector<int> used(10, 0);
            for (int k = 1; k <= j; k++) {
                bool isOverflow = addToVec(used, i*k);
                if (isOverflow) break;
                if (used == goal && k == j) {
                    string s = makePandigital(i, j);
                    cout << i << "," << j << endl;
                    cout << s << endl;
                    if (s > max) max = s;
                }
            }
        }
    }
    cout << "A: " << max << endl;
}
