#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> ar(n + 5), cold(k + 5), hot(k + 5);
    for (int i = 0; i < n; i++) {
        cin >> ar[i + 1];
        --ar[i + 1];
    }
    vector<ll> dif(n + 5), pref(n + 5);
    for (int i = 0; i < k; i++) {
        cin >> cold[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> hot[i];
    }
    if (n == 1) {
        cout << cold[ar[1]] << '\n';
        return;
    }
    const auto now = [&](int a, int b) {
        if (b == 0) return cold[ar[a]];
        if (ar[a] == ar[b]) return hot[ar[a]];
        return cold[ar[a]];
    };
    for (int i = 1; i <= n; i++) {
        dif[i] = now(i, i - 1);
        pref[i] = pref[i - 1] + dif[i];
    }

    vector<ll> p(n + 5);
    vector<set<ll>> ve(k);
    set<pair<ll, int>> all;
    p[1] = cold[ar[1]];
    all.insert(make_pair(p[1] - pref[1], 0));
    for (int i = 2; i <= n; i++) {
        auto cur = *all.begin();
        if (ar[cur.second] == ar[i]) {
            p[i] = cur.first + pref[i - 1] + now(i, cur.second);
        } else {
            if (!ve[ar[i]].empty()) {
                auto now_k = *ve[ar[i]].begin();
                ll x1 = now_k + pref[i - 1] + now(i, i);
                ll x2 = cur.first + pref[i - 1] + now(i, cur.second);
                p[i] = min(x1, x2);
            }
        }
        all.insert(make_pair(p[i] - pref[i], i - 1));
        ve[ar[i - 1]].insert(p[i] - pref[i]);
    }

    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, p[i] + pref[n] - pref[i]);
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