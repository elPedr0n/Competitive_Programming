#include <bits/stdc++.h>

using namespace std;

// Vetor global que acumula o estado atual do subconjunto
vector<int> subset;
int n;

void search(int k) {
    if (k == n + 1) {
        // Terminou aqui pois decidimos sobre o último elemento 
        // Processa o subconjunto
        for (auto x : subset) {
            cout << x << " ";
        }
        cout << "\n";
    } else {
        // Podemos incluir o número atual no subconjunto
        subset.push_back(k);
        search(k+1);
        // Terminou de processar com ele então tiramos ele 
        subset.pop_back();
        // Processamos também sem esse número na lista
        search(k+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    search(1);
}