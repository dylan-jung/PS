#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unordered_map<int, int> mp;
    int n;
    cin >> n;
    while(n--) {
        int k;
        cin >> k;
        mp[k]++;
    }

    int m;
    cin >> m;
    while(m--) {
        int k;
        cin >> k;
        cout << mp[k] << " ";
    }
}