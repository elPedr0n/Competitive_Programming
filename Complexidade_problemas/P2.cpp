#include <bits/stdc++.h>

using namespace std;


int compara_linguagens(vector<int> a, vector<int> b) {
    for (int i = 0; i < a.size(); i++) {
        auto it = std::find(b.begin(), b.end(), a[i]);
        if (it != b.end()) return 1;
    }
    return 0;
}

void solve() {
    int n, m, componentes = 0, tem_aresta = 0;
    
    cin >> n >> m;
    
    vector<vector<int>> adj(n);
    vector<int> visitados(n, 0);
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> b;
            adj[i].push_back(b);
        }
    }
    
    
    for (int i = 0; i < n; i++) {
        
        if (!visitados[i]) {
            componentes++;
            //dfs
            stack<int> pilha;
            pilha.push(i);
            
            while (!pilha.empty()) {
                int u = pilha.top();
                pilha.pop();
                
                for (int j = 0; j < n; j++) {
                    if (i != j and !visitados[j] and compara_linguagens(adj[u],adj[j])) {
                        if (!tem_aresta) tem_aresta=1;
                        visitados[j] = 1;
                        pilha.push(j);
                    }
                }
            }
        }
    }
    
    int out = 0;
    if (!tem_aresta) {
        for (int i = 0; i < n; i++) {
            if (adj[i].size() > 0) {
                out = 1;
                break;
            }
        }
        cout << n - out;
    } else 
        cout << componentes - 1;
    
    
    
    
    
}

int main() {
    
    solve();

    return 0;
}