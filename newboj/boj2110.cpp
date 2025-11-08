#include <bits/stdc++.h>

using namespace std;

int n, c;
vector<int> arr;

bool canInstall(int k) {
    int cnt = 1;
    int last = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i]-last >= k) {
            cnt += 1;
            last = arr[i];
        }
    }
    return cnt >= c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    arr.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int l = 1, r = arr.back() - arr.front();
    int result = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        // cout << mid << "\n";
        if(canInstall(mid)) {
            result = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << result;
}