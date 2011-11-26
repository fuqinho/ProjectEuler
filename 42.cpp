#include <iostream>
#include <vector>
using namespace std;

static const int MAX_TRI = 100000;

int getValue(string s) {
    int v = 0;
    for (int i = 0; i < s.size(); i++) {
        v += s[i] - 'A' + 1;
    }
    return v;
}

int main() {

    vector<bool> isTriangle(MAX_TRI+1, false);
    for (int i = 1; ; i++) {
        int n = i * (i + 1) / 2;
        if (n <= MAX_TRI) {
            isTriangle[n] = true;
        } else {
            break;
        }
    }

    int count = 0;
    string word;
    for (int i = 0; i < 1786; i++) {
        cin >> word;
        if (isTriangle[getValue(word)]) count++; 
    }

    cout << count << endl;
}

