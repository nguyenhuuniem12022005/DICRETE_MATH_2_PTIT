#include <bits/stdc++.h> // Thư viện tổng hợp cần thiết
using namespace std;

// Biến toàn cục
int n;                          // Số đỉnh
int a[101][101];                // Ma trận trọng số a[i][j]: từ i -> j
int d[101];                     // d[i]: khoảng cách ngắn nhất từ u đến i
int pr[101];                    // pr[i]: đỉnh liền trước của i trong đường đi
vector<int> visited(n + 1, 0);           // visited[i]: đánh dấu đỉnh i đã xét xong chưa

// Thuật toán Dijkstra tìm đường đi ngắn nhất từ đỉnh u
void Dijsktra(int u) {

    // Khởi tạo khoảng cách ban đầu
    for(int i = 1; i <= n; i++) {
        d[i] = a[u][i];       // d[i]: chi phí trực tiếp từ u đến i
        pr[i] = u;            // Đỉnh trước của i là u
        visited[i] = 0;       // Chưa xét đỉnh i
    }

    d[u] = 0;                 // Khoảng cách từ u đến u = 0
    pr[u] = 0;                // Không có đỉnh trước của u
    visited[u] = 1;           // Đã xét u

    // Lặp cho đến khi không còn đỉnh nào để chọn
    while(1) {
        int cur = 0;
        int mind = 10001;     // Giá trị lớn ban đầu để tìm min
        
        // Tìm đỉnh chưa xét có khoảng cách nhỏ nhất
        for(int i = 1; i <= n; i++) {
            if(visited[i] == 0 && d[i] < mind) {
                cur = i;
                mind = d[i];
            }
        }

        if(cur == 0) return; // Không còn đỉnh nào để cập nhật

        visited[cur] = 1; // Đánh dấu đã xét cur

        // Cập nhật khoảng cách của các đỉnh kề cur
        for(int i = 1; i <= n; i++) {
            if(visited[i] == 0 && d[i] > d[cur] + a[cur][i]) {
                d[i] = d[cur] + a[cur][i]; // Cập nhật đường đi ngắn hơn
                pr[i] = cur;               // Ghi nhớ đỉnh trước
            }
        }
    }
}

int main() {
    cin >> n; // Nhập số lượng đỉnh

    // Nhập ma trận trọng số a[i][j]: từ i -> j
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int u; 
    cin >> u; // Nhập đỉnh bắt đầu

    Dijsktra(u); // Gọi hàm Dijkstra

    // In khoảng cách từ u đến các đỉnh khác
    for(int i = 1; i <= n; i++) {
        cout << d[i] << ' ';
    }
    cout << endl;

    return 0;
}

