#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll calc_soma(int v, int k) {
    ll out = v, e = 1;

    while (floor(v/pow(k, e)) > 0) {
        out += floor(v/pow(k, e));
        e++;
    }

    return out;
}

void solve() {

    ll n, k;
    cin >> n >> k;

    ll low = 1, high = n, menor_diff = 1e11, menor = 1e11, att;

    while (low <= high) {

        ll v = low + (high - low) / 2;

        att = calc_soma(v, k);
        if (att < n) {
            low = v+1;
        } else if (att > n) {
            if (menor_diff > att) {
                menor = v;
                menor_diff = att;
            } 
            high = v-1;            
        } else {
            menor = v;
            break;
        }
    }

    cout << menor << endl;

}

int main() {
    

    solve();

    return 0;
}