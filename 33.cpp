#include <iostream>
using namespace std;

int main() {
    int num = 1, den = 1;
    for (int i1 = 1; i1 <= 9; i1++) {
        for (int i2 = 0; i2 <= 9; i2++) {
            for (int j1 = 1; j1 <= 9; j1++) {
                for (int j2 = 0; j2 <= 9; j2++) {
                    if (i1*10+i2 < j1*10+j2) {
                        if (i1 == j2) {
                            if ((i1*10+i2) * j1 == (j1*10+j2) * i2) {
                                cout << i1 << i2 << "/" << j1 << j2 << endl;
                                num *= i2;
                                den *= j1;
                            }
                        }
                        if (i2 == j1) {
                            if ((i1*10+i2) * j2 == (j1*10+j2) * i1) {
                                cout << i1 << i2 << "/" << j1 << j2 << endl;
                                num *= i1;
                                den *= j2;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << num << "/" << den << endl;
}
