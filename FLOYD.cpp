#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int a[100][100], d[100][100], n;

void FLOYD(int a[100][100]) {
    // Khởi tạo d từ ma trận trọng số a
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = a[i][j];

    // Floyd-Warshall
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    // In kết quả
    cout << "Ma tran d[i][j] la duong di ngan nhat giua moi cap dinh:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) cout << "INF ";
            else cout << d[i][j] << " ";
        }
        cout << endl;
    }
}
