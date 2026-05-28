#include <bits/stdc++.h>

using namespace std;

void solve() {

    string s;
    cin >> s;

    stack<char> st;

    int out = 0;
    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '.') continue;
        if (s[i] == '>') {
            if (!st.empty()) {
                st.pop();
                out++;
            }
        } else {
            st.push(s[i]);
        }

    }

    cout << out << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }
}