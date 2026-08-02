#include <iostream>

using namespace std;
using ll = long long;

 
int main() {
    
    ll n;
    cin >> n;

    cout << n;

    while (n != 1) {
        if (n % 2 == 1) n = n * 3 + 1;
        else  n /= 2;
        cout << " " << n;
    }

    cout << endl;

    return 0;
}