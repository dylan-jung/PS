#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int arr[100][100];
    bool visited[100][100] = { false };

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '0') {
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = 1;
            }
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int result = 0;

    queue<tuple<int, int, int>> q;
    q.push({0, 0, 1});
    while(!q.empty()) {
        auto [x, y, dis] = q.front(); q.pop();
        // cout << x << " " << y << " " << dis << "\n";
        
        if(x == n-1 && y == m-1) {
            result = dis;
            break;
        }

        for(int i =0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] == 1) {
                if(visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({nx, ny, dis+1});
            }
        }
    }
    cout << result;
}