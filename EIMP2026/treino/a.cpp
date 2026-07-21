#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



void solve() {

    ll a;
    cin >> a;
    vector<ll> f(a+1);
    for (int i = 1; i <= a; i++) {   
        cin >> f[i];
    }

    for (int i = 1; i <= a; i++) {
        if (f[f[f[i]]] == i) {cout << "YES" << endl; return;}
    }
    cout << "NO" << endl;


}

int main() {

    solve();

    return 0;

}