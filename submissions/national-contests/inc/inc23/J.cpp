#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int B = 22;

ll conv(ll x) {
    vector<ll> dig;
    while (x) {
        dig.push_back(x % 4);
        x /= 4;
    }
    while (dig.size() < B) {
        dig.push_back(0);
    }
    for (auto& e : dig) {
        e = e % 2;
    }
    ll ret = 0;
    for (int i = 0; i < B; i++) {
        ret += dig[i] * (1ll << i);
    }
    return ret;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n), br(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    ll mx = 0;
    for (int i = 0; i < n; i++) {
        br[i] = conv(ar[i]);
        mx = max(mx, br[i]);
    }

    ll sz = 0, tmp = 1;
    while (tmp <= mx) {
        tmp <<= 1;
        sz++;
    }

    ll msk = (1 << sz) - 1;
    vector<ll> dp(1 << sz);

    for (int i = 0; i < n; i++) {
        dp[br[i]]++;
    }

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j <= msk; j++) {
            if (j & (1 << i)) {
                dp[j] += dp[j ^ (1 << i)];
            }
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += dp[msk ^ br[i]];
    }

    ans -= dp[0];
    ans /= 2;
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