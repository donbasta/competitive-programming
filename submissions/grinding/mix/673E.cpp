#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<ll> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<ld> F(n), P(n), Q(n), I(n);
    P[0] = t[0];
    I[0] = ld(1) / ld(t[0]);
    for (int i = 1; i < n; i++) {
        P[i] = P[i - 1] + t[i];
        F[i] = P[i - 1] / ld(t[i]);
        Q[i] = Q[i - 1] + F[i];
        I[i] = I[i - 1] + ld(1) / ld(t[i]);
    }

    auto cost = [&](int l, int r) -> ld {
        ld ret = (r - l + 1);
        ret += Q[r] - Q[l];
        if (l) {
            ret -= P[l - 1] * (I[r] - I[l]);
        }
        return ret;
    };

    vector<ld> dp(n), ndp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = cost(0, i);
    }
    const function<void(int, int, int, int)> solve = [&](int l, int r, int optl, int optr) {
        if (l > r) return;
        int mid = (l + r) >> 1;
        pair<ld, int> best = make_pair(1e18, -1);
        for (int i = optl; i <= min(mid, optr); i++) {
            best = min(best, make_pair((i ? dp[i - 1] : ld(0)) + cost(i, mid), i));
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
    cout << fixed << setprecision(16);
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