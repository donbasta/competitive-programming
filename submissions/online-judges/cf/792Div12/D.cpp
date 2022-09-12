#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> ar(n + 1);
    vector<ll> lul;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        ans += ar[i];
        lul.emplace_back(ar[i] + i);
    }
    ll sum = ans;
    sort(lul.begin(), lul.end());
    reverse(lul.begin(), lul.end());
    ll pref = 0;
    for (ll rem = 1; rem <= k; rem++) {
        pref += lul[rem - 1];
        ll tmp = sum - (pref) + (n * rem) - (rem * (rem - 1) / 2);
        ans = min(ans, tmp);
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