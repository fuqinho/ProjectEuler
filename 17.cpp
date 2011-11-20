#include <iostream>
using namespace std;

string LETTER_X[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string LETTER_Xx[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string makeLetter(int n) {
    string result = "";
    if (n >= 1000) {
        result += LETTER_X[n / 1000] + "thousand";
        if (n % 1000 != 0) {
            result += "and";
        }
    }
    if (n % 1000 >= 100) {
        result += LETTER_X[(n % 1000) / 100] + "hundred";
        if (n % 100 != 0) {
            result += "and";
        }
    }
    if (n % 100 >= 20) {
        result += LETTER_Xx[(n % 100) / 10] + LETTER_X[n % 10];
    } else if (n % 100 > 0) {
        result += LETTER_X[n % 100];
    }
    return result;
}

int countLetter(int n) {
    string letter = makeLetter(n);
    cout << n << ": " << letter << " (" << letter.size() << ")" << endl;
    return letter.size();
}

int main() {
    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        sum += countLetter(i);
    }
    cout << sum << endl;
}
