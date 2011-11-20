#include <iostream>
using namespace std;

long long pat[21][21];

int main() {
    for (int i = 0; i < 21; i++) {
        pat[0][i] = 1;
        pat[i][0] = 1;
    }

    for (int i = 1; i < 21; i++) {
        for (int j = 1; j < 21; j++) {
            pat[i][j] = pat[i-1][j] + pat[i][j-1];
        }
    }
    cout << pat[20][20] << endl;
}
