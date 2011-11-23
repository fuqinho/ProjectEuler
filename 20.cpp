#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> number(1000, 0);
    number[0] = 1;
    int rem = 0;
    for (int i = 2; i <= 100; i++) {
        for (int j = 0; j < number.size(); j++) {
            rem += number[j] * i;
            number[j] = rem % 10;
            rem /= 10;
        }
    }
    int result = 0;
    for (int i = number.size() - 1; i >= 0; i--) {
        result += number[i];
    }
    cout << result << endl;
}

