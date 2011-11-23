#include <iostream>
#include <vector>
using namespace std;

static const int MAX_NUM = 28123;

int main() {
    vector<int> abList;
    for (int i = 2; i <= MAX_NUM; i++) {
        int sum = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) sum += j;
        }
        if (sum > i) {
            abList.push_back(i);
        }
    }

    vector<bool> isAbunSum(MAX_NUM + 1, false);
    for (int i = 0; i < abList.size(); i++) {
        for (int j = 0; j < abList.size(); j++) {
            if (abList[i] + abList[j] <= MAX_NUM) {
                isAbunSum[abList[i] + abList[j]] = true;
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= MAX_NUM; i++) {
        if (!isAbunSum[i]) ans += i;
    }
    
    cout << ans << endl;
}
