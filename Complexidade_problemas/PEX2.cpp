#include <bits/stdc++.h>

using namespace std;

using ll = long long;


bool aux(ll a, ll b) {
    return a <= b;
}

void solve() {

    ll x, y;
    cin >> x >> y;

    vector<ll> a(x), b(y), out(y);

    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < y; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < y; i++) {
        out[i] = lower_bound(a.begin(), a.end(), b[i], aux) - a.begin();
    }


    for (auto o : out) {
        cout << o << " ";
    }
    cout << endl;
}

int main() {
    
    
    solve();

    return 0;
}