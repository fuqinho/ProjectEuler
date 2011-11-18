#include <iostream>
using namespace std;

int main() {
    int val1 = 1, val2 = 2;
    int sum = 2;
    while (val1 + val2 <= 4000000) {
        int next = val1 + val2;
        val1 = val2;
        val2 = next;
        if (next % 2 == 0) sum += next;
    }
    cout << sum << endl;
}
