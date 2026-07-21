#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;
typedef long long ll;

void solve() {

    int n;
    cin >> n;

    vector<vector<int>> a(n+1, vector<int>(0, 0));

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == -1) continue;
        a[x].push_back(i);
    }

    // Fazer um bfs pra cada um dos vertices
    int maxd = -1;

    for (int i = 1; i <= n; i++) {
        vector<bool> vis(n+1, false);
        vis[i] = true;
        queue<pair<int, int>> q;
        q.push({i, 1});

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            if (curr.second > maxd) maxd = curr.second;

            for (auto b: a[curr.first]) {
                if (!vis[b]) {
                    vis[b] = true;
                    q.push({b, curr.second+1});
                }
            }
        }
    }

    cout << maxd << endl;
}

int main() {

    solve();

    return 0;

}