#include <bits/stdc++.h>

using namespace std;

const int n = 4;
vector<int> permutation;
bool chosen[n+1];

void search() {
    if (permutation.size() == n) {
        // Chegamos ao tamanho máximo então podemos processar 
        for (auto x : permutation) {
            cout << x << " ";
        }
        cout << "\n";
    } else { 
        for (int i = 1; i <= n; i++) {
            // Se já usamos pulamos 
            if (chosen[i]) continue;

            // Podemos escolher esse elemento agora
            chosen[i] = true;
            permutation.push_back(i);
            search();

            // Ou pulamos e processaremos ele em outro momento
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {

    search();

    return 0;
}