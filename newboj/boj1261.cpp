#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int arr[100][100];
    bool visited[100][100] = { false };
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << arr[i][j];
    //     }
    //     cout << "\n";
    // }

    int dx[4] = { 0, 0, -1, 1};
    int dy[4] = { -1, 1, 0, 0};

    deque<tuple<int, int, int>> q;
    q.push_back({0, 0, 0});
    visited[0][0] = true;
    int ans = 0;
    while(!q.empty()) {
        auto [x, y, cost] = q.front(); q.pop_front();

        // cout << x << y << cost << "\n";
        if(x == n-1 && y == m-1) {
            ans = cost;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]) {
                if(arr[nx][ny] == 0) {
                    q.push_front({nx, ny, cost});
                    visited[nx][ny] = true;
                }
                else {
                    q.push_back({nx, ny, cost+1});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    cout << ans;
}