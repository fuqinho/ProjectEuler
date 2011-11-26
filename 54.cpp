#include <iostream>
#include <vector>
using namespace std;

int getRank(vector<string> p) {
    vector<int> nums;
    for (int i = 0; i < 5; i++) {
        if (p[i][0] > 
    }
}

bool getWinner(vector<string> p1, vector<string> p2) {
    
    return true;
}

int main() {
    for (int t = 1; t <= 1000; t++) {
        string temp;
        vector<string> s1, s2;
        for (int i = 0; i < 5; i++) {
            cin >> temp;
            s1.push_back(temp);
        }
        for (int i = 0; i < 5; i++) {
            cin >> temp;
            s2.push_back(temp);
        }
        bool p1win = getWinner(s1, s2);
        cout << t << ": " << (p1win ? "Player 1" : "Player 2") << endl;
    }
}
