#include <bits/stdc++.h>

using namespace std;

int dp[16][1<<16];
int edges[16][16];
int n;

int tsp(int now, int visited) {
    if(visited == ((1<<n) - 1))
        return edges[now][0] == 0 ? 1e9 : edges[now][0];

    auto& ret = dp[now][visited];
    if(ret != -1) return ret;

    ret = 1e9;
    for(int i = 0; i < n; i++) {
        if(visited & (1 << i)) continue;
        if(edges[now][i] == 0) continue;
        ret = min(ret, tsp(i, visited | 1 << i) + edges[now][i]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> edges[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1);
}