#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ll last = 0, tmp = 0;
        for (int j = i + 1; j < n; j++) {
            tmp += (last + a[j]) / a[j];
            last = (last + a[j]) / a[j] * a[j];
        }
        last = 0;
        for (int j = i - 1; j >= 0; j--) {
            tmp += (last + a[j]) / a[j];
            last = (last + a[j]) / a[j] * a[j];
        }
        ans = min(ans, tmp);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}