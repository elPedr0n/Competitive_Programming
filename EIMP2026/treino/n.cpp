#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;
typedef long long ll;

#define MAXN 200309

int n, t[4*MAXN] = {0};

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2],t[v*2+1]); 
    }
}

int f_max(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(f_max(v*2, tl, tm, l, min(r, tm)),
           f_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

// void update(int v, int tl, int tr, int pos, int new_val, int prof) {
//     if (tl == tr) {
//         t[v] = new_val;
//     } else {
//         int tm = (tl + tr) / 2;
//         if (pos <= tm)
//             update(v*2, tl, tm, pos, new_val, prof-1);
//         else
//             update(v*2+1, tm+1, tr, pos, new_val, prof-1);
//         t[v] = prof % 2 == 0 ? t[v*2] ^ t[v*2+1] : t[v*2] | t[v*2+1];    
//     }
// }

void solve() {

    cin >> n;
    int a[n] = {0};
    for (int i = 0; i < n; i++) cin >> a[i];


    // Fazemos a contrucao aq da seg tree
    build(a, 1, 0, n);


    for (int i = 0; i < 50; i++) {
        cout << t[i] << ' ';
    }
    cout << endl;

    ll m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll l, r;
        cin >> l >> r;
        cout << f_max(1, 0, n, l, r) << endl;
    }

    

}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}