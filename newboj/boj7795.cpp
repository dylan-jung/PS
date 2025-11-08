#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        map<int, int> arr1;
        map<int, int> arr2;
        for(int i = 0; i < n; i++) {
            int k;
            cin >> k;
            arr1[k] += 1;
        }
        for(int i = 0; i < m; i++) {
            int k;
            cin >> k;
            arr2[k] += 1;
        }

        
    }
}