#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<tuple<int, int>> edges[1001];

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[a].push_back({b, w});
    }
    int s, e;
    cin >> s >> e;

    int dist[1001];
    fill(dist, dist+1001, 1e9);
    dist[s] = 0;
    priority_queue<tuple<int, int>> pq;
    bool visited[1001] = { false };
    pq.push({0, s});
    while(!pq.empty()) {
        auto [w, now] = pq.top(); pq.pop();

        if(now == e) break;
        if(visited[now]) continue;
        visited[now] = true;

        for(auto [next, nw]: edges[now]) {
            int d = dist[now] + nw;
            if(d < dist[next]) {
                dist[next] = dist[now] + nw;
                pq.push({-dist[next], next});
            }
        }
    }
    cout << dist[e];
}