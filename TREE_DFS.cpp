#include <bits/stdc++.h>

using namespace std;

int n, a[101][101];
vector<bool> visited(n + 1, false);
vector<pair<int, int>> tree;

void T_DFS(int u) {
    visited[u] = true;
    if (tree.size() == (n - 1)) {
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(a[u][i] == 1 && !visited[i]) {
            pair<int, int> tmp(u, i);
            tree.push_back(tmp);
            T_DFS(i);
        }
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int u; cin >> u;
    T_DFS(u);

    for(pair<int, int> x : tree) {
        cout << '(' << x.first << ", " << x.second << ") ";
    }
    cout << endl;
    
    for(int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    tree.clear();

    T_BFS(u);

    for(pair<int, int> x : tree) {
        cout << '(' << x.first << ", " << x.second << ") ";
    }
    cout << endl;
    return 0;
}
