#include <iostream>
#include <vector>
using namespace std;

static const int MAX_NUM = 2000000;

int main() {
    vector<bool> isPrime(MAX_NUM + 1, true);
    isPrime[0] = isPrime[1] = false;
    long long sum = 0;
    for (int i = 2; i <= MAX_NUM; i++) {
        if (isPrime[i]) {
            sum += i;
            //cerr << i << " ";
            for (int j = i * 2; j <= MAX_NUM; j += i) {
                isPrime[j] = false;
            }
        }
    }
    cout << sum << endl;
}
