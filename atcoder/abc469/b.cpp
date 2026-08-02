// #include <bits/stdc++.h>

#include<iostream>
#include<vector>
#include <cmath>
#include <string>

using namespace std;
typedef long long ll;

void solve() {

    ll n;
    cin  >> n;
    string s;
    cin >> s;

    bool ok = false;
    ll out = 0;
    int a[] = {-1, 1};

    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') {
            ok = false;
            for (int j = 0; j < 2; j++) {
                int k = i + a[j];
                if (k >= 0 && k < n) {
                    if (s[k] == 'o') {
                        ok = true;
                    }
                }
            }
            if (!ok) {
                // cout << i << endl;
                out++;
                ok = false;
            }
        } 
        
    }

    cout << out << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }
}