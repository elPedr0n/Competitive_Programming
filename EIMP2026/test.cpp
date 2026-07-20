#include <iostream>
#include <vector>
#define N 5
using namespace std;

int main() {
     
    vector<vector<int>> adj(N, vector<int>(0, 0));

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);

    for (auto a : adj) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}