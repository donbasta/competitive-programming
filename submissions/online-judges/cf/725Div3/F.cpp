#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll cnt(ll x) {
    ll pw = 1;
    int pg = 0;
    while (pw <= x) pw *= 10LL, pg++;
    pg++;
    ll cum = 0;
    ll ans = 0;
    for (; pw > 0; pw /= 10) {
        ans += (1LL * pg * ((x / pw) - cum));
        cum = x / pw;
        pg--;
    }
    return ans;
}

ll l, r;

void solve() {
    cin >> l >> r;
    ll ans = cnt(r) - cnt(l);
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