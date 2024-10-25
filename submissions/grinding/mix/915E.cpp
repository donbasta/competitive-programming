#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Vertex {
    int s, e;
    int lz = -1, val;
    Vertex *lc = nullptr, *rc = nullptr;
    Vertex(int s, int e, int val) : s(s), e(e), val(val) {}
    void extend() {
        if (!lc && (s != e)) {
            int mid = (s + e) >> 1;
            lc = new Vertex(s, mid, mid - s + 1);
            rc = new Vertex(mid + 1, e, e - mid);
        }
    }
    void push() {
        if (!lc && (s != e)) extend();
        if (lz == -1) return;
        int mid = (s + e) >> 1;
        lc->lz = rc->lz = lz;
        lc->val = (lz ? (mid - s + 1) : 0);
        rc->val = (lz ? (e - mid) : 0);
        lz = -1;
    }
    void upd(int l, int r, int col) {
        if (s == l && e == r) {
            lz = col;
            val = (col ? (e - s + 1) : 0);
            return;
        }
        push();
        int mid = (s + e) >> 1;
        if (r <= mid)
            lc->upd(l, r, col);
        else if (l >= mid + 1)
            rc->upd(l, r, col);
        else {
            lc->upd(l, mid, col);
            rc->upd(mid + 1, r, col);
        }
        val = lc->val + rc->val;
    }
    int get(int l, int r) {
        if (s == l && e == r) {
            return val;
        }
        push();
        int mid = (s + e) >> 1;
        if (r <= mid)
            return lc->get(l, r);
        else if (l >= mid + 1)
            return rc->get(l, r);
        return lc->get(l, mid) + rc->get(mid + 1, r);
    }
};

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    Vertex* sgt = new Vertex(1, n, n);
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        sgt->upd(l, r, k - 1);
        cout << sgt->get(1, n) << '\n';
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