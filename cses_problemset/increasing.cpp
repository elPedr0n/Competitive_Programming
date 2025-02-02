#include <iostream>

using namespace std;
using ll = long long;

int main() {

    ll n, arr[200000], movs = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i > 0) {
            if (arr[i] < arr[i-1]) {
                movs += arr[i-1] - arr[i];
                arr[i] = arr[i-1];
            }
        }
    }

    cout << movs << endl;

    return 0;
}