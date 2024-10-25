#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct BIT {
    vector<ll> bit;
    int n;
    BIT(int n) : n(n), bit(n + 1) {}
    void upd(int idx, ll val) {
        idx++;
        while (idx <= n) bit[idx] += val, idx += idx & -idx;
    }
    ll get(int idx) {
        idx++;
        ll ret = 0;
        while (idx) ret += bit[idx], idx -= idx & -idx;
        return ret;
    }
    ll get(int a, int b) {
        return get(b) - (a ? get(a - 1) : 0);
    }
};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n), id(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        id[p[i]] = i;
    }
    vector<vector<int>> lefts(n);
    for (int i = 1; i <= n; i++) {
        int cur = id[i];
        for (int j = i; j <= n; j += i) {
            int lmao = id[j];
            int l = min(cur, lmao), r = max(cur, lmao);
            lefts[r].push_back(l);
        }
    }
    vector<vector<vector<int>>> qu(n);
    vector<ll> ans(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        qu[r].push_back(vector<int>{l, i});
    }
    BIT bit(n);
    for (int i = 0; i < n; i++) {
        for (auto x : lefts[i]) {
            bit.upd(x, 1);
        }
        for (auto q : qu[i]) {
            ans[q[1]] = bit.get(q[0], i);
        }
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }
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