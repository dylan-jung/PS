#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[500][500];
    int dp[500][500] = { 0 };

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    } 

    dp[0][0] = arr[0][0];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j-1 >= 0)
                dp[i][j] = max(dp[i-1][j-1], dp[i][j]);
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
            dp[i][j] += arr[i][j];
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j <= i; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int result = 0;
    for(int i = 0; i < n; i++) {
        result = max(result, dp[n-1][i]);
    }
    cout << result;
}