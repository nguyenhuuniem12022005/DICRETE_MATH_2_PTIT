#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int a[100][100], d[100], n;
bool visited[100];

void DIJKSTRA(int u) {
    for (int i = 1; i <= n; i++) {
        d[i] = a[u][i];         // Khoảng cách ban đầu từ u đến i
        visited[i] = false;
    }
    d[u] = 0;
    visited[u] = true;

    for (int k = 1; k < n; k++) {
        int minDist = INF, v = -1;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && d[i] < minDist) {
                minDist = d[i];
                v = i;
            }
        }
        if (v == -1) break; // Không còn đỉnh nào để duyệt

        visited[v] = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && a[v][i] < INF && d[v] + a[v][i] < d[i]) {
                d[i] = d[v] + a[v][i];
            }
        }
    }

    // In kết quả
    cout << "Khoang cach ngan nhat tu dinh " << u << ":\n";
    for (int i = 1; i <= n; i++) {
        cout << "d[" << i << "] = " << d[i] << endl;
    }
}
