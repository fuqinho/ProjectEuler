#include <iostream>
using namespace std;



int main() {
    int target = 200;
    int curSum = 0;
    int counts = 0;
    for (int i = 0; i*200 <= 200; i++) {
        int curSum1 = i*200;
        for (int j = 0; curSum1 + j*100 <= 200; j++) {
            int curSum2 = curSum1 + j*100;
            for (int k = 0; curSum2 + k*50 <= 200; k++) {
                int curSum3 = curSum2 + k*50;
                for (int l = 0; curSum3 + l*20 <= 200; l++) {
                    int curSum4 = curSum3 + l*20;
                    for (int m = 0; curSum4 + m*10 <= 200; m++) {
                        int curSum5 = curSum4 + m*10;
                        for (int n = 0; curSum4 + n*5 <= 200; n++) {
                            int curSum6 = curSum5 + n*5;
                            for (int o = 0; curSum6 + o*2 <= 200; o++) {
                                int curSum7 = curSum6 + o*2;
                                //cout << i << " " << j << " " << k << " " << l << " " << m << " " << n << " " << o << " " << 200-curSum7 << endl;
                                counts++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << counts << endl;
}
