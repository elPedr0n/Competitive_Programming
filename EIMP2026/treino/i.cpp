#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
typedef long long ll;

void solve() {

    ll as, bs;
    cin >> as >> bs;

    vector<ll> a(as), b(bs);
    for (int i = 0; i < as; i++) cin >> a[i];
    for (int i = 0; i < bs; i++) cin >> b[i];

    sort(a.begin(), a.end());
    for (int i = 0; i < bs; i++) {
        cout << upper_bound(a.begin(), a.end(), b[i]) - a.begin() << ' ';
    }

    cout << endl;
}

int main() {

    solve();

    return 0;

}