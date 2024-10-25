#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

typedef struct item *pitem;
struct item {
    int val, prio, cnt;
    bool rev;
    pitem l, r;
    item(int val) : prio(rng32()), val(val), cnt(0), rev(false), l(NULL), r(NULL){};
};

int cnt(pitem t) { return t ? t->cnt : 0; }

void upd(pitem t) {
    if (t) {
        t->cnt = 1 + cnt(t->l) + cnt(t->r);
    }
}

// push for reverse operation
void push(pitem t) {
    if (t && t->rev) {
        t->rev = false;
        swap(t->l, t->r);
        if (t->l)
            t->l->rev ^= true;
        if (t->r)
            t->r->rev ^= true;
    }
}

void split(pitem t, pitem &l, pitem &r, int key, int add = 0) {
    if (!t)
        return void(l = r = 0);
    push(t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split(t->l, l, t->l, key, add), r = t;
    else
        split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
    upd(t);
}

void merge(pitem &t, pitem l, pitem r) {
    push(l);
    push(r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prio > r->prio)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd(t);
}

void insert(pitem &t, pitem it, int pos) {
    if (!t) {
        t = it;
        return;
    }
    pitem t1, t2;
    split(t, t1, t2, pos);
    merge(t1, t1, it);
    merge(t, t1, t2);
}

void reverse(pitem t, int l, int r) {
    pitem t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    t2->rev ^= true;
    merge(t, t1, t2);
    merge(t, t, t3);
}

void erase(pitem &t, int pos) {
    pitem t1, t2, t3;
    split(t, t1, t2, pos);
    split(t2, t2, t3, 1);
    merge(t, t1, t3);
}

int get(pitem &t, int pos) {
    pitem t1, t2, t3;
    split(t, t1, t2, pos);
    split(t2, t2, t3, 1);
    int ret = t2->val;
    merge(t1, t1, t2);
    merge(t, t1, t3);
    return ret;
}

void output(pitem t) {
    if (!t)
        return;
    push(t);
    output(t->l);
    cout << t->val << ' ';
    output(t->r);
}

void el_psy_congroo() {
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