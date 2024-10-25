#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;
const int N = 3e5;

int st[4 * N + 50];

int get(int v, int s, int e, int l, int r) {
    if (l > r) return INF;
    if (s == l && e == r) {
        return st[v];
    }
    int mid = (s + e) >> 1;
    return min(get(v << 1, s, mid, l, min(r, mid)), get(v << 1 | 1, mid + 1, e, max(mid + 1, l), r));
}

void upd(int v, int s, int e, int pos, int val) {
    if (s == e) {
        st[v] = val;
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid)
        upd(v << 1, s, mid, pos, val);
    else
        upd(v << 1 | 1, mid + 1, e, pos, val);
    st[v] = min(st[v << 1], st[v << 1 | 1]);
}

int n;

void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        p[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        --b[i];
    }
    for (int i = 1; i <= 4 * n + 10; i++) {
        st[i] = INF;
    }
    for (int i = 0; i < n; i++) {
        reverse(p[i].begin(), p[i].end());
        if (!p[i].empty()) upd(1, 0, n - 1, i, p[i].back());
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (p[b[i]].empty()) {
            ok = false;
            break;
        }
        int pos = p[b[i]].back();
        if (get(1, 0, n - 1, 0, b[i] - 1) < pos) {
            ok = false;
            break;
        }
        p[b[i]].pop_back();
        upd(1, 0, n - 1, b[i], p[b[i]].empty() ? INF : p[b[i]].back());
    }

    cout << (ok ? "YES" : "NO") << '\n';
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