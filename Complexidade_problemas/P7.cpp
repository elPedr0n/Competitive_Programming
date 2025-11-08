#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

using ll = long long;
 
//Peguei uma estrutura de fenwick tree ja pronta
struct FenwickTree {
    vector<int> tree;
    int size;

    FenwickTree(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }

    void update(int idx, int delta) {
        for (; idx <= size; idx += idx & -idx) {
            tree[idx] += delta;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }

    int query_lt(int idx) {
        return query(idx - 1);
    }
};


void solve() {
    int n;

    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    const int MAX_FREQ = n; 
    
    vector<int> F1(n);
    map<int, int> count_prefix; 
    for (int i = 0; i < n; ++i) {
        count_prefix[a[i]]++;
        F1[i] = count_prefix[a[i]];
    }

    vector<int> F2(n);
    map<int, int> count_suffix;
    for (int i = n - 1; i >= 0; --i) {
        count_suffix[a[i]]++;
        F2[i] = count_suffix[a[i]];
    }
    
    FenwickTree bit(MAX_FREQ);
    ll total_pairs = 0;

    for (int i = n - 1; i >= 0; --i) {
        
        if (F1[i] > 1) { 
            total_pairs += bit.query_lt(F1[i]);
        }
        
        
        bit.update(F2[i], 1);
    }
    
    cout << total_pairs << endl;
}

int main() {
    // Configurações para I/O rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}