#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int a[100][100], n;
bool visited[100];
int d[100], parent[100];

void PRIM(int a[100][100]) {
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    d[1] = 0; // bắt đầu từ đỉnh 1

    for (int count = 1; count <= n - 1; count++) {
        int u = -1, minD = INF;

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && d[i] < minD) {
                minD = d[i];
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (a[u][v] && !visited[v] && a[u][v] < d[v]) {
                d[v] = a[u][v];
                parent[v] = u;
            }
        }
    }

    // In cây khung nhỏ nhất
    cout << "Cay khung nho nhat:\n";
    int tong = 0;
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << " - " << i << " : " << a[i][parent[i]] << endl;
        tong += a[i][parent[i]];
    }
    cout << "Tong trong so = " << tong << endl;
}
int main() {
    cout << "Nhap so dinh: ";
    cin >> n;

    cout << "Nhap ma tran trong so (neu khong co canh nhap 0):\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    // Gọi một trong hai hàm bên dưới:
    PRIM(a);
    // HAMILTON(a);

    return 0;
}
