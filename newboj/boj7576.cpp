#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;
    int arr[1000][1000];
    bool visited[1000][1000] = { false };
    queue<tuple<int, int, int>> q;
    
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                q.push({i, j, 0});
                visited[i][j] = true;
            }
            if(arr[i][j] != -1) cnt++; // 채워야할 토마토 개수 세기, day0일때 완숙토마토도 셈
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int result = 0;

    while(!q.empty()) {
        auto [x, y, day] = q.front(); q.pop();
        
        cnt -= 1;
        arr[x][y] = 1;
        if(cnt == 0) {
            result = day;
            break;
        }
        // cout << x << " " << y << " " << day << "\n";

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(visited[nx][ny] || arr[nx][ny] != 0) continue;
                visited[nx][ny] = true;
                q.push({nx, ny, day+1});
            }
        }
    }

    if(cnt > 0) {
        cout << -1;
    } else{
        cout << result;
    }

}