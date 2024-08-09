#include <chrono>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void topologicalSortDFS(int node, const vector<vector<int>> &adjList, vector<bool> &visited, stack<int> &topoStack) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            topologicalSortDFS(neighbor, adjList, visited, topoStack);
        }
    }

    // After visiting all neighbors, push the current node onto the stack
    topoStack.push(node);
}

void topologicalSort(const vector<vector<int>> &adjList) {
    int numNodes = adjList.size();
    vector<bool> visited(numNodes, false);
    stack<int> topoStack;

    // Perform DFS from each node
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            topologicalSortDFS(i, adjList, visited, topoStack);
        }
    }

    // Print the topological sort by popping from the stack
    cout << "Topological Sort: ";
    while (!topoStack.empty()) {
        cout << topoStack.top() << " ";
        topoStack.pop();
    }
    cout << endl;
}

int main() {
    vector<vector<int>> adjList = {
        {1, 2},  // Node 0 is connected to Node 1 and Node 2
        {3},     // Node 1 is connected to Node 3
        {3},     // Node 2 is connected to Node 3
        {}       // Node 3 has no outgoing edges
    };

    auto start = chrono::high_resolution_clock::now();
    topologicalSort(adjList);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsedTime = end - start;
    cout << "Time taken: " << elapsedTime.count() << " seconds" << endl;

    return 0;
}
