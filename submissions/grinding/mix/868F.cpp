#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<int> cnt(n + 1);

    int cl = 0, cr = -1;
    ll cur_cost = 0;
    auto cost = [&](int l, int r) -> ll {
        while (cr < r) cr++, cur_cost += cnt[ar[cr]], cnt[ar[cr]]++;
        while (cl > l) cl--, cur_cost += cnt[ar[cl]], cnt[ar[cl]]++;
        while (cr > r) cnt[ar[cr]]--, cur_cost -= cnt[ar[cr]], cr--;
        while (cl < l) cnt[ar[cl]]--, cur_cost -= cnt[ar[cl]], cl++;
        return cur_cost;
    };

    vector<ll> dp(n), ndp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = cost(0, i);
    }
    const function<void(int, int, int, int)> solve = [&](int l, int r, int optl, int optr) {
        if (l > r) return;
        int mid = (l + r) >> 1;
        pair<ll, int> best = make_pair(INF, -1);
        for (int i = optl; i <= min(optr, mid); i++) {
            ll C = cost(i, mid);
            best = min(best, make_pair((i ? dp[i - 1] : 0) + C, i));
        }
        ndp[mid] = best.first;
        int opt = best.second;
        solve(l, mid - 1, optl, opt);
        solve(mid + 1, r, opt, optr);
    };
    for (int i = 1; i < k; i++) {
        solve(0, n - 1, 0, n - 1);
        dp.swap(ndp);
    }
    cout << dp[n - 1] << '\n';
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