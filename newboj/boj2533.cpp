#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000001][2];
// dp[i][j] : i가 subtree의 root일 때,
// i가 얼리어답터일 경우 j(0: no, 1: yes), 최소 얼리어답터의 개수
vector<int> E[1000001];

int dfs(int k, int t, int par) {
    auto& ret = dp[k][t];
    if(ret) return ret;
    if(t==0) {
        for (auto &&c : E[k]) {
            if(c == par) continue;
            ret += dfs(c, 1, k);
        }
    }
    else {
        for (auto &&c : E[k]) {
            if(c == par) continue;
            ret += min(dfs(c, 0, k), dfs(c, 1, k));
        }
        ret += 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    cout << min(dfs(1, 0, 0), dfs(1, 1, 0));
}