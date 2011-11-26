#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    for (int i = 0; i < 10; i++) v.push_back(i);
    sort(v.begin(), v.end());

    long long sum = 0;
    do {
        if ((v[1]*100 + v[2]*10 + v[3]) % 2 != 0) continue;
        if ((v[2]*100 + v[3]*10 + v[4]) % 3 != 0) continue;
        if ((v[3]*100 + v[4]*10 + v[5]) % 5 != 0) continue;
        if ((v[4]*100 + v[5]*10 + v[6]) % 7 != 0) continue;
        if ((v[5]*100 + v[6]*10 + v[7]) % 11 != 0) continue;
        if ((v[6]*100 + v[7]*10 + v[8]) % 13 != 0) continue;
        if ((v[7]*100 + v[8]*10 + v[9]) % 17 != 0) continue;

        for (int i = 0; i < 10; i++) cout << v[i];
        cout << endl;
        
        long long digit = 1;
        for (int i = 9; i >= 0; i--) {
            sum += v[i] * digit;
            digit *= 10;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << "A: " << sum << endl;
}
