    #include <bits/stdc++.h>

    using namespace std;

    void solve() {
        int n;
        cin >> n;

        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }

        
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        int ans = 0;
        vector<int> dp(n+1, 0), p(n, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i - 1; j >= 0; j--) {
                if (v[j].second <= v[i].first) {
                    p[i] = j;
                    break;
                }
            }
        }


        for (int i = 1; i <= n; i++) {
            dp[i] = v[i-1].second - v[i-1].first;

            if (p[i-1] != -1) {
                dp[i] = max(dp[i-1], dp[p[i-1]+1] + v[i-1].second - v[i-1].first);
            } else {
                dp[i] = max(dp[i-1], dp[i]);
            }

        }

        cout << dp[n] << "\n";
    }


    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int t = 1;
        // std::cin >> t;

        while (t--) {
            solve();
        }

        return 0;
    }