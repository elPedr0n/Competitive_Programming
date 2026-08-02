#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    long long int n;
    cin >> n;
    for (long long int i = 1; i <= n; i++) {
        cout << (i*i*(i*i-1)/2) - 4 * (i - 1) * (i - 2) << endl;
    }
}   
 
int main() {
    
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
 
    return 0;
}