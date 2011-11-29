#include <iostream>
using namespace std;

int main() {
    int sum = 1;
    for (int i = 3; i <= 1001; i += 2) {
        sum += i*i + i*i-(i-1) + i*i-(i-1)*2 + i*i-(i-1)*3;
    }
    cout << sum << endl;
}
