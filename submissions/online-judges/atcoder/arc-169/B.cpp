#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    ll n, S;
    cin >> n >> S;
    vector<ll> ar(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        pref[i] = pref[i - 1] + ar[i];
    }
    vector<int> ri(n + 1);
    for (int i = 1; i <= n; i++) {
        ll kur = pref[i - 1];
        ll x = upper_bound(pref.begin(), pref.end(), kur + S) - pref.begin() - 1;
        ri[i] = x;
    }
    // for (int i = 1; i <= n; i++) {
    //     cerr << i << ' ' << ri[i] << '\n';
    // }
    ll ans = 1;
    vector<ll> f(n + 2);
    f[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        ll cur = ri[i] - i + 1;
        cur += (f[ri[i] + 1] + n - ri[i]);
        f[i] = cur;
        ans += f[i];
    }
    // for (int i = 1; i <= n; i++) {
    //     cerr << i << ' ' << f[i] << '\n';
    // }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}