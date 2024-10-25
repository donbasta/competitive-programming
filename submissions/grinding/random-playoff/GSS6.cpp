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

const ll INF = 2e18;

struct Node {
    Node *l = nullptr, *r = nullptr;
    ll val, maxPref, maxSuf, sum, maxSubSum;
    int prio, c = 1;
    Node(ll val) : val(val), prio(rng()) {
        maxPref = maxSuf = sum = maxSubSum = val;
    }
    void recalc();
};

int cnt(Node *node) { return node ? node->c : 0; }
void Node::recalc() {
    c = cnt(l) + cnt(r) + 1;
    ll maxPrefL = (l ? l->maxPref : -INF);
    ll sumL = (l ? l->sum : 0);
    ll maxSufL = (l ? l->maxSuf : -INF);
    ll maxSubSumL = (l ? l->maxSubSum : -INF);
    ll maxPrefR = (r ? r->maxPref : -INF);
    ll sumR = (r ? r->sum : 0);
    ll maxSufR = (r ? r->maxSuf : -INF);
    ll maxSubSumR = (r ? r->maxSubSum : -INF);

    maxPref = max({maxPrefL, sumL + val, sumL + val + maxPrefR});
    maxSuf = max({maxSufR, sumR + val, sumR + val + maxSufL});
    sum = sumL + sumR + val;
    maxSubSum = max({maxSubSumL, maxSubSumR, max(0ll, maxSufL) + val + max(0ll, maxPrefR)});
}

pair<Node *, Node *> split(Node *n, int k) {
    if (!n) return {};
    if (cnt(n->l) >= k) {
        auto pa = split(n->l, k);
        n->l = pa.second;
        n->recalc();
        return make_pair(pa.first, n);
    } else {
        auto pa = split(n->r, k - 1 - cnt(n->l));
        n->r = pa.first;
        n->recalc();
        return make_pair(n, pa.second);
    }
}

Node *merge(Node *l, Node *r) {
    if (!l) return r;
    if (!r) return l;
    if (l->prio > r->prio) {
        l->r = merge(l->r, r);
        l->recalc();
        return l;
    } else {
        r->l = merge(l, r->l);
        r->recalc();
        return r;
    }
}

Node *insert(Node *t, Node *n, int pos) {
    auto pa = split(t, pos);
    return merge(merge(pa.first, n), pa.second);
}

Node *erase(Node *t, int pos) {
    auto pa = split(t, pos);
    auto pb = split(pa.second, 1);
    return merge(pa.first, pb.second);
}

ll query(Node *t, int l, int r) {
    auto pa = split(t, l);
    auto pb = split(pa.second, r - l + 1);
    int ret = pb.first->maxSubSum;
    t = merge(pa.first, pb.first);
    t = merge(t, pb.second);
    return ret;
}

void el_psy_congroo() {
    int n;
    cin >> n;

    Node *treap = nullptr;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        treap = insert(treap, new Node(x), i);
    }

    int q;
    cin >> q;

    while (q--) {
        char tp;
        cin >> tp;
        ll x, y;
        if (tp == 'I') {
            cin >> x >> y;
            --x;
            treap = insert(treap, new Node(y), x);
        } else if (tp == 'D') {
            cin >> x;
            --x;
            treap = erase(treap, x);
        } else if (tp == 'R') {
            cin >> x >> y;
            --x;
            treap = erase(treap, x);
            treap = insert(treap, new Node(y), x);
        } else if (tp == 'Q') {
            cin >> x >> y;
            --x, --y;
            cout << query(treap, x, y) << '\n';
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