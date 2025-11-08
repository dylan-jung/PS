#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    auto pq = priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if(k == 0) {
            if(pq.size() == 0) {
                cout << 0 << "\n";
            }
            else {
                auto [absval, val] = pq.top();
                cout << val << "\n";
                pq.pop();
            }
        }
        else {
            pq.push({abs(k), k});
        }
    }
}