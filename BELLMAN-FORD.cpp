#include <bits/stdc++.h>

using namespace std;

// Biến toàn cục
int n;                      // Số đỉnh của đồ thị
int a[101][101];            // Ma trận trọng số (a[i][j] là trọng số từ đỉnh j sang đỉnh i)
int d[101];                 // Mảng lưu khoảng cách ngắn nhất từ u đến i
int pr[101];                // Mảng lưu đỉnh trước của i trên đường đi ngắn nhất
vector<int> visited(n + 1, 0); // Dự kiến để dùng trong tương lai (ở đây không sử dụng)


// Hàm thực hiện thuật toán Bellman-Ford từ đỉnh `u`
int Bellman_Ford(int u) {
    // Khởi tạo: khoảng cách từ u đến các đỉnh khác là trọng số trực tiếp từ a[u][i]
    for(int i = 1; i <= n; i++) {
        d[i] = a[u][i];
        pr[i] = u; // gán đỉnh trước là u
    }
    d[u] = 0;      // Khoảng cách từ u đến u là 0
    pr[u] = 0;     // Không có đỉnh trước với u

    // Thực hiện tối đa n - 1 lần (vì chu trình đơn giản nhất có thể có n - 1 cạnh)
    for(int k = 1; k <= n - 1; k++) {
        bool stop = true; // Nếu không có cập nhật nào => kết thúc sớm

        // Duyệt tất cả cặp (j, i): cạnh từ j -> i
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // Nếu tồn tại đường đi tốt hơn từ j -> i qua a[j][i]
                if(d[i] > d[j] + a[j][i]) {
                    d[i] = d[j] + a[j][i];  // cập nhật khoảng cách
                    pr[i] = j;              // cập nhật đỉnh trước
                    stop = false;           // có thay đổi, tiếp tục lặp nữa
                }
            }
        }

        // Nếu không có cập nhật nào thì dừng lại sớm
        if(stop) {
            return 1; // Không có chu trình âm, thuật toán thành công
        }
    }
    return 0; // Có thể tồn tại chu trình âm (nếu ta tiếp tục cập nhật sau n-1 vòng)
}

int main() {
    cin >> n; // Nhập số đỉnh

    // Nhập ma trận trọng số của đồ thị
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j]; // a[i][j] là trọng số từ j đến i
        }
    }

    int u; 
    cin >> u; // Nhập đỉnh bắt đầu

    // Gọi thuật toán Bellman-Ford
    if (!Bellman_Ford(u)) {
        cout << "Co chu trinh am" << endl; // Nếu hàm trả về 0 => có chu trình âm
    }
    else {
        // In ra khoảng cách ngắn nhất từ u đến các đỉnh khác
        for(int i = 1; i <= n; i++) {
            cout << d[i] << ' ';
        }
    }

    cout << endl;
    return 0;
}
