#include <bits/stdc++.h>

#define MAXN (int)1e7 + 5

using namespace std;
using ll = long long;

vector<ll> A(MAXN, 0), dp(MAXN, 0);

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cin >> A[a];
    }

    if (A[0] > 0) dp[0]= 1;
    ll mx = 0;

    for (int i = 1; i < MAXN; i++) {
        if (!A[i]) dp[i] = dp[i - 1];
        else {
            if (A[i] >= i) dp[i] = 1;
            else dp[i] = dp[i - A[i] - 1] + 1;
        }

        if (mx < dp[i]) mx = dp[i];
    }

    cout << n - mx << "\n";

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}