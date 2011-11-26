#include "common.h"


int main() {
    int foundCount = 0;
    map<long long, int> m;
    for (long long i = 0; ; i++) {
        long long t = i * (i+1) / 2;
        if (m.find(t) == m.end()) 
            m.insert(make_pair(t, 1));
        else
            m[t]++;
        if (m[t] == 3) {
            cout << t << endl;
            foundCount++;
            if (foundCount >= 2) break;
        }


        long long p = i * (3 * i - 1) / 2;
        if (m.find(p) == m.end())
            m.insert(make_pair(p, 1));
        else
            m[p]++;

        long long h = i * (2 * i - 1);
        if (m.find(h) == m.end())
            m.insert(make_pair(h, 1));
        else
            m[h]++;
    }
}
