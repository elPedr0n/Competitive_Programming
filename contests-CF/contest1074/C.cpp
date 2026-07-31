#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());

    int mex = 0, atual = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i-1] + 1 == a[i]) {
            atual++;
        } else {
            mex = max(atual, mex);
            atual = 1;
        }
    }

    cout << max(mex, atual) << endl;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}


