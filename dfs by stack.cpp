#include <bits/stdc++.h>
using namespace std;

int a[100][100];
bool visited[100];
int n;
void dfs_stack(int u)
{
    stack<int>s;
    s.push(u);
    visited[u]=true;
    while(!s.empty())
    {
        int v=s.top();
        s.pop();
        cout<<v<<' ';
        for (int i=1;i<= n;i++)
        {
            if (a[v][i]==1 && !visited[i])
            {
                s.push(i);
                visited[i]=true;
            }
        }
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    int u;
    cin>>u;
    dfs_stack(u);
    return 0;
}