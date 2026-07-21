#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct {
    ll p;
    vector<ll> n;
} node;

void solve() {

    int n, m, v;
    cin >> n >> m >> v;
    if (n * m -1 == v) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main() {

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;

}