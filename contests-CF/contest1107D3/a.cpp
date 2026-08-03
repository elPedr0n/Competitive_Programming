#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {

    ll x, y;

    cin >> x >> y;

    if (x >= y) {
        if (x % y == 0) {
            cout << "YES" << endl;
        } else {
            cout <<"NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }


}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }
}