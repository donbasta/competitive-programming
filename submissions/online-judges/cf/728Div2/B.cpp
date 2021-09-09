#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<ll> ar(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        for (ll j = ar[i]; j < 2LL * i; j += ar[i]) {
            int idx = j - i;
            if (idx >= 1 && ar[idx] * ar[i] == j) {
                ans++;
            }
        }
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