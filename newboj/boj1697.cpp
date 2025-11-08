#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    int arr[100001];
    bool visited[100001] = { false };
    queue<tuple<int, int>> q;
    
    q.push({n, 0});
    visited[n] = true;
    int result = 0;

    while(!q.empty()) {
        auto [x, dis] = q.front(); q.pop();
        
        if(x == k) {
            result = dis;
            break;
        }

        for(int i = 0; i < 3; i++) {
            int nx;
            if(i == 0) 
                nx = x - 1;
            else if(i == 1)
                nx = x + 1;
            else if(i == 2)
                nx = x * 2;
            
            if(0 <= nx && nx <= 100000) {
                if(visited[nx]) continue;
                visited[nx] = true;
                q.push({nx, dis+1});
            }
        }
    }

    cout << result;
}