struct Segtree {
    int n;
    vector<int> t;
    function<int(int, int)> Func;
    Segtree (int _n, function<int(int, int)> _f) : n(_n), Func(_f) {
        t.resize(4 * _n + 5);
    }
    void build (int v, int s, int e, const vector<int>& ar) {
        if (s == e) {
            t[v] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build (v << 1, s, mid, ar);
        build (v << 1 | 1, mid + 1, e, ar);
        t[v] = Func(t[v << 1], t[v << 1 | 1]);
    }
    void upd (int v, int s, int e, int pos, int val) {
        if (s == e) {
            t[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid) {
            upd (v << 1, s, mid, pos, val);
        } else {
            upd (v << 1 | 1, mid + 1, e, pos, val);
        }
        t[v] = Func(t[v << 1], t[v << 1 | 1]);
    }
    int que (int v, int s, int e, int l, int r) {
        if (l == s && r == e) { 
            return t[v]; 
        }
        int mid = (s + e) >> 1;
        if (r <= mid) {
            return que(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            return que(v << 1 | 1, mid + 1, e, l, r);
        } else {
            return Func(que(v << 1, s, mid, l, mid), que(v << 1 | 1, mid + 1, e, mid + 1, r));
        }
    }
};

int main() {
    function<int(int, int)> fmin = [&](int a, int b) -> int {return min(a, b);};
    Segtree sgt = Segtree(n, fmin);
    vector<int> ar(n + 1);
    sgt.build(1, 1, n, ar);
}