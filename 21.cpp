#include <iostream>
#include <vector>
using namespace std;

static const int MAX_NUM = 10000;

int getD(int n) {
    int ret = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) ret += i;
    }
    return ret;
}

int main() {
    vector<int> d(MAX_NUM+1, 0);
    for (int i = 1; i <= MAX_NUM; i++) {
        d[i] = getD(i);
    }

    int ans = 0; 
    for (int i = 1; i <= MAX_NUM; i++) {
        cerr << i << ": " << d[i] << endl;
        if (d[i] != i && d[i] <= MAX_NUM && d[d[i]] == i) {
            cout << d[i] << endl;
            ans += i;
        }
    }
    cout << "Answer: " << ans << endl;
}
