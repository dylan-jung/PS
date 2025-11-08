#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int arr[301];
    cin >> n;

    arr[0] = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int dp[301][2] = { 0 };
    dp[0][0] = arr[0];
    dp[0][1] = -999;
    dp[1][0] = arr[1];
    dp[1][1] = arr[0] + arr[1];
    for(int i = 2; i < n; i++) {
        dp[i][0] = max(dp[i-2][1], dp[i-2][0]) + arr[i];
        dp[i][1] = dp[i-1][0] + arr[i];
    }

    // for(int i = 0; i < n; i++) {
    //     cout << dp[i][0] << " " << dp[i][1] << "\n";
    // }
    // cout << "\n";

    cout << max(dp[n-1][0], dp[n-1][1]);
}