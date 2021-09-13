#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string s[2];

void solve() {
    cin >> n;
    cin >> s[0] >> s[1];
    int ans = 0;
    int zero = 0;
    for (int i = 0; i < n; i++) {
        if (s[0][i] != s[1][i]) {
            ans += 2;
            continue;
        }
        int now = s[0][i] - '0';
        if (now == 0) ans++;
    }
    // cerr << ans << '\n';
    int id = 0;
    while (id < n) {
        if (s[0][id] != s[1][id]) {
            id++;
            continue;
        }
        int now = s[0][id] - '0';
        if ((id < n - 1) && (s[0][id + 1] == s[1][id + 1])) {
            int nx = s[0][id + 1] - '0';
            if (now != nx) {
                ans++;
                id += 2;
                continue;
            }
        }
        id++;
    }
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