#include <iostream>
#include <vector>

using namespace std;

int a[20][20], q[20], visited[20], n;
int front = -1, rear = -1;

void bfs(int v) {
    for (int i = 0; i < n; i++) { // check all the vertices in the graph
        if (a[v][i] != 0 && visited[i] == 0) { // adjacent to v and not visited
            rear = rear + 1;
            q[rear] = i; // insert them into queue
            visited[i] = 1; // mark the vertex visited
            cout << i << " ";
        }
    }
    front = front + 1; // remove the vertex at front of the queue
    if (front <= rear) { // as long as there are elements in the queue
        bfs(q[front]); // perform bfs again on the vertex at front of the queue
    }
}

int main() {
    int v, i, j;
    cout << "\n Enter the number of vertices: ";
    cin >> n;
    for (i = 0; i < n; i++) { // mark all the vertices as not visited
        visited[i] = 0;
    }
    cout << "\n Enter graph data in matrix form:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << "\n Enter the starting vertex: ";
    cin >> v;
    front = rear = 0;
    q[rear] = v;
    cout << "\n BFS traversal is:\n";
    visited[v] = 1; // mark the starting vertex as visited
    cout << v << " ";
    bfs(v);

    bool allVisited = true;
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            allVisited = false;
            break;
        }
    }

    if (!allVisited) {
        cout << "\n BFS is not possible for all nodes.";
    }

    return 0;
}