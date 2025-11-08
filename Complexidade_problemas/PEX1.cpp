#include <bits/stdc++.h>

#define MAXN 100009

using ll = long long int;
using namespace std;

vector<pair<int, int>> adj[MAXN]; // lista com dest, peso

void reconstroi_caminho(vector<pair<ll, ll>> dist, int n) {

    vector<int> caminho;
    ll start = n;
    while (start != 1) {
        caminho.push_back(start);
        start = dist[start].second;
    }
    caminho.push_back(1); 

    for (int i = caminho.size() - 1; i > -1; i--) cout << caminho[i] << " ";
    cout << endl;
}

vector<pair<ll, ll>> dijkstra(int start, int end, int num_vertices, vector<pair<ll, ll>> dist) {
    for (int i =1; i <= num_vertices; i++) {
        dist[i].first = LLONG_MAX;
    }

    set<pair<int, int>> pq;
    dist[start].first = 0;
    pq.insert({0, start});
    while(!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());   
        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (dist[u].first + w < dist[v].first) {
                pq.erase({dist[v].first, v});
                dist[v].first = dist[u].first + w;
                dist[v].second = u;
                pq.insert({dist[v].first, v});
            }
        }
    }

    return dist;
}



void solve() {

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);  
        adj[b].emplace_back(a, w);
    }

    vector<pair<ll, ll>> dist(n + 1);
    dist = dijkstra(1, n, n, dist);

    if (dist[n].first == LLONG_MAX) {
        cout << "-1" << endl;
    } else {
        reconstroi_caminho(dist, n);
    }


}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}