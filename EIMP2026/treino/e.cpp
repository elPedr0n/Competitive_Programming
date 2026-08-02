#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;
typedef long long ll;

void solve() {

    ll n;
    cin >> n;
    string a, b;
     
    cin >> a;
    cin >> b;

    ll out = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == '0') continue;

        if (a[i] == '0') {
            out++;
            a[i] = 1;
        } else {
            if (i - 1 >= 0 && a[i-1] == '1') {
                out++;
            } else if (i + 1 < n && a[i+1] == '1') {
                out++;
                a[i+1] = 1;
            }
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