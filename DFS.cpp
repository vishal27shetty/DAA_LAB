#include <iostream>
#include <vector>
#include <stack>
#include <chrono>

using namespace std;
using namespace std::chrono;

void dfs(int start, const vector<vector<int>>& adj, vector<bool>& vis) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!vis[node]) {
            vis[node] = true;
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},   // Neighbors of node 0
        {0, 3, 4},// Neighbors of node 1
        {0},      // Neighbors of node 2
        {1},      // Neighbors of node 3
        {1}       // Neighbors of node 4
    };

    vector<bool> vis(adj.size(), false);

    cout << "DFS starting from node 0:" << endl;

    auto start_time = high_resolution_clock::now();
    dfs(0, adj, vis);
    auto end_time = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end_time - start_time);
    cout << "\nTime taken for DFS: " << duration.count() << " microseconds" << endl;

    return 0;
}
