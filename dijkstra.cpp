#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> P; // (weight, vertex)

void dijkstra(vector<vector<P>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1); // To store the parent of each vertex in the shortest path tree
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : graph[u]) {
            int v = edge.second;
            int wt = edge.first;
            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
                parent[v] = u; // Store the parent of v
            }
        }
    }

    // Display the shortest path tree (similar to MST)
    for (int i = 0; i < n; ++i) {
        if (i != start && parent[i] != -1) {
            cout << "Edge: " << parent[i] << " - " << i << " - Cost: " << dist[i] - dist[parent[i]] << endl;
        }
    }
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<P>> graph(n);

    graph[0].push_back({10, 1});
    graph[0].push_back({5, 3});
    graph[1].push_back({1, 2});
    graph[1].push_back({2, 3});
    graph[2].push_back({4, 4});
    graph[3].push_back({2, 1});
    graph[3].push_back({9, 2});
    graph[3].push_back({2, 4});
    graph[4].push_back({6, 0});
    graph[4].push_back({7, 2});

    dijkstra(graph, 0);

    return 0;
}
