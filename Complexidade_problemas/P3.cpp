#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n, k, d;
    
    cin >> n >> k >> d;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> police_nodes(k);
    vector<bool> is_police(n + 1, false);

    for (int i = 0; i < k; i++) {
        cin >> police_nodes[i];
        is_police[police_nodes[i]] = true;
    }
    
    for (int i = 1; i < n; i++) {
        int u, v;
        if (!(cin >> u >> v)) return;
        
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    vector<int> dist(n + 1, 1e9); 
    
    vector<int> source_node(n + 1, 0); 
    
    queue<pair<int, int>> bfs;

    for (int p_node : police_nodes) {
        dist[p_node] = 0;
        source_node[p_node] = p_node;
        bfs.push({p_node, 0});
    }

    // Executa a busca em largura
    while (!bfs.empty()) {
        pair<int, int> current = bfs.front();
        bfs.pop();
        
        int u = current.first;
        int current_dist = current.second;
        
        if (current_dist >= d) continue;
        
        for (const auto& edge : adj[u]) {
            int v = edge.first; // O nó vizinho
            
             if (current_dist + 1 < dist[v]) {
                dist[v] = current_dist + 1;
                source_node[v] = source_node[u]; 
                bfs.push({v, dist[v]});
            }
        }
    }
    
    
    vector<int> edges_to_remove;
    
    for (int u = 1; u <= n; ++u) {
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int edge_index = edge.second;
            
            if (u < v) {
               
                if (source_node[u] != 0 && source_node[v] != 0 && source_node[u] != source_node[v]) {
                   
                    edges_to_remove.push_back(edge_index);
                }
            }
        }
    }

    sort(edges_to_remove.begin(), edges_to_remove.end());
    
    // Impressão do resultado
    cout << edges_to_remove.size() << endl;
    for (size_t i = 0; i < edges_to_remove.size(); ++i) {
        cout << edges_to_remove[i] << (i == edges_to_remove.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main()
{
    solve();
    
    return 0;
}