#include <bits/stdc++.h>
using namespace std;

int a[100][100];
bool visited[100];
int n;
void DFS_stack(int u) {
    stack<int> st;
    st.push(u);
    visited[u] = true;
    cout << u << " ";
    while(!st.empty()) {
        int x = st.top(); st.pop();
        for(int i = 1; i <= n; i++) {
            if(a[x][i] == 1 && !visited[i]) {
                cout << i << " ";
                st.push(x);
                st.push(i);
                visited[i] = true;
                break;
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
    DFS_stack(u);
    return 0;
}
