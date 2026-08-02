#include <iostream>

using namespace std;
using ll = long long;

int main() {

    ll soma_p = 0, soma, n;

    cin >> n;
    ll tmp[n-1];
    soma = (1 + n) * n / 2;
    for (int i = 0; i < n-1; i++) {
        cin >> tmp[i];
        soma_p += tmp[i];
    }

    cout << soma - soma_p << endl;

    return 0;
}