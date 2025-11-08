#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int>> edge[10001];
bool visited[10001];

int max_value = 0;
int max_node = 0;

void dfs(int now, int dis) {
    if(visited[now]) return;
    visited[now] = true;

    if(dis > max_value) {
        max_value = dis;
        max_node = now;
    }

    for(auto [next, weight] : edge[now]) {
        dfs(next, dis+weight);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(visited, visited+10001, 0);

    int n;
    cin >> n;
    while(--n) {
        int a, b, w;
        cin >> a >> b >> w;
        edge[a].push_back({b, w});
        edge[b].push_back({a, w});
    }

    dfs(1, 0);
    int t = max_node;
    fill(visited, visited+10001, 0);
    dfs(t, 0);
    cout << max_value;
}