// #include <bits/stdc++.h>

#include<iostream>
#include<vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

void solve() {

    ll n, h = 0;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        queue<char> q;
        ll out = 0;
        for (int j = 0; j <= i; j++){ 
            if (s[j] = 'o') h = min(h+1, n-1);
        }




    }

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