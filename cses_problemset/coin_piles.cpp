#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

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


        if (((aa == bb and bb == 0) and ((a == 0 and b == 0) or (a != 0 and b != 0))) or (((aa == 2 and bb == 1) or (aa == 1 and bb == 2)) and (maior / 2 <= menor))) {
            cout << "YES\n";
        } else cout << "NO\n";
    }


    return 0;
}