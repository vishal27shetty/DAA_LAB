#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> a(20, vector<int>(20));
vector<int> visited(20, 0);
int n;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = 1;
    
    cout << v << " ";

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (a[front][i] != 0 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
                cout << i << " ";
            }
        }
    }
}

int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter graph data in matrix form:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter the starting vertex: ";
    cin >> v;

    cout << "BFS traversal is:\n";
    bfs(v);

    bool allVisited = true;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            allVisited = false;
            break;
        }
    }

    if (!allVisited) {
        cout << "\nBFS is not possible for all nodes.";
    }

    return 0;
}


