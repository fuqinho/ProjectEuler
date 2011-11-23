#include <iostream>
using namespace std;

static const int DAYS1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const int DAYS2[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const string WEEK[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int main() {
    int day = 1; // monday
    int result = 0;
    for (int i = 1900; i <= 2000; i++) {
        bool isLeap = (i % 4 == 0);
        if (i % 100 == 0) isLeap = false;
        if (i % 400 == 0) isLeap = true;
        for (int j = 0; j < 12; j++) {
            if (day == 0 && i >= 1901) {
                cout << i << "/" << j+1 << "/1 is " << WEEK[day] << endl;
                result++;
            }
            day = (day + (isLeap ? DAYS2[j] : DAYS1[j])) % 7;
        }
    }
    cout << result << endl;
}
