#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += abs(a[i] - a[i - 1]);
    }
    ll mx = *max_element(a.begin(), a.end());
    ll mn = *min_element(a.begin(), a.end());
    ll l = a[0], r = a.back();
    if (l < r) swap(l, r);
    if (mx < x) {
        ans += min(x - l, (x - mx) * 2);
    }
    if (mn > 1) {
        ans += min(r - 1, (mn - 1) * 2);
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