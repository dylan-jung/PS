#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int arr[500000];

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    cin >> m;
    for(int i = 0; i < m; i++) {
        int q;
        cin >> q;
        cout << binary_search(arr, arr+n, q) << " ";
    }
    cout << endl;
}