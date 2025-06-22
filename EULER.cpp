#include <bits/stdc++.h>
using namespace std;

void EULER(int a[100][100], int n, int start) {
    stack<int> s;
    vector<int> CE; // Chu trình Euler

    s.push(start);
    while (!s.empty()) {
        int u = s.top();
        bool found = false;

        for (int v = 1; v <= n; v++) {
            if (a[u][v]) {
                s.push(v);
                a[u][v] = a[v][u] = 0; // Xóa cạnh sau khi đi
                found = true;
                break;
            }
        }

        if (!found) {
            CE.push_back(u); // không còn cạnh đi tiếp -> lưu lại đỉnh
            s.pop();
        }
    }

    // In chu trình Euler
    cout << "Chu trinh Euler: ";
    for (int i = CE.size() - 1; i >= 0; i--)
        cout << CE[i] << " ";
    cout << endl;
}

int main() {
    int a[100][100];
    int n, start;

    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap ma tran ke:\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    cout << "Nhap dinh bat dau: ";
    cin >> start;

    EULER(a, n, start);

    return 0;
}
