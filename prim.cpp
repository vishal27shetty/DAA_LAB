#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> P; // (weight, vertex)

void prim(vector<vector<P>>& graph, int start) {
    int n = graph.size();
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);  // To store the parent of each vertex in the MST
    priority_queue<P, vector<P>, greater<P>> pq;

    key[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.second;
            int wt = edge.first;
            if (!inMST[v] && key[v] > wt) {
                key[v] = wt;
                pq.push({wt, v});
                parent[v] = u; // Store the parent of v
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i != start) {
            cout << "Edge: " << parent[i] << " - " << i << " - Cost: " << key[i] << endl;
        }
    }
}

int main() {
    int n = 6; // Number of vertices
    vector<vector<P>> graph(n);

     graph[0].push_back({6, 3}); // A-D
    graph[0].push_back({5, 1}); // A-B
    graph[0].push_back({4, 4}); // A-E
    graph[0].push_back({2, 2}); // A-C

    graph[1].push_back({5, 0}); // B-A
    graph[1].push_back({2, 2}); // B-C

    graph[2].push_back({2, 1}); // C-B
    graph[2].push_back({3, 4}); // C-E
    graph[2].push_back({2, 0}); // C-A

    graph[3].push_back({6, 0}); // D-A
    graph[3].push_back({7, 5}); // D-F
    graph[3].push_back({3, 4}); // D-E

    graph[4].push_back({4, 0}); // E-A
    graph[4].push_back({3, 3}); // E-D
    graph[4].push_back({8, 5}); // E-F
    graph[4].push_back({3, 2}); // E-C

    graph[5].push_back({7, 3}); // F-D
    graph[5].push_back({8, 4}); // F-E

    // Start from vertex F, which is vertex 5 in 0-indexed array
    prim(graph, 5);

    return 0;
}

