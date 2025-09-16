#include <bits/stdc++.h>


using namespace std;


int main() {

    int t, n, k;

    cin >> t;

    for (int p = 0; p < t; p++) {
        cin >> n >> k;

        int arr[n] = {0}, out = 0, ind;
        for (int i = 0; i < n; i++) cin >> arr[i];

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int aux = fabs(arr[i] - arr[j]);
                if (aux % k != 0) {
                    out = 1;
                    ind = i;
                    break;
                }
            }
        }

        if (out) cout << "YES\n" << ind + 1 << endl;
        else cout << "NO" << endl;


    }

    return 0;
}
