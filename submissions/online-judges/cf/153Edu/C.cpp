#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct BIT {
    vector<int> tree;
    int n;
    BIT(int n) : n(n) {
        tree.resize(n + 1);
    }
    void upd(int idx, int val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }
    int get(int idx) {
        int ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1), pos(n + 1);
    vector<bool> valley(n + 1);
    BIT bit(n), cnt(n);
    int mn = INT_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
        if (p[i] < mn) {
            mn = p[i];
            valley[p[i]] = true;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = bit.get(pos[i]);
        // cout << i << ' ' << x << ' ' << valley[i] << ' ' << cnt.get(pos[i]) << '\n';
        if ((x < cnt.get(pos[i])) || valley[i]) {
            bit.upd(pos[i], 1);
        } else {
            // cout << i << '\n';
            ans++;
        }
        cnt.upd(pos[i], 1);
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