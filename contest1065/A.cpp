#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, out = 0, c = 0, v = 0;
    cin >> n;
    c = floor(n / 2);
    if (c > 0 and n % 2 == 0) {
        while (c*2  + v*4 <= n and c > -1) {
            out++;
            c-=2;
            v+=1;
        }
    }

    cout << out << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}