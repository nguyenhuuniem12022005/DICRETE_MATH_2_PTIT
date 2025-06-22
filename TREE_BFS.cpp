#include <bits/stdc++.h>
using namespace std;

void T_BFS(int a[][100], int n, int start) {
    bool visited[100] = {false};
    int T[100]; // T[v] = u => u là cha của v trong cây khung
    queue<int> q;

    q.push(start);
    visited[start] = true;
    T[start] = -1; // Gốc cây không có cha

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v = 1; v <= n; v++) {
            if (a[u][v] == 1 && !visited[v]) {
                q.push(v);
                visited[v] = true;
                T[v] = u;
            }
        }
    }

    // In cây khung BFS
    cout << "Cay khung BFS (dinh - cha):\n";
    for (int i = 1; i <= n; i++) {
        if (T[i] != -1)
            cout << i << " - " << T[i] << '\n';
    }
}

int main() {
    int a[100][100];
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (0 or 1):\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    int startVertex;
    cout << "Enter starting vertex for BFS Tree: ";
    cin >> startVertex;

    T_BFS(a, n, startVertex);

    return 0;
}
