#include <iostream>
#include <vector>
#include <string>

#define all(x) x.begin(), x.end()
#define fori(x, a, b) for (int i = x; i < a; i += b)
#define forj(x, a, b) for (int j = x; j < a; j += b)

using namespace std;

void rabinKarp(string &s, string &t){
    const int p = 31;
    int tl = (int)t.length();
    vector<long long> p_pow(tl);
    p_pow[0] = 1;
    
    fori(1, p_pow.size(), 1)
        p_pow[i] = p_pow[i - 1] * p;

    vector<long long> h(tl);
    fori(0, tl, 1) {
        h[i] = (t[i] - 'a' + 1) * p_pow[i];
        if (i) {
            h[i] += h[i - 1];
        }
    }

    int sl = (int)s.length();

    if (sl > tl) {
        cout << "No\n";
        return;
    }

    long long h_s = 0;
    fori(0, sl, 1)
        h_s += (s[i] - 'a' + 1) * p_pow[i];

    bool found = false;
    fori(0, tl - sl, 1) {
        long long cur_h = h[i + sl - 1];
        if (i)
            cur_h -= h[i - 1];
        if (cur_h == h_s * p_pow[i] && s == t.substr(i, sl)) {
            found = true;
            break;
        }
    }

    cout << (found ? "Yes\n" : "No\n");
}
