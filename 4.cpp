#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int result = 0;
    for (int i = 0; i <= 999; i++) {
        for (int j = 0; j <= 999; j++) {
            int tmp = i * j;
            stringstream iss;
            iss << tmp;
            string tmps = iss.str();
            bool isPalin = true;
            for (int k = 0; k < tmps.size() / 2; k++) {
                if (tmps[k] != tmps[tmps.size()-1-k]) {
                    isPalin = false;
                }
            }
            if (isPalin) {
                result = max(result, tmp);
            }
        }
    }
    cout << result << endl;
}
