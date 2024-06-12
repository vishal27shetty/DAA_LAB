#include <iostream>
#include <stack>
using namespace std;

int a[50][50], visited[50];
stack<int> s;

void dfs(int start, int n);

int main() {
    int n, i, j, start;
    cout << "ENTER THE NUMBER OF VERTICES: ";
    cin >> n;
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << "ENTER 1 IF " << i << " HAS A NODE WITH " << j << " ELSE 0: ";
            cin >> a[i][j];
        }
    }
    
    cout << "THE ADJACENCY MATRIX IS\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << " " << a[i][j];
        }
        cout << endl;
    }
    
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    
    cout << "\nD.F.S";
    cout << "\nENTER THE SOURCE VERTEX: ";
    cin >> start;
    dfs(start, n);
    
    return 0;
}

void dfs(int start, int n) {
    s.push(start);
    visited[start] = 1;
    cout << " " << start << " ";
    
    while (!s.empty()) {
        int k = s.top();
        s.pop();

        for (int i = 1; i <= n; i++) {
            if (a[k][i] != 0 && visited[i] == 0) {
                s.push(i);
                visited[i] = 1;
                cout << " " << i << " ";
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            dfs(i, n);
        }
    }
}

