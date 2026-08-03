#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fatorial(ll n) {
    if (n == 1) return 1;
    else return fatorial(n-1)*n;
}

void solve() {

    string s;
    cin >> s;

    map<char, ll> mp;
    for (auto c : s) {
        if(mp.count(c) > 0) mp[c]+=1;
        else mp[c]=1;
    }

    ll f = fatorial((ll)s.size());
    for (auto c : mp) {
        if (c.second > 1) f /= fatorial(c.second);
    }

    cout << f << "\n";

    // Calcular as permutações usando next permutations
    sort(s.begin(), s.end());

    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));



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