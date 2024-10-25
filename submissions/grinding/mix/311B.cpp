#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;

void el_psy_congroo() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<ll> pre(n + 1);
    for (int i = 2; i <= n; i++) {
        ll d;
        cin >> d;
        pre[i] = pre[i - 1] + d;
    }
    vector<ll> cats;
    for (int i = 0; i < m; i++) {
        ll h, t;
        cin >> h >> t;
        cats.push_back(t - pre[h]);
    }
    sort(cats.begin(), cats.end());

    vector<ll> pref(m);
    pref[0] = cats[0];
    for (int i = 1; i < m; i++) {
        pref[i] = pref[i - 1] + cats[i];
    }

    auto cost = [&](int i, int j) -> ll {
        ll tot = pref[j] - (i ? pref[i - 1] : 0);
        ll ret = 1ll * (j - i + 1) * cats[j] - tot;
        // ll ret = 1ll * (j - i + 1) * max(0ll, cats[j]) - tot;
        return ret;
    };

    vector<ll> dp(m), ndp(m);
    for (int i = 0; i < m; i++) {
        dp[i] = cost(0, i);
    }
    const function<void(int, int, int, int)> solve = [&](int l, int r, int optl, int optr) {
        if (l > r) return;
        int mid = (l + r) >> 1;
        pair<ll, int> best = make_pair(INF, -1);
        for (int i = optl; i <= min(mid, optr); i++) {
            best = min(best, make_pair((i ? dp[i - 1] : 0ll) + cost(i, mid), i));
        }
        ndp[mid] = best.first;
        int opt = best.second;
        solve(l, mid - 1, optl, opt);
        solve(mid + 1, r, opt, optr);
    };
    for (int i = 1; i < p; i++) {
        solve(0, m - 1, 0, m - 1);
        dp.swap(ndp);
    }
    cout << dp[m - 1] << '\n';
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