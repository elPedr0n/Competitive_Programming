#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll t, a, b, maior, menor;
    cin >> t;

    for (int k = 0; k < t; k++) {

        cin >> a >> b;
        ll aa = a % 3, bb = b % 3;

        if (a > b) {
            maior = a;
            menor = b;
        } else  {
            maior = b;
            menor = a;
        }
        if ((aa == bb and bb != 0) or (aa == 0 and bb != 0) or (aa != 0 and bb == 0) or menor < maior / 2) {
            cout << "NO\n";
        } else  cout << "YES\n";
    
    }

}

int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}