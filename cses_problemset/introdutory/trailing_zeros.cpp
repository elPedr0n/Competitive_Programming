#include <iostream>
#include <vector>
 
using namespace std;
typedef long long ll;
 
ll p[] = {(5), (25), (125), (625), (3125), (15625), (78125), (390625), (1953125), (9765625), (48828125), (244140625)};
 
void solve() {
    
    ll n;
    cin >> n;
    
    ll out = 0, c = 11;
    
    for (int i = 11; i >= 0; i--) {
        out += (n / p[i]);
        //n = n % p[i];
        c--;
    }   
    
    cout << out << endl;
 
}
 
 
int main()
{
    solve();
    
    return 0;
}