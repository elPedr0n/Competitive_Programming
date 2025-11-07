#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

void solve() {
    ll n, tomadas = 0, vida = 0;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq; //min heap
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        vida+=x;
        tomadas++;
        pq.push(x);
        
        while (vida < 0) {
            vida -= pq.top();
            pq.pop();
            tomadas--;
        }    
    }
    cout << tomadas << "\n";
}

int main() {
    
    solve();

    return 0;
}