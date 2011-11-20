#include <iostream>
using namespace std;

static const int MAX_NUM = 1000000;
int chain_count[MAX_NUM + 1];

// memoized recursion
int getChainCount(long long n) {
    int result;
    if (n > MAX_NUM || chain_count[n] == 0) {
        if (n % 2 == 0) {
            result = 1 + getChainCount(n / 2);
            if (n <= MAX_NUM) chain_count[n] = result;
        } else {
            result = 1 + getChainCount(n * 3 + 1);
            if (n <= MAX_NUM) chain_count[n] = result;
        }
    } else {
        result = chain_count[n];
    }
    return result;
}

int main() {
    chain_count[1] = 1;

    int max_chain_count = 0;
    int maxStart;
    for (int i = 2; i <= MAX_NUM; i++) {
        if (getChainCount(i) >= max_chain_count) {
            max_chain_count = getChainCount(i);
            maxStart = i;
        }
    }

    cout << "start: " << maxStart << ", chain: " << max_chain_count << endl;
}
