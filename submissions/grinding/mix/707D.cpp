#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Vertex {
    Vertex *lc, *rc;
    int sum;
    bool lz = false;
    Vertex(int val) : lc(nullptr), rc(nullptr), sum(val) {}
    Vertex(Vertex* lc, Vertex* rc) : lc(lc), rc(rc), sum(0), lz(false) {
        if (lc) sum += lc->sum;
        if (rc) sum += rc->sum;
    }
    Vertex(Vertex* v) {
        sum = v->sum, lz = v->lz, lc = v->lc, rc = v->rc;
    }
};

Vertex* init(int s, int e) {
    if (s == e) return new Vertex(0);
    int mid = (s + e) >> 1;
    return new Vertex(init(s, mid), init(mid + 1, e));
}

Vertex* lazy(Vertex* v, int s, int e) {
    Vertex* ret = new Vertex(v);
    ret->lz ^= 1;
    ret->sum = (e - s + 1) - ret->sum;
    return ret;
}

void push(Vertex* v, int s, int e) {
    if (!v->lz) return;
    int mid = (s + e) >> 1;
    v->lc = lazy(v->lc, s, mid);
    v->rc = lazy(v->rc, mid + 1, e);
    v->lz = false;
}

Vertex* upd_val(Vertex* v, int s, int e, int idx, int val) {
    if (s == e) return new Vertex(val);
    int mid = (s + e) >> 1;
    push(v, s, e);
    if (idx <= mid)
        return new Vertex(upd_val(v->lc, s, mid, idx, val), v->rc);
    else
        return new Vertex(v->lc, upd_val(v->rc, mid + 1, e, idx, val));
}

Vertex* upd_invert(Vertex* v, int s, int e, int l, int r) {
    if (s == l && e == r) {
        Vertex* ret = new Vertex(v->lc, v->rc);
        ret->sum = (e - s + 1) - v->sum;
        ret->lz = v->lz ^ 1;
        return ret;
    }
    int mid = (s + e) >> 1;
    push(v, s, e);
    if (r <= mid)
        return new Vertex(upd_invert(v->lc, s, mid, l, r), v->rc);
    else if (l >= mid + 1)
        return new Vertex(v->lc, upd_invert(v->rc, mid + 1, e, l, r));
    else
        return new Vertex(
            upd_invert(v->lc, s, mid, l, mid),
            upd_invert(v->rc, mid + 1, e, mid + 1, r));
}

void el_psy_congroo() {
    int n, m, q;
    cin >> n >> m >> q;
    Vertex* sgt = init(0, n * m - 1);
    vector<Vertex*> history;
    history.push_back(sgt);
    for (int ii = 0; ii < q; ii++) {
        int tp, i, j, k;
        cin >> tp;
        if (tp == 1) {
            cin >> i >> j;
            --i, --j;
            sgt = upd_val(sgt, 0, m * n - 1, i * m + j, 1);
        } else if (tp == 2) {
            cin >> i >> j;
            --i, --j;
            sgt = upd_val(sgt, 0, m * n - 1, i * m + j, 0);
        } else if (tp == 3) {
            cin >> i;
            --i;
            sgt = upd_invert(sgt, 0, m * n - 1, i * m, i * m + m - 1);
        } else if (tp == 4) {
            cin >> k;
            sgt = history[k];
            // sgt = new Vertex(history[k]);
        }
        cout << sgt->sum << '\n';
        history.push_back(sgt);
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