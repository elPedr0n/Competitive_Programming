#include <iostream>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        
        ll x;
        cin >> x;

        if (mp.count(x) < 1) {
            mp[x] = 1;
        } else {
            mp[x]++;
        }
    
    }

}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin>> t;
    while (t--) {
        solve();
    }

    return 0;
}