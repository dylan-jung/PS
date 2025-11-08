#include <bits/stdc++.h>

using namespace std;

int dp[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(dp, dp+1000001, 1e9);
    dp[1] = 0;

    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        dp[i] = min(dp[i], dp[i-1]);
        if(i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2]);
        if(i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3]);
        dp[i] += 1;
    }

    // for(int i = 1; i <= n; i++)
    //     cout << dp[i] << " ";
    // cout << "\n";
    cout << dp[n];
}