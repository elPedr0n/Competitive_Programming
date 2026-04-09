#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    long long int n, s, s2;
    cin >> n;
    s = (1+n)*n/2;
    if (s%2) cout << "NO" << endl;
    else {
        s2 = s/2;
        vector<long long int> v;
        vector<bool> b(n+1, true);
        long long int i, pi = n;
        while (s2 > 0) {
            // cout << "ta aq dentro\n";
            i = pi;
            while (!b[i] || s2-i < 0) i--;
            s2 -= i;
            v.push_back(i);
            b[i] = false;
            pi = i;
        } 
        cout << "YES\n" << v.size() << endl;
        for (auto i: v) cout << i << ' ';
        cout << endl << n-v.size() << endl;
        for (int i = n; i >= 1; i--) if (b[i]) cout << i << ' ';
        cout << endl;
    }
}
 
int main() {
    
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
 
    return 0;
}