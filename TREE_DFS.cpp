#include <bits/stdc++.h>
using namespace std;

void T_DFS(int a[100][100], int n)
{
    bool visited[100] = {false};
    int T[100]; // lưu cây khung DFS
    stack<int> s;

    s.push(1); // bắt đầu từ đỉnh 1 (bạn có thể đổi nếu cần)
    visited[1] = true;
    T[1] = -1; // gốc cây

    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        for (int v = n; v >= 1; v--) // duyệt ngược để giống DFS
        {
            if (a[u][v] == 1 && !visited[v])
            {
                s.push(v);
                visited[v] = true;
                T[v] = u; // lưu cha
            }
        }
    }

    // In cây khung DFS
    cout << "Cay khung DFS (dinh - cha):\n";
    for (int i = 1; i <= n; i++)
    {
        if (T[i] != -1)
            cout << i << " - " << T[i] << '\n';
    }
}

int main()
{
    int a[100][100];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    T_DFS(a, n);

    return 0;
}
