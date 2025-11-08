// map iteration 연습하기 좋은 문제

#include<iostream>
#include<map>
#include<algorithm>

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

        map<int, int> a;
        map<int, int> b;
        unordered_map<int, int> psum;
        for(int i = 0; i < n; i++) {
            int k;
            cin >> k;
            a[k] += 1;
        }
        for(int i = 0; i < m; i++) {
            int k;
            cin >> k;
            b[k] += 1;
        }

        int full = 0;
        int temp = 0;
        for(auto k: b) {
            full += k.second;
            psum[k.first] = temp;
            temp += k.second;
        }

        // for(auto k: psum) {
        //     cout << k.first << " " << k.second << "\n";
        // }

        int value = 0;
        for(auto now: a) {
            auto lit = b.lower_bound(now.first);
            if(lit != b.end()) {
                // cout << now.first << " " << lit->first << " " << psum[lit->first] << " " << now.second << "\n";
                value += psum[lit->first] * now.second;
                // for(auto it = b.begin(); it != lit; it++) { // 최초시도: 이터레이팅.. 연습
                //     value += now.second * it->second;
                // }
                // cout << now.first << " " << value << "\n";
            }
            else {
                value += full * now.second;
            }
        }
        cout << value << "\n";
    }
}