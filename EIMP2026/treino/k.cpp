#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;
typedef long long ll;

void solve() {

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n+1);

    for (int i = 1; i <= n; i++) cin >> a[i];

    ll min_h = 1000000, ind = k-1;
    for (int i = k; i <= n; i++) {
        ll sum = 0;
        for (int j = 0; j < k; j++) {
            sum += a[i - j];
        }
        if (sum < min_h) {
            min_h = sum;
            ind = i-k+1;
            // cout << ind << endl;
            // cout << min_h << endl; 
        }
    }

    cout << ind << endl;

}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>> t
    while (t--) {
        solve();
    }

    return 0;
}