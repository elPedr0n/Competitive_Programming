#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, M1 = 0, A1 = 0;
    cin >> n;
    vector<int> A(n), M(n);

    for (int i = 0; i < n; i++) {cin >> A[i]; if (A[i]) A1++;}
    for (int i = 0; i < n; i++) {cin >> M[i]; if (M[i]) M1++;}

    // cout << "a1=" << A1 << "m1=" << M1 << endl;

    for (int i = 0; i < n; i++) {
        // cout << i << endl;
        if (i % 2 == 0) {
            // cout << "ai=" << A[i] << "mi=" << M[i] << endl;
            if (A1 % 2 == 0 && M[i] != A[i]) {
                int tmp = M[i];
                M[i] = A[i];
                A[i] = tmp;

                if (tmp) {M1--;A1++;}
                else {M1++;A1--;}
                // cout << "Entremo em i=" << i << "tmp=" << tmp << endl;
            }
        } else {
            if (M1 % 2 == 0 and M[i] != A[i]) {
                int tmp = M[i];
                M[i] = A[i];
                A[i] = tmp;

                if (tmp) {M1--;A1++;}
                else {M1++;A1--;}
            }
        }
    }

    if (M1 % 2 == A1 % 2) cout << "Tie\n";
    else if (M1 % 2 == 1) cout << "Mai\n";
    else cout << "Ajisai\n";


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}