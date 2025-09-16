#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n, t, d;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    cin >> t;
    while (t--) {
        cin >> d;
        cout << upper_bound(arr.begin(), arr.end(), d) - arr.begin() << endl;
    }

}

int main() {
    

    solve();

    return 0;
}