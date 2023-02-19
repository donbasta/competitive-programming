#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        tot += ar[i];
    }
    ll ans = 1;
    ll pref = 0;
    for (int i = 0; i < n - 1; i++) {
        pref += ar[i];
        ans = max(ans, __gcd(pref, tot - pref));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}