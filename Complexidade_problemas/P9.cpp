#include <bits/stdc++.h>
#define MAXN ((int) 1e4)
#define MAXM ((int) 2e4)
#define INF ((long long) 1e18)
using namespace std;
typedef pair<int, int> pii;

int n, m, K;
pii A[MAXN + 10];
long long ans;

long long f[MAXM + 10], g[MAXN + 10];

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i].first, &A[i].second);
    sort(A + 1, A + n + 1);

    long long sm = 0;
    g[n + 1] = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = n; i > 0; i--) {
        pq.push(A[i].second);
        sm += A[i].second;
        if (pq.size() > K) {
            sm -= pq.top();
            pq.pop();
        }
        g[i] = sm;
    }

    for (int i = 0; i <= m; i++) f[i] = -INF;
    f[0] = 0;
    ans = g[1];
    for (int i = 1; i <= n; i++) for (int j = m; j >= A[i].first; j--) {
        f[j] = max(f[j], f[j - A[i].first] + A[i].second);

        ans = max(ans, f[j] + g[i + 1]);
    }
    printf("%lld\n", ans);
    return 0;
}