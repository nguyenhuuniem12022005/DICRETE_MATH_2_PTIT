#include <bits/stdc++.h>
using namespace std;

// Biến toàn cục
int n;                            // Số đỉnh
int a[101][101];                  // Ma trận trọng số đầu vào
int d[101][101];                  // Ma trận d[i][j]: khoảng cách ngắn nhất từ i đến j
int pr[101][101];                 // Ma trận truy vết đường đi: pr[i][j] là đỉnh trước j trên đường đi từ i → j
vector<int> visited(n + 1, 0);    // Không cần dùng trong Floyd, có thể bỏ
int Floyd() {
    // Khởi tạo ma trận khoảng cách và truy vết ban đầu
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            d[i][j] = a[i][j];      // Dùng trọng số ban đầu
            pr[i][j] = i;           // Truy vết: trước j là i
        }
    }

    // Ba vòng lặp chính của Floyd-Warshall
    for(int k = 1; k <= n; k++) {         // Duyệt từng đỉnh trung gian
        for(int i = 1; i <= n; i++) {     // Duyệt đỉnh bắt đầu
            for(int j = 1; j <= n; j++) { // Duyệt đỉnh kết thúc
                // Nếu đường đi qua đỉnh trung gian k ngắn hơn đường hiện tại
                if(d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];   // Cập nhật khoảng cách mới
                    pr[i][j] = pr[k][j];           // Cập nhật truy vết
                }
            }
        }
    }

    // Kiểm tra có chu trình âm không (nếu d[i][i] < 0 thì có)
    for(int i = 1; i <= n; i++) {
        if(d[i][i] < 0) {
            return 0; // Có chu trình âm
        }
    }
    return 1; // Không có chu trình âm
}
int main() {
    cin >> n; // Nhập số đỉnh

    // Nhập ma trận trọng số
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int u;
    cin >> u; // Đọc thêm một biến u (chưa dùng trong Floyd, có thể bỏ nếu không cần)

    if(!Floyd()) {
        cout << "Co chu trinh am" << endl; // Nếu có chu trình âm
    }
    else {
        // In ra ma trận d và pr
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << d[i][j] << '|' << pr[i][j] << ' ';
            }
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}
