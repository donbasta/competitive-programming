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

struct Node {
    Node *l = nullptr, *r = nullptr;
    ll func = 0, sum, val;
    int prio, c = 1;
    Node(ll val) : val(val), prio(rng()), sum(val) {}
    void recalc();
};

int cnt(Node *n) { return n ? n->c : 0; }
void Node::recalc() {
    c = cnt(l) + cnt(r) + 1;
    ll fL = (l ? l->func : 0ll);
    ll fR = (r ? r->func : 0ll);
    ll sL = (l ? l->sum : 0ll);
    ll sR = (r ? r->sum : 0ll);
    func = fL + fR - sL + sR;
    func = func + val * (cnt(l) - cnt(r));
    func = func + sR * cnt(l) - sL * cnt(r);

    sum = sL + sR + val;
}

// semua yang di kiri <k, sisanya >= k
pair<Node *, Node *> split(Node *n, int k) {
    if (!n) return {};
    if (n->val >= k) {
        auto pa = split(n->l, k);
        n->l = pa.second;
        n->recalc();
        return make_pair(pa.first, n);
    } else {
        auto pa = split(n->r, k);
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

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    vector<ll> pts = pos;
    sort(pts.begin(), pts.end());

    Node *treap = nullptr;
    for (int i = 0; i < n; i++) {
        treap = merge(treap, new Node(pts[i]));
    }

    int m;
    cin >> m;
    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            ll p, d;
            cin >> p >> d;
            --p;
            auto pa = split(treap, pos[p]);
            auto pb = split(pa.second, pos[p] + 1);
            treap = merge(pa.first, pb.second);
            pos[p] += d;
            pb = split(treap, pos[p]);
            treap = merge(merge(pb.first, new Node(pos[p])), pb.second);
        } else if (tp == 2) {
            ll L, R;
            cin >> L >> R;
            auto pa = split(treap, L);
            auto pb = split(pa.second, R + 1);
            if (!pb.first) {
                cout << 0 << '\n';
            } else {
                cout << pb.first->func << '\n';
            }
            treap = merge(merge(pa.first, pb.first), pb.second);
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