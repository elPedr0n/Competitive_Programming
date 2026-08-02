#include <bits/stdc++.h>
 
using namespace std;
 
void solve(int n, int from, int to, int aux) {
 
    if (!n) return;
    
    solve(n-1, from, aux, to);
    cout << from << ' ' << to << endl;
    solve(n-1, aux, to, from);
 
    
}
 
int main()
{ 
    int n;
    cin >> n;
    
    cout << pow(2, n) -1 << endl;
    solve(n, 1, 3, 2);
    
}