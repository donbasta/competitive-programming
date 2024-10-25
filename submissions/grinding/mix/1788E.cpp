#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1, -INF) {}
    void upd(int idx, int val) {
        idx++;
        while (idx <= n) {
            tree[idx] = max(tree[idx], val), idx += idx & -idx;
        }
    }
    int get(int idx) {
        idx++;
        int ret = -INF;
        while (idx) {
            ret = max(ret, tree[idx]), idx -= idx & -idx;
        }
        return ret;
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n + 1), pre(n + 1);
    vector<int> f(n + 1), ord(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        pre[i] = pre[i - 1] + ar[i];
    }

    vector<pair<ll, int>> ve;
    for (int i = 0; i <= n; i++) {
        ve.emplace_back(pre[i], i);
    }
    sort(ve.begin(), ve.end());
    for (int i = 0; i <= n; i++) {
        ord[ve[i].second] = i;
    }

    BIT bit(n + 1);
    bit.upd(ord[0], 0);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        int idx = ord[i];
        int mx = bit.get(idx);
        f[i] = max(f[i], mx + i);
        bit.upd(idx, f[i] - i);
    }
    cout << f[n] << '\n';
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