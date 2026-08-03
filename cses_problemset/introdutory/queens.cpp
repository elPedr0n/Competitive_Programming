#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define N 8

vector<string> board;
vector<bool> col(N, false);
vector<bool> diag1(2 * N, false), diag2(2 * N, false);
ll out = 0;

void solve(int y) {

    if (y == N) {
        out++;
        return;
    } else {
        for (int i = 0; i < N; i++) {
            int id1 = i + y;
            int id2 = i - y + (N-1);

            if (board[y][i] == '*' or col[i] or diag1[id1] or diag2[id2]) continue;
            col[i] = true;
            diag1[id1] = true;
            diag2[id2] = true;

            solve(y+1);

            col[i] = false;
            diag1[id1] = false;
            diag2[id2] = false;

        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        board.push_back(s);
    } 

    solve(0);

    cout << out << '\n';

}