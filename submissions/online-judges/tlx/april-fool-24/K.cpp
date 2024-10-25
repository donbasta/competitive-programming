#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tc template <class
tc T1, class T2 > ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
tc T, class = decay_t<decltype(*begin(declval<T>()))>, class = enable_if_t < !is_same<T, string>::value >> ostream &operator<<(ostream &os, const T &c) {
    os << '{';
    for (auto it = c.begin(); it != c.end(); ++it) os << &", "[2 * (it == c.begin())] << *it;
    return os << '}';
}
#define PARENS ()
#define EEE(...) EEE1(EEE1(__VA_ARGS__))
#define EEE1(...) EEE2(__VA_ARGS__)
#define EEE2(...) __VA_ARGS__
#define REP(macro, ...) __VA_OPT__(EEE(REP_HELPER(macro, __VA_ARGS__)))
#define REP_HELPER(macro, a1, ...) macro(a1) __VA_OPT__(REP_AGAIN PARENS(macro, __VA_ARGS__))
#define REP_AGAIN() REP_HELPER
#define out(x) "\t[" << #x " = " << x << "]\n"
#ifdef LOCAL
#define debug(...) cerr << "Line " << __LINE__ << "\n" \
                        << REP(out, __VA_ARGS__) << "\n";
#else
#define debug(...) "itfeelsliketimeispassingsoquickly.thepassageoftimedependsentirelyonwhereyou'restanding.relativitytheory...it'ssoromantic.butit'sjustsotragictoo."
#endif

const int INF = 2e9;

using ll = __int128;
istream &operator>>(istream &is, ll &v) {
    string s;
    is >> s;
    v = 0;
    for (auto &it : s)
        if (isdigit(it)) v = v * 10 + it - '0';
    if (s[0] == '-') v *= -1;
    return is;
}

ostream &operator<<(ostream &os, const ll &v) {
    if (v == 0) return (os << "0");
    ll num = v;
    if (v < 0) os << '-', num = -num;
    string s;
    for (; num > 0; num /= 10) s.push_back((char)(num % 10) + '0');
    reverse(s.begin(), s.end());
    return (os << s);
}
struct Segtree {
    vector<ll> tree;
    Segtree(int n) {
        tree.resize(4 * n + 5);
    }
    void upd(int v, int s, int e, int idx, ll val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else
            upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    ll get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
};

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    Segtree sgt(n);
    while (q--) {
        ll a, b, c;
        cin >> b >> a >> c;
        if (a == 1) {
            --b;
            ll now = sgt.get(1, 0, n - 1, b, b);
            sgt.upd(1, 0, n - 1, b, now + c);
        } else if (a == 2) {
            --b;
            sgt.upd(1, 0, n - 1, b, c);
        } else if (a == 3) {
            --b, --c;
            cout << sgt.get(1, 0, n - 1, b, c) << '\n';
        }
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