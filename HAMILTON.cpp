#include <bits/stdc++.h>
using namespace std;

// Biến toàn cục
int n;                        // Số đỉnh
int a[101][101];              // Ma trận kề của đồ thị
int u;                        // Đỉnh bắt đầu
vector<bool> visited(101, false); // Mảng đánh dấu đỉnh đã đi
int X[101];                   // Mảng lưu đường đi Hamilton hiện tại

// Hàm đệ quy tìm chu trình Hamilton từ vị trí k
void Hamilton(int k) {
    int x = X[k - 1];         // Đỉnh trước đó trong đường đi

    for(int i = 1; i <= n; i++) {
        if(a[x][i] == 1) {    // Nếu có cạnh nối từ x đến i
            if(k == n + 1 && i == u) { // Nếu đã đi qua n đỉnh và quay lại đỉnh ban đầu
                // In ra một chu trình Hamilton
                for(int i = 1; i <= n; i++) {
                    cout << X[i] << ' ';
                }
                cout << i << endl; // i chính là đỉnh u
            } 
            else if(!visited[i]) { // Nếu đỉnh i chưa được đi
                X[k] = i;           // Gán đỉnh i vào vị trí k
                visited[i] = true;  // Đánh dấu đã đi
                Hamilton(k + 1);    // Đệ quy tới bước tiếp theo
                visited[i] = false; // Quay lui: bỏ đánh dấu
            }
        }
    }
}
int main() {
    cin >> n; // Nhập số đỉnh

    // Nhập ma trận kề
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    cin >> u;      // Nhập đỉnh xuất phát
    X[1] = u;      // Đỉnh đầu tiên của đường đi là u
    visited[u] = true; // Đánh dấu đã thăm u

    Hamilton(2);   // Bắt đầu tìm từ vị trí thứ 2 trong chu trình

    return 0;
}
