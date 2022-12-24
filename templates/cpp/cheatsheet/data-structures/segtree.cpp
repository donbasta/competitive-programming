#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

template <typename T, class F = function<T(const T &, const T &)>>
class Segtree
{
public:
    int n;
    vector<T> t;
    F func;

    Segtree(int _n, const F &_f) : n(_n), func(_f)
    {
        t.resize(4 * _n + 5);
    }
    void build(int v, int s, int e, const vector<T> &ar)
    {
        if (s == e)
        {
            t[v] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, ar);
        build(v << 1 | 1, mid + 1, e, ar);
        t[v] = func(t[v << 1], t[v << 1 | 1]);
    }
    void upd(int v, int s, int e, int pos, const T &val)
    {
        if (s == e)
        {
            t[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
        {
            upd(v << 1, s, mid, pos, val);
        }
        else
        {
            upd(v << 1 | 1, mid + 1, e, pos, val);
        }
        t[v] = func(t[v << 1], t[v << 1 | 1]);
    }
    T que(int v, int s, int e, int l, int r)
    {
        if (l == s && r == e)
        {
            return t[v];
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
        {
            return que(v << 1, s, mid, l, r);
        }
        else if (l >= mid + 1)
        {
            return que(v << 1 | 1, mid + 1, e, l, r);
        }
        else
        {
            return func(que(v << 1, s, mid, l, mid), que(v << 1 | 1, mid + 1, e, mid + 1, r));
        }
    }
};

int main()
{
    function<int(int, int)> fmin = [&](int a, int b) -> int
    { return min(a, b); };
    int n = 5;
    Segtree<int> sgt(n, fmin);
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ar[i] = i + 1;
    }
    sgt.build(1, 1, n, ar);
    for (int i = 0; i < sgt.t.size(); i++)
    {
        cerr << i << ' ' << sgt.t[i] << '\n';
    }
}
