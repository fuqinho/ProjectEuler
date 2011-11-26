#include <iostream>
#include <vector>
using namespace std;

static const int MAX_HEIGHT = 100;

int main() {
    int temp;
    vector< vector<int> > input;
    for (int i = 1; i <= MAX_HEIGHT; i++) {
        vector<int> hoge;
        for (int j = 1; j <= i; j++) {
            cin >> temp;
            hoge.push_back(temp);
        }
        input.push_back(hoge);
    }

    for (int i = MAX_HEIGHT - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            input[i][j] += max(input[i+1][j], input[i+1][j+1]);
        }
    }

    cout << input[0][0] << endl;
}

