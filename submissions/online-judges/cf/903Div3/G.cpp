#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    int n;
    vector<int> tree;
    Segtree(int n) : n(n), tree(4 * n + 5) {}
    void build(int v, int s, int e, const vector<int>& ar) {
        if (s == e) {
            tree[v] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, ar);
        build(v << 1 | 1, mid + 1, e, ar);
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid) {
            upd(v << 1, s, mid, idx, val);
        } else if (idx >= mid + 1) {
            upd(v << 1 | 1, mid + 1, e, idx, val);
        }
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        int mid = (s + e) >> 1;
        if (r <= mid) {
            return get(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            return get(v << 1 | 1, mid + 1, e, l, r);
        }
        return get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    if (n == 1) {
        for (int i = 0; i < m; i++) {
            int t, l, r, x;
            cin >> t >> l >> r;
            if (t == 1)
                cin >> x;
            else if (t == 2)
                cout << "YES" << '\n';
        }
        return;
    }
    if (n == 2) {
        for (int i = 0; i < m; i++) {
            int t, l, r, x;
            cin >> t >> l >> r;
            --l, --r;
            if (t == 1) {
                cin >> x;
                x %= 26;
                for (int j = l; j <= r; j++) {
                    int nw = ((s[j] - 'a') + x) % 26;
                    s[j] = nw + 'a';
                }
            } else if (t == 2) {
                if (r == l) {
                    cout << "YES" << '\n';
                } else {
                    cout << (s[0] == s[1] ? "NO" : "YES") << '\n';
                }
            }
        }
        return;
    }
    vector<int> a1(n - 1), a2(n - 2);
    vector<int> c1(n - 1), c2(n - 2);
    for (int i = 0; i < n - 1; i++) {
        a1[i] = (s[i + 1] - s[i]) % 26;
        if (a1[i] < 0) a1[i] += 26;
        c1[i] = a1[i] == 0;
    }
    for (int i = 0; i < n - 2; i++) {
        a2[i] = (s[i + 2] - s[i]) % 26;
        if (a2[i] < 0) a2[i] += 26;
        c2[i] = a2[i] == 0;
    }
    Segtree s1(n - 1), s2(n - 2);
    s1.build(1, 0, n - 2, c1);
    s2.build(1, 0, n - 3, c2);
    for (int i = 0; i < m; i++) {
        int t, l, r, x;
        cin >> t >> l >> r;
        --l, --r;
        if (t == 1) {
            cin >> x;
            x %= 26;
            if (l > 0) {
                int prv = a1[l - 1];
                int nx = (a1[l - 1] + x) % 26;
                if (prv == 0) {
                    s1.upd(1, 0, n - 2, l - 1, 0);
                }
                if (nx == 0) {
                    s1.upd(1, 0, n - 2, l - 1, 1);
                }
                a1[l - 1] = nx;
            }
            if (r < n - 1) {
                int prv = a1[r];
                int nx = (a1[r] - x) % 26;
                if (nx < 0) nx += 26;
                if (prv == 0) {
                    s1.upd(1, 0, n - 2, r, 0);
                }
                if (nx == 0) {
                    s1.upd(1, 0, n - 2, r, 1);
                }
                a1[r] = nx;
            }
            if (l > 1) {
                int prv = a2[l - 2];
                int nx = (a2[l - 2] + x) % 26;
                if (prv == 0) {
                    s2.upd(1, 0, n - 3, l - 2, 0);
                }
                if (nx == 0) {
                    s2.upd(1, 0, n - 3, l - 2, 1);
                }
                a2[l - 2] = nx;
            }
            if (l > 0 && r >= l + 1) {
                int prv = a2[l - 1];
                int nx = (a2[l - 1] + x) % 26;
                if (prv == 0) {
                    s2.upd(1, 0, n - 3, l - 1, 0);
                }
                if (nx == 0) {
                    s2.upd(1, 0, n - 3, l - 1, 1);
                }
                a2[l - 1] = nx;
            }
            if (r + 2 < n) {
                int prv = a2[r];
                int nx = (a2[r] - x) % 26;
                if (nx < 0) nx += 26;
                if (prv == 0) {
                    s2.upd(1, 0, n - 3, r, 0);
                }
                if (nx == 0) {
                    s2.upd(1, 0, n - 3, r, 1);
                }
                a2[r] = nx;
            }
            if (l <= r - 1 && r + 1 < n) {
                int prv = a2[r - 1];
                int nx = (a2[r - 1] - x) % 26;
                if (nx < 0) nx += 26;
                if (prv == 0) {
                    s2.upd(1, 0, n - 3, r - 1, 0);
                }
                if (nx == 0) {
                    s2.upd(1, 0, n - 3, r - 1, 1);
                }
                a2[r - 1] = nx;
            }
        } else if (t == 2) {
            if (l == r) {
                cout << "YES" << '\n';
            } else if (r - l == 1) {
                int a = s1.get(1, 0, n - 2, l, r - 1);
                if (a == 0) {
                    cout << "YES" << '\n';
                } else {
                    cout << "NO" << '\n';
                }
            } else {
                int a = s1.get(1, 0, n - 2, l, r - 1);
                int b = s2.get(1, 0, n - 3, l, r - 2);
                if (a + b == 0) {
                    cout << "YES" << '\n';
                } else {
                    cout << "NO" << '\n';
                }
            }
        }
    }
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