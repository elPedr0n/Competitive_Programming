// #include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;
typedef long long ll;

void solve() {

    ll n;
    cin >> n;

    set<ll> s;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << endl;

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