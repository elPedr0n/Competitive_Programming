#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll t, li, co;
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> li >> co;

        if (li > co) {
            ll maior = li*li - (li - 1); //Valor da diagonal do bgl

            if (li % 2 == 1) cout << maior - (li -co) << endl;
            else cout << maior + (li - co) << endl;

        } else {

            ll maior = co*co - (co - 1);

            if (co % 2 == 1) cout << maior + (co -li) << endl;    
            else cout << maior - (co -li) << endl;
        } 
    }

    return 0;
}