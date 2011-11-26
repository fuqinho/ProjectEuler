#include <iostream>
#include <vector>
using namespace std;

static const int MAX_PRIME = 2000000;

int getScore(int a, int b, vector<bool>& isPrime) {
    int n = 0;
    while (true) {
        int temp = n*n + a*n + b;
        if (temp >= 0 && temp <= MAX_PRIME && isPrime[temp]) {
            n++;
        } else {
            return n;
        }
    }
}

int main() {
    vector<bool> isPrime(MAX_PRIME+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAX_PRIME; i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= MAX_PRIME; j+=i)
                isPrime[j] = false;
        }
    }

    //cerr << getScore(1, 41, isPrime) << endl;

    int maxScore = 0;
    int answer = 0;
    for (int a = -999; a < 1000; a++) {
        for (int b = -999; b < 1000; b++) {
            int score = getScore(a, b, isPrime);
            if (score > maxScore) {
                maxScore = score;
                answer = a * b;
                cerr << "a: " << a << " b: " << b << " score: " << score << endl;
            }
        }
    }

    cout << answer << endl;
}

