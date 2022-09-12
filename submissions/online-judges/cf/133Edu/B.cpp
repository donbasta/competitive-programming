#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ve;
    vector<int> buf;
    for (int i = 1; i <= n; i++) {
        buf.emplace_back(i);
    }
    ve.emplace_back(buf);
    cout << n << '\n';
    for (int i = 2; i <= n; i++) {
        swap(buf[0], buf[i - 1]);
        ve.emplace_back(buf);
    }
    for (auto v : ve) {
        for (auto vv : v) {
            cout << vv << ' ';
        }
        cout << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}
