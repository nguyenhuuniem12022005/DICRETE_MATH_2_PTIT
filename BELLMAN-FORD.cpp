#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int a[100][100]; // Ma trận trọng số
int d[100], n;

void BELLMAN_FORD(int u) {
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    d[u] = 0;

    // Lặp (n - 1) lần
    for (int k = 1; k <= n - 1; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] != INF && d[i] != INF && d[i] + a[i][j] < d[j]) {
                    d[j] = d[i] + a[i][j];
                }
            }
        }
    }

    // Kiểm tra chu trình âm
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != INF && d[i] != INF && d[i] + a[i][j] < d[j]) {
                cout << "Do thi co chu trinh am.\n";
                return;
            }
        }
    }

    // In kết quả
    cout << "Khoang cach ngan nhat tu dinh " << u << ":\n";
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) cout << "d[" << i << "] = INF\n";
        else cout << "d[" << i << "] = " << d[i] << endl;
    }
}
int main() {
    cout << "Nhap so dinh: ";
    cin >> n;

    cout << "Nhap ma tran trong so (neu khong co canh nhap INF):\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            string val;
            cin >> val;
            if (val == "INF") a[i][j] = INF;
            else a[i][j] = stoi(val);
        }

    int start;
    cout << "Nhap dinh bat dau: ";
    cin >> start;

    BELLMAN_FORD(start);

    return 0;
}
