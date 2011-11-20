#include <iostream>
#include <vector>
using namespace std;

int main() {
    string tmp;
    vector<string> input;
    for (int i = 0; i < 100; i++) {
        cin >> tmp;
        input.push_back(tmp);
    }

    vector<int> res;
    int rem = 0;
    for (int i = 49; i >= 0; i--) {
        for (int j = 0; j < 100; j++) {
            rem += input[j][i] - '0';
        }
        res.push_back(rem % 10);
        rem /= 10;
    }
    while (rem != 0) {
        res.push_back(rem % 10);
        rem /= 10;
    }

    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    cout << endl;
}
