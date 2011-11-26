#include <iostream>
using namespace std;

static const int THRESH = 1000000;

double factorial(int n, int r) {
    if (n - r < r) r = n - r;
    double ans = 1;
    for (int i = 0; i < r; i++) {
        ans *= n-i;
        ans /= r-i;
        if (ans > THRESH * 10) return 99999999.0;
    }
    return ans;
}

int main() {
    int count = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= i; j++) {
            //cout << i << " C " << j << " = " << factorial(i, j) <<endl;
            if (factorial(i, j) - THRESH < 0.01 && THRESH - factorial(i, j) < 0.01) cout << "WARNING!!" << endl;
            if (factorial(i, j) > THRESH) count++;
        }
    }
    cout << "A: " << count << endl;
    //cout << factorial(23, 10) << endl;
}
