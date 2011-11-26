#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> input;
    string tmp;
    for (int i = 0; i < 5163; i++) {
        cin >> tmp;
        input.push_back(tmp);
    }

    sort(input.begin(), input.end());
    long long ans = 0;
    for (int i = 0; i < input.size(); i++) {
        int score = 0;
        for (int j = 0; j < input[i].size(); j++) {
            score += input[i][j] - 'A' + 1;
        }
        ans += score * (i + 1);
    }
    cout << ans << endl;
}
