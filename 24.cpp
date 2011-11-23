#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> p;
    for (int i = 0; i <= 9; i++) p.push_back(i);

    int loop = 0;
    do {
        loop++;
        if (loop == 1000000) {
            for (int i = 0; i <= 9; i++) cout << p[i];
            cout << endl;
            break;
        }
    } while (next_permutation(p.begin(), p.end()));
}

