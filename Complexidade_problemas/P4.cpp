#include <iostream>
#include <vector>
#include <numeric>
 
using namespace std;
#define MAX 10000
 
 
void solve() {
 
    int n, total, rep;
    bool tem_rep = false;
    
    cin >> n;
    total = n;
    
    vector<int> v(MAX,0);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x-1]++;
        if (v[x-1] >= 2) {
            if (tem_rep) {
                v[rep]--;
                v[x-1]--;
                tem_rep = false;
            } else {
                tem_rep = true;
                rep = x-1;
            }
        } 
    }
    
    /*for (int i = 0; i < MAX; i++) {
        if (v[i]) cout << i << ':' << v[i] << endl;
    }*/
    total = accumulate(v.begin(), v.end(), 0);
    if (tem_rep) total-=2;
    
    cout << total << endl;
    
    
    
}
 
 
int main()
{
    int t;
    cin >> t;
    while (t--) 
        solve();
    
    return 0;
}