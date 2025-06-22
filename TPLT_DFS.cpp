#include <bits/stdc++.h>
using namespace std;

bool visited[100];
int n;
int TPLT_dfs(int a[100][100])
{
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            stack<int> s;
            s.push(i);
            visited[i] = true;
            while (!s.empty()) {
                int v = s.top();
                s.pop();
                for (int j = 1; j <= n; j++) {
                    if (a[v][j] == 1 && !visited[j]) {
                        visited[j] = true;
                        s.push(j);
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
    int components = TPLT_dfs(a);
    cout << "Number of connected components: " << components << endl;
    return 0;
}