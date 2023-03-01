#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> ar(n + 1), pre(n + 1), lol(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = ar[i] + pre[i - 1];
        lol[i] = pre[i] - x * i;
    }
    ll ans = 0;
    if (x >= 0) {
        set<pair<ll, ll>> se;
        se.emplace(0, 0);
        for (int i = k + 1; i <= n; i++) {
            auto mn = *se.begin();
            ans = max(ans, lol[i] - mn.first + 2ll * k * x);
            se.emplace(lol[i - k], i - k);
        }
        for (int len = 1; len <= k; len++) {
            for (int i = len; i <= n; i++) {
                ans = max(ans, lol[i] - lol[i - len] + 2ll * len * x);
            }
        }
    } else {
        set<pair<ll, ll>> se;
        se.emplace(0, 0);
        if (n >= k + 2) {
            for (int i = 1; i <= n; i++) {
                auto mn = *se.begin();
                ans = max(ans, lol[i] - mn.first);
                se.emplace(lol[i], i);
                if ((i + 1) >= (n - k)) {
                    se.erase(se.find(make_pair(lol[i + 1 - (n - k)], i + 1 - (n - k))));
                }
            }
        }
        for (int len = n - k; len <= n; len++) {
            for (int i = len; i <= n; i++) {
                ans = max(ans, lol[i] - lol[i - len] + 2ll * (len + k - n) * x);
            }
        }
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