#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
    for (int k = 0; k < 10; k++)
    for (int l = 0; l < 10; l++) 
    for (int m = 0; m < 10; m++)
    for (int n = 0; n < 10; n++) {
        int sum = i*i*i*i*i;
        sum += j*j*j*j*j;
        sum += k*k*k*k*k;
        sum += l*l*l*l*l;
        sum += m*m*m*m*m;
        sum += n*n*n*n*n;
        if (sum == i*100000 + j*10000 + k*1000 + l*100 + m*10 + n) {
            int digits = (i==0?0:1) + (j==0?0:1) + (k==0?0:1) 
                + (l==0?0:1) + (m==0?0:1) + (n==0?0:1);
            if (digits >= 2) {
                cout << i << j << k << l << m << n << endl;
                ans += sum;
            }
        }
    }
    cout << "A: " << ans << endl;
}

