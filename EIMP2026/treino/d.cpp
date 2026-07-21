#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct {
    ll p;
    vector<ll> n;
} node;

void solve() {

    ll n, m, k;
    cin >> n >> m >> k;
    vector<node> g(n+1);
    for (ll i = 1; i <= n; i++) cin >> g[i].p;
    
    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].n.push_back(y);
        g[y].n.push_back(x);
    }

    // Agora metemos o bfs
    vector<ll> max_dists(k+1, 0);
    vector<bool> vis(n+1, false);
    queue<pair<node, ll>> q;

    ll dist_atual = 0;
    q.push({g[1], dist_atual});
    vis[1] = true;

    while (!q.empty()) {
 
        // cout << "dist atual = " << dist_atual << endl;
        pair<node, ll> curr = q.front();
        q.pop();
        if (max_dists[curr.first.p] < curr.second) max_dists[curr.first.p] = curr.second;

        for (ll nd : curr.first.n) {
            if (!vis[nd]) {
                vis[nd] = true;
                q.push({g[nd], curr.second+1});
            }
        }


    }

    for (int t = 1; t <= k; t++) cout << max_dists[t] << ' ';
    cout << endl;

}

int main() {

    solve();

    return 0;

}