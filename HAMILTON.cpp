#include <bits/stdc++.h>
using namespace std;

int a[100][100], n;
bool visited[100];
int path[100];

void printPath(int k) {
    for (int i = 0; i < k; i++) {
        cout << path[i] << " -> ";
    }
    cout << path[0] << endl; // quay về đỉnh xuất phát để thành chu trình
}

void HAMILTON_UTIL(int k) {
    for (int v = 2; v <= n; v++) {
        if (!visited[v] && a[path[k-1]][v]) {
            path[k] = v;
            visited[v] = true;

            if (k == n - 1 && a[v][path[0]]) {
                printPath(k + 1);
            } else {
                HAMILTON_UTIL(k + 1);
            }

            visited[v] = false;
        }
    }
}

void HAMILTON(int a[100][100]) {
    memset(visited, false, sizeof(visited));
    path[0] = 1;  // bắt đầu từ đỉnh 1
    visited[1] = true;
    cout << "Cac chu trinh Hamilton:\n";
    HAMILTON_UTIL(1);
}
int main() {
    cout << "Nhap so dinh: ";
    cin >> n;

    cout << "Nhap ma tran trong so (neu khong co canh nhap 0):\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    // Gọi một trong hai hàm bên dưới:
     HAMILTON(a);

    return 0;
}
