#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<deque<int>> de(n + 1);
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    vector<ll> dp(n), ndp(n);

    int cl = 0, cr = -1;
    ll cur_cost = 0;
    auto cost = [&](int l, int r) -> ll {
        while (cr < r) {
            cr++, de[ar[cr]].push_back(cr);
            if (de[ar[cr]].size() >= 2) cur_cost += de[ar[cr]].back() - de[ar[cr]][de[ar[cr]].size() - 2];
        }
        while (cl > l) {
            cl--, de[ar[cl]].push_front(cl);
            if (de[ar[cl]].size() >= 2) cur_cost += de[ar[cl]][1] - de[ar[cl]].front();
        }
        while (cr > r) {
            if (de[ar[cr]].size() >= 2) cur_cost -= de[ar[cr]].back() - de[ar[cr]][de[ar[cr]].size() - 2];
            de[ar[cr]].pop_back(), cr--;
        }
        while (cl < l) {
            if (de[ar[cl]].size() >= 2) cur_cost -= de[ar[cl]][1] - de[ar[cl]].front();
            de[ar[cl]].pop_front(), cl++;
        }
        return cur_cost;
    };

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

    for (int i = 0; i < n; i++) {
        dp[i] = cost(0, i);
    }
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