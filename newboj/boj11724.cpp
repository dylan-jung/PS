#include <bits/stdc++.h>

using namespace std;

bool visited[1001];
vector<int> edges[1001];
int cnt;

void dfs(int now) {
    if(visited[now]) return;
    visited[now] = true;

    for(auto next: edges[now]) {
        dfs(next);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(visited, visited+1001, 0);
    int n, m;
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        cnt++;
        dfs(i);
    }
    cout << cnt;
}