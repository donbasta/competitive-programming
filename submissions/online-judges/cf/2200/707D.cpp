#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

typedef struct Vertex * pvertex;
struct Vertex {
    Vertex *l, *r;
    int sum;
    bool inv;

    Vertex(int val) : l(NULL), r(NULL), sum(val), inv(false) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0), inv(false) {
        if (l) sum += (l -> sum);
        if (r) sum += (r -> sum);
    }
};

void push(pvertex v, int s, int e) {
    if (v -> inv) {
        int mid = (s + e) >> 1;
        if (v -> l) {
            v -> l -> inv ^= true;
            v -> l -> sum = (mid - s + 1 - (v -> l -> sum));
        }
        if (v -> r) {
            v -> r -> inv ^= true;
            v -> r -> sum = (e - mid - (v -> r -> sum));
        }
        v -> inv = false;
    }
}

pvertex build(const vector<int>& ar, int s, int e) {
    if (s == e) { return new Vertex(ar[s]); }
    int mid = (s + e) >> 1;
    return new Vertex(build(ar, s, mid), build(ar, mid + 1, e));
}

int get(pvertex v, int s, int e, int l, int r) {
    if (l > r) return 0;
    if (s == l && e == r) return v -> sum;
    push (v, s, e);
    int mid = (s + e) >> 1;
    return get (v -> l, s, mid, l, min(r, mid)) + get (v -> r, mid + 1, e, max(l, mid + 1), r);
}

pvertex update(pvertex v, int s, int e, int pos, int val) {
    if (s == e) return new Vertex(val);
    push (v, s, e);
    int mid = (s + e) >> 1;
    if (pos <= mid) return new Vertex(update(v -> l, s, mid, pos, val), v -> r);
    else return new Vertex(v -> l, update(v -> r, mid + 1, e, pos, val));
}

pvertex invert(pvertex v, int s, int e, int l, int r) {
    if (s == l && e == r) {
        pvertex ret = new Vertex(v -> sum);
        ret -> l = v -> l;
        ret -> r = v -> r;
        ret -> inv = (v -> inv) ^ 1;
        ret -> sum = (e - s + 1 - (ret -> sum));
        return ret;
    }
    push (v, s, e);
    int mid = (s + e) >> 1;
    if (l >= mid + 1) {
        return new Vertex(v -> l, invert(v -> r, mid + 1, e, l, r));
    } else if (r <= mid) {
        return new Vertex(invert(v -> l, s, mid, l, r), v -> r);
    }
    return new Vertex(invert(v -> l, s, mid, l, mid), invert(v -> r, mid + 1, e, mid + 1, r));
}

int n, m, q;

void solve() {
    cin >> n >> m >> q;

    vector<int> ar(n * m);
    pvertex T = build(ar, 0, n * m - 1);
    vector<pvertex> history;
    history.push_back(T);

    for (int it = 1; it <= q; it++) {
        int t, i, j;
        cin >> t;
        if (t == 1) {
            cin >> i >> j;
            T = update(T, 0, n * m - 1, (i - 1) * m + (j - 1), 1);
        } else if (t == 2) {
            cin >> i >> j;
            T = update(T, 0, n * m - 1, (i - 1) * m + (j - 1), 0);
        } else if (t == 3) {
            cin >> i;
            T = invert(T, 0, n * m - 1, (i - 1) * m, i * m - 1);
        } else if (t == 4) {
            cin >> i;
            T = history[i];
        }
        history.push_back(T);
        cout << get(T, 0, n * m - 1, 0, n * m - 1) << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}