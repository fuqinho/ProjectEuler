#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector< vector<int> > input;
    for (int i = 0; i < 20; i++) {
        vector<int> tvec;
        for (int j = 0; j < 20; j++) {
            int tmp;
            cin >> tmp;
            tvec.push_back(tmp);
        }
        input.push_back(tvec);
    }

    int maxProd = 0;
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {
            maxProd = max(maxProd, input[i][j]*input[i+1][j+1]*input[i+2][j+2]*input[i+3][j+3]);
        }
        for (int j = 3; j < 20; j++) {
            maxProd = max(maxProd, input[i][j]*input[i+1][j-1]*input[i+2][j-2]*input[i+3][j-3]);
        }
    }

    cout << maxProd << endl;
}
