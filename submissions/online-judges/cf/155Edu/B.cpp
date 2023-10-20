#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll A = accumulate(a.begin(), a.end(), 0ll);
    ll B = accumulate(b.begin(), b.end(), 0ll);
    ll MA = *min_element(a.begin(), a.end());
    ll MB = *min_element(b.begin(), b.end());
    ll ans = min(A + MB * n, B + MA * n);
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