#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Segtree {
    vector<int> tmin, tmax;
    Segtree(int n) : tmin(4 * n + 5), tmax(4 * n + 5) {}
    void build(int v, int s, int e, const vector<int>& T) {
        if (s == e) {
            tmin[v] = tmax[v] = T[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
        tmin[v] = min(tmin[v << 1], tmin[v << 1 | 1]);
        tmax[v] = max(tmax[v << 1], tmax[v << 1 | 1]);
    }
    int get_min(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tmin[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get_min(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get_min(v << 1 | 1, mid + 1, e, l, r);
        return min(
            get_min(v << 1, s, mid, l, mid), get_min(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
    int get_max(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tmax[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get_max(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get_max(v << 1 | 1, mid + 1, e, l, r);
        return max(
            get_max(v << 1, s, mid, l, mid), get_max(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        pos[A[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    Segtree sa(n), sb(n);
    sa.build(1, 0, n - 1, A);
    sb.build(1, 0, n - 1, B);
    vector<int> need;
    for (int i = 0; i < n; i++) {
        if (A[i] > B[i]) {
            cout << "NO" << '\n';
            return;
        }
        if (A[i] < B[i]) {
            need.push_back(i);
        }
    }
    for (auto e : need) {
        int sz = pos[B[e]].size();
        int x = upper_bound(pos[B[e]].begin(), pos[B[e]].end(), e) - pos[B[e]].begin();
        bool ok = false;
        if (x < sz) {
            int ok1 = sa.get_max(1, 0, n - 1, e, pos[B[e]][x]);
            int ok2 = sb.get_min(1, 0, n - 1, e, pos[B[e]][x]);
            if ((ok1 <= B[e]) && (ok2 >= B[e])) ok = true;
        }
        if (x > 0) {
            int ok1 = sa.get_max(1, 0, n - 1, pos[B[e]][x - 1], e);
            int ok2 = sb.get_min(1, 0, n - 1, pos[B[e]][x - 1], e);
            if ((ok1 <= B[e]) && (ok2 >= B[e])) ok = true;
        }
        if (!ok) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}