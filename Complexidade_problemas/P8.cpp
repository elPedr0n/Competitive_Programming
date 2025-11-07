#include <bits/stdc++.h>

using namespace std;

bool segundoMaior(tuple<int, int, int> &a, tuple<int, int, int>&b) {
    return get<1>(a) > get<1>(b);
}

bool primeiroMenor(tuple<int, int, int> &a, tuple<int, int, int>&b) {
    return get<0>(a) < get<0>(b);
}

bool primeiroMenor2(tuple<int, int, int> &a, int b) {
    return get<0>(a) < b;
}

void solve() {
    int n, k;
    cin >> n;
    vector<tuple<int, int, int>> grupos(n+1, {0, 0, 0}); //pessoas, money, indice
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        grupos[i] = {a, b, i};
    }

    cin >> k;
    vector<tuple<int, int, int>> mesas(k+1); //qtd, gp_ocupando
    vector<pair<int, int>> respostas;
    for (int i = 1; i <= k; i++) {
        int c;
        cin >> c;
        mesas[i] = {c, 0, i};
    }

    sort(grupos.begin()+1, grupos.end(), segundoMaior);
    sort(mesas.begin()+1, mesas.end(), primeiroMenor);

    int sum = 0, ocupadas = 0;
    for (int i = 1; i <= n; i++) {
        auto gp = grupos[i];

        auto it = lower_bound(mesas.begin()+1, mesas.end(), get<0>(gp), primeiroMenor2);
        if (it == mesas.end()) continue;

        if (get<1>(mesas[it - mesas.begin()]) == 0) {
            respostas.push_back({get<2>(gp), get<2>(mesas[it - mesas.begin()])});
            mesas.erase(it);
            sum+= get<1>(gp);
            ocupadas++;
        }
    }

    cout << ocupadas << " " << sum << "\n";
    for (auto p : respostas) {
        cout << p.first << " " << p.second << "\n";
    }
    
}

int main() {
    
    solve();

    return 0;
}