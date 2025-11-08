#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    auto q = queue<int>();
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    while(q.size() != 1) {
        q.pop();
        int t = q.front();
        q.push(t);
        q.pop();
    }
    cout << q.front();;
}