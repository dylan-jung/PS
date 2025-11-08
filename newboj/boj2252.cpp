#include <bits/stdc++.h>

using namespace std;

vector<int> edges[32001];
int indeg[32001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(indeg, indeg+32001, 0);

    int n, m;
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        indeg[b]++;
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) {
            // cout << i;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front(); q.pop();
        cout << now << " ";
        for(auto next: edges[now]) {
            indeg[next] -= 1;
            if(indeg[next] == 0) q.push(next);
        }
    }
}