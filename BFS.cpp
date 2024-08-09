#include <chrono>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void BFS(const vector<vector<int>> &adjList, int startNode,
         vector<bool> &visited) {
  queue<int> q;
  visited[startNode] = true;
  q.push(startNode);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    cout << node << " ";

    for (int neighbor : adjList[node]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

int main() {
  vector<vector<int>> adjList = {
      {1, 2},    
      {0, 3, 4}, 
      {0, 4},    
      {1, 5},    
      {1, 2, 5}, 
      {3, 4}     
  };

  int startNode = 0;
  vector<bool> visited(adjList.size(), false);

  auto start = chrono::high_resolution_clock::now();
  cout << "BFS: ";
  BFS(adjList, startNode, visited);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> elapsedTime = end - start;
  cout << "\nTime taken: " << elapsedTime.count() << " seconds\n";

  return 0;
}
