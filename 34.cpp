#include <iostream>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int factorial(int n) {
    int ret = 1;
    for (int i = 2; i <= n; i++) {
        ret *= i;
    }
    return ret;
}

int main() {
    int sum = 0;
    REP(i, 10) REP(j, 10) REP(k, 10) REP(l, 10) REP(m, 10) REP(n, 10) REP(o, 10) {
        int num = i*1000000 + j*100000 + k*10000 + l*1000 + m*100 + n*10 + o;
        int fac = factorial(i) + factorial(j) + factorial(k) + factorial(l) 
                + factorial(m) + factorial(n) + factorial(o);
        int digits = 7;
        if (i==0) {
            digits--;
            if (j==0) {
                digits--;
                if (k==0) {
                    digits--;
                    if (l==0) {
                        digits--;
                        if (m==0) {
                            digits--;
                            if (n==0) {
                                digits--;
                            }
                        }
                    }
                }
            }
        }
        fac -= 7-digits;
    
        if (num == fac && digits >= 2) {
            cout << i << j << k << l << m << n << o << endl;
            sum += num;
        }
    }
    cout << "A: " << sum << endl;
}
