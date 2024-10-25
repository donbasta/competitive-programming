#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Segtree {
    vector<pair<int, int>> tree;
    int n;
    Segtree(int n) : n(n), tree(4 * n + 5) {}
    void build(int v, int s, int e, const vector<int>& T) {
        if (s == e) {
            tree[v] = make_pair(T[s], s);
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
        tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
    }
    pair<int, int> que(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return que(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return que(v << 1 | 1, mid + 1, e, l, r);
        return min(
            que(v << 1, s, mid, l, mid), que(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
    pair<int, int> que(int l, int r) {
        return que(1, 0, n - 1, l, r);
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n), fi(n + 1, -1), le(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (fi[ar[i]] == -1) {
            fi[ar[i]] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        le[i] = fi[ar[i]];
    }

    Segtree sgt(n);
    sgt.build(1, 0, n - 1, le);

    vector<int> dp(n), piv(n, -1);
    for (int i = 0; i < n; i++) {
        int L = le[i];
        if (L == i) {
            dp[i] = (i ? dp[i - 1] : 0);
        } else if (L == i - 1) {
            dp[i] = (i >= 2 ? dp[i - 2] : 0);
        } else {
            pair<int, int> mn = sgt.que(L + 1, i - 1);
            if (mn.first >= L) {
                int st = L;
                dp[i] = (st ? dp[st - 1] : 0) + (i - st - 1);
            } else {
                int idx = mn.second;
                dp[i] = dp[idx] + i - 1 - idx;
            }
        }
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