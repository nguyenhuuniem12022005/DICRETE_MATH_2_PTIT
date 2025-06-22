#include <bits/stdc++.h>
using namespace std;


bool visited[100];
int n;
int TPLT_bfs(int a[100][100]) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int j = 1; j <= n; j++) {
                    if (a[v][j] == 1 && !visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
    return count;
}
int main() {
    cin >> n;
    int a[100][100];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    int components = TPLT_bfs(a);
    cout << "Number of connected components: " << components << endl;
    return 0;
}