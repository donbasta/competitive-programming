#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<ll> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    vector<ll> jar;
    for (int i = 1; i < n; i++) {
        jar.emplace_back(d[i] - d[i - 1]);
    }
    ll ans = d.back();
    // cerr << ans << '\n';
    for (int i = 0; i < n - 1; i++) {
        ans -= 1LL * jar[i] * (i + 1) * (n - i - 1);
        // cerr << i << ' ' << ans << ' ' << jar[i] << '\n';
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