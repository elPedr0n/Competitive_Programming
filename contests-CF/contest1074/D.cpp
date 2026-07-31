#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> aux;
    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> b >> c;
        if (a[b] + c <= h) {
            aux.push_back({a[b], b});
            a[b] += c;
        } else {
            // int size = aux.size();
            // cout << "size of size: " << size << endl;
            while (!aux.empty()) {
                pair<int, int> p = aux.back();
                aux.pop_back();
                a[p.second] = p.first;
            }
            // cout << "size of size: " << size << endl;
        }   
    }

    for (int x = 1; x <= n; x++) {
        cout << a[x] << ' ';
    }
    cout << endl;

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


