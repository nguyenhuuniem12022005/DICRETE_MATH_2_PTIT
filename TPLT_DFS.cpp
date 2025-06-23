#include <bits/stdc++.h>
using namespace std;

bool visited[100];
int n;

void DFS(int u, int a[100][100]) {
    visited[u] = true;
    for(int i = 1; i <= n; i++) {
        if(a[u][i] == 1 && !visited[i]) {
            DFS(i, a); // truyền mảng a tiếp tục
        }
    }
}

int ConCom_DFS(int a[100][100]) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cnt += 1;
            DFS(i, a); // truyền mảng a vào DFS
        }
    }
    return cnt;
}

int main() {
    int a[100][100];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    memset(visited, false, sizeof(visited));
    int components = ConCom_DFS(a);
    cout << "Number of connected components: " << components << endl;

    return 0;
}
