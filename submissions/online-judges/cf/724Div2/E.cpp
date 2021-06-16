#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int n, m;

void solve() {
    cin >> n >> m;
    int ans = 1, cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto& c : s) {
            if (c == '#') ans = (ans * 2) % MOD, cnt++;
        }
    }
    if (cnt == m * n) ans--;
    cout << ans << '\n';
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