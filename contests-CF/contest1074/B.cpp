#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, maximum = -1, index_max = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > maximum) {
            maximum = a[i];
            index_max = i;
        }
    }
    cout << n * maximum << endl;
}

int main() {

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}


