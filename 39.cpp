#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> solutions(1001, 0);
    for (int i = 1; i <= 1000; i++) {
        for (int j = i; i+j <= 1000; j++) {
            for (int k = j; i+j+k <= 1000; k++) {
                if (i * i + j * j == k * k) {
                    solutions[i+j+k]++;
                }
            }
        }
    }

    int maxCount = 0;
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        if (solutions[i] > maxCount) {
            ans = i;
            maxCount = solutions[i];
        }
    }
    cout << "A: " << ans << endl;
}
