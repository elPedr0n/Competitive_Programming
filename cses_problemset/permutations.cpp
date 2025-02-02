#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n, arr[1000000] = {0};   
    cin >> n;

    if (n <= 3 && n != 1) cout << "NO SOLUTION" << endl;
    else if (n == 4) cout << "2 4 1 3\n";
    else {
        ll c = 1;
        for (int i = 0; i < n; i+=2) {
            arr[i] = c;
            c++;
        }

        for (int i = 1; i < n; i+=2) {
            arr[i] = c;
            c++;
        }

        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    


    return 0;
}