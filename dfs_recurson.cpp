#include <bits/stdc++.h>
using namespace std;

int a[100][100];
bool visited[100];
int n;
void dfs(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int i = 1; i <= n; i++)
    {
        if (a[u][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    int u;
    cin >> u;
    dfs(u);
    return 0;
}