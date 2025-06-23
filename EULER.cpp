#include <bits/stdc++.h>
using namespace std;

// Biến toàn cục
int n;                          // Số đỉnh
int a[101][101];                // Ma trận kề a[i][j] = 1 nếu có cạnh giữa i và j
vector<bool> visited(101, false); // Không cần thiết trong thuật toán này (có thể bỏ)


// Thuật toán tìm chu trình Euler bắt đầu từ đỉnh u
vector<int> EULER(int u) {  
    stack<int> st;           // Stack dùng để mô phỏng hành trình
    st.push(u);              // Bắt đầu từ đỉnh u
    vector<int> CE;          // Danh sách các đỉnh thuộc chu trình Euler (đi ngược)

    while(!st.empty()) {
        int x = st.top();    // Lấy đỉnh trên đỉnh stack nhưng chưa xóa

        bool ok = true;      // Biến kiểm tra xem x còn cạnh nối nào không
        for(int i = 1; i <= n; i++) {
            if(a[x][i] == 1) {         // Nếu còn cạnh từ x đến i
                ok = false;
                st.push(i);           // Tiếp tục đi đến đỉnh i
                a[x][i] = a[i][x] = 0; // Xóa cạnh giữa x và i (vì đồ thị vô hướng)
                break;                // Thoát để tiếp tục với đỉnh mới
            }
        }

        if(ok) {             // Nếu x không còn cạnh nối nào
            CE.push_back(x); // Thêm x vào kết quả
            st.pop();        // Quay lại đỉnh trước đó
        }
    }

    return CE; // Danh sách đỉnh trong chu trình Euler (theo thứ tự ngược)
}
int main() {
    cin >> n; // Nhập số đỉnh

    // Nhập ma trận kề
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j]; // a[i][j] = 1 nếu có cạnh i–j
        }
    }

    int u; 
    cin >> u; // Nhập đỉnh bắt đầu chu trình Euler

    // Gọi thuật toán
    vector<int> CE = EULER(u);

    // Đảo ngược kết quả vì quá trình push_back theo thứ tự ngược
    for(int i = CE.size() - 1; i >= 0; i--) {
        cout << CE[i] << ' ';
    }
    return 0;
}

