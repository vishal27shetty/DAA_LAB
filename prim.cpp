#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    tuple<int, vector<pair<int, int>>, vector<int>> spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        vector<int> vis(V, 0);
        // {wt, node, parent}
        pq.push({0, 0, -1});
        int sum = 0;
        vector<pair<int, int>> mst_edges;
        vector<int> mst_weights;

        while (!pq.empty()) {
            auto [wt, node, parent] = pq.top();
            pq.pop();

            if (vis[node] == 1) continue;
            // add it to the mst
            vis[node] = 1;
            sum += wt;

            // Include the edge in the MST edges list
            if (parent != -1) {
                mst_edges.push_back({parent, node});
                mst_weights.push_back(wt);
            }

            for (auto &it : adj[node]) {
                int adjNode = it[0];
                int edW = it[1];
                if (!vis[adjNode]) {
                    pq.push({edW, adjNode, node});
                }
            }
        }
        return {sum, mst_edges, mst_weights};
    }
};

int main() {

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto &it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    auto [sum, mst_edges, mst_weights] = obj.spanningTree(V, adj);

    cout << "The sum of all the edge weights: " << sum << endl;
    cout << "The edges in the minimum spanning tree are:" << endl;
    for (size_t i = 0; i < mst_edges.size(); ++i) {
        cout << mst_edges[i].first << " - " << mst_edges[i].second << " : " << mst_weights[i] << endl;
    }

    return 0;
}
