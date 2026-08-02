#include <iostream>
#include <vector>
#include <string>
#include <iostream>
 
using namespace std;
 
void solve() {
    string s;
    cin >> s;
    vector<int> l(26, 0);
    for (auto i : s) {
        l[i-'A']++;
    }
    int impar = s.size() % 2, tem = 0, idx = 0, a = 0;
    if (impar) {
        for (auto v : l) {
            if (v % 2 and tem) {
                cout << "NO SOLUTION\n";
                return;
            } else if (!tem and v % 2) {
                tem++;
                a = idx;
            }
            idx++;
        }
        string ss(s.size(), 0);
        ss[s.size() / 2] = a + 'A';
        l[a]--;
        int ii = 0;
        for (int i = 0; i < (int)s.size()/2; i++) {
            while (l[ii]<2) ii++;
            if (l[ii] >= 2) {
                ss[i] = ii + 'A';
                ss[s.size()-i-1] = ii + 'A';
                l[ii]-=2;
            }
        }
        cout << ss << "\n";
    } else {
        for (auto v : l) {
            if (v % 2) {
                cout << "NO SOLUTION\n";
                return;
            }
        }
        string ss(s.size(), 0);
        int ii = 0;
        for (int i = 0; i < (int)s.size()/2; i++) {
            while (l[ii]<2) ii++;
            if (l[ii] >= 2) {
                ss[i] = ii + 'A';
                ss[s.size()-i - 1] = ii + 'A';
                l[ii]-=2;
            }
        }
        cout << ss << "\n";
    }
    
 
 
}   
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
 
    return 0;
}