#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> decNum(1000, 0);
    decNum[0] = 1;

    int rem = 0;

    for (int n = 0; n < 1000; n++) {
        for (int i = 0; i < 1000; i++) {
            rem = decNum[i] * 2 + rem;
            decNum[i] = rem % 10;
            rem /= 10;
        }
    }

    int result = 0;
    for (int i = 0; i < 1000; i++) {
        result += decNum[i];
    }
    cout << result << endl;
}
