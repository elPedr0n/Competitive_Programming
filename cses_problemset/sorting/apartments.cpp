// #include <bits/stdc++.h>
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    set<ll> aptos;
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        aptos.insert(x);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = aptos.lower_bound(d[i] - k);
        if (it != aptos.end() && *it <= d[i] + k) {
            ans++;
            aptos.erase(it);
        }
    }

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }
}