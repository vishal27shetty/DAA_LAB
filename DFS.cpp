#include <chrono>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void DFS(const vector<vector<int>> &adjList, int startNode, vector<bool> &visited) {
    stack<int> s;
    s.push(startNode);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> adjList = {
        {1, 2},    // Node 0 is connected to Node 1 and Node 2
        {0, 3, 4}, // Node 1 is connected to Node 0, Node 3, and Node 4
        {0},       // Node 2 is connected to Node 0
        {1},       // Node 3 is connected to Node 1
        {1}        // Node 4 is connected to Node 1
    };

    int startNode = 0;
    vector<bool> visited(adjList.size(), false);

    auto start = chrono::high_resolution_clock::now();
    cout << "DFS: ";
    DFS(adjList, startNode, visited);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsedTime = end - start;
    cout << "\nTime taken: " << elapsedTime.count() << " seconds\n";

    return 0;
}
