#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

int n;
string s;

void solve() {
    cin >> n >> s;
    int lastIdx = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'F') {
            continue;
        } else if (lastIdx == -1) {
            lastIdx = i;
        } else if (s[i] != s[lastIdx]) {
            // cerr << i << ' ' << lastIdx << '\n';
            ans = (ans + 1LL * (lastIdx + 1) * (n - i)) % MOD;
        }
        lastIdx = i;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
  
    return 0;
}