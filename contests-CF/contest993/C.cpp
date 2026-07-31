#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        ll a, b, c, m, r1, r2, out = 0;
        cin >> m >> a >> b >> c;
        r1 = m, r2 = m;

        if (r1 > a) {
            out += a;
            r1-=a;
        } else {
            out += r1;
            r1 = 0;
        }

        if (r2 > b) {
            out += b;
            r2-=b;
        } else {
            out += r2;
            r2 = 0;
        }

        if (r1 + r2 > c) {
            out+=c;
        } else {
            out += r1+r2;
        }

        cout << out << endl;

    }

    return 0;
}