#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> rob(n), spike(m);

    for (int i = 0; i < n; i++) {
        cin >> rob[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> spike[i];
    }

    sort(spike.begin(), spike.end());

    string inst;
    cin >> inst;

    for (int i = 0; i < k; i++) {
        
        if (inst[i] == 'R') {
            for (int j = 0; j < rob.size(); j++) {
                
                if (binary_search(spike.begin(), spike.end(), rob[j]+1)) {
                    rob.erase(find(rob.begin(), rob.end(), rob[j]));
                    j--;
                } else {
                    rob[j]++;
                }
            }
        } else {
            for (int j = 0; j < rob.size(); j++) {
                
                if (binary_search(spike.begin(), spike.end(), rob[j]-1)) {
                    rob.erase(find(rob.begin(), rob.end(), rob[j]));
                    j--;
                } else {
                    rob[j]--;
                }
            }
        }

        cout << rob.size() << ' ';
    }
    cout << endl;
    // cout << "cabou aq um teste" << endl;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}


