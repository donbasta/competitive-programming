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
    int val, y, c = 1;
    bool rev;
    Node(int val) : val(val), y(rng()), rev(false) {}
    void recalc();
    void push();
};

int cnt(Node *n) { return n ? n->c : 0; }
void Node::recalc() { c = cnt(l) + cnt(r) + 1; }
void Node::push() {
    if (rev) {
        rev = false;
        swap(l, r);
        if (l) l->rev ^= true;
        if (r) r->rev ^= true;
    }
}

// ada k element di first split, sisanya di second split
pair<Node *, Node *> split(Node *n, int k) {
    if (!n) return {};
    n->push();
    if (cnt(n->l) >= k) {
        auto pa = split(n->l, k);
        n->l = pa.second;
        n->recalc();
        return make_pair(pa.first, n);
    } else {
        auto pa = split(n->r, k - cnt(n->l) - 1);
        n->r = pa.first;
        n->recalc();
        return make_pair(n, pa.second);
    }
}

Node *merge(Node *l, Node *r) {
    if (l) l->push();
    if (r) r->push();
    if (!l) return r;
    if (!r) return l;
    if (l->y > r->y) {
        l->r = merge(l->r, r);
        l->recalc();
        return l;
    } else {
        r->l = merge(l, r->l);
        r->recalc();
        return r;
    }
}

// insert n ke indeks ke pos (kirinya ada pos buah elemen)
Node *insert(Node *t, Node *n, int pos) {
    auto pa = split(t, pos);
    return merge(merge(pa.first, n), pa.second);
}

// from t, erase yang ada di indeks ke pos
Node *erase(Node *t, int pos) {
    auto pa = split(t, pos);
    auto pb = split(pa.second, 1);
    return merge(pa.first, pb.second);
}

// get value yang ada di posisi ke pos
int get(Node *t, int pos) {
    auto pa = split(t, pos);
    auto pb = split(pa.second, 1);
    int ret = pb.first->val;
    Node *N = merge(pa.first, pb.first);
    N = merge(N, pb.second);
    return ret;
}

Node *reverse(Node *t, int l, int r) {
    auto pa = split(t, l);
    auto pb = split(pa.second, r - l + 1);
    pb.first->rev ^= true;
    Node *N = merge(pa.first, pb.first);
    N = merge(N, pb.second);
    return N;
}

void el_psy_congroo() {
    int n, q, m;
    cin >> n >> q >> m;

    Node *tree = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree = insert(tree, new Node(x), i);
    }

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        --l, --r;
        if (t == 1) {
            int val = get(tree, r);
            tree = erase(tree, r);
            tree = insert(tree, new Node(val), l);
        } else if (t == 2) {
            tree = reverse(tree, l, r);
        }
    }

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        --b;
        cout << get(tree, b) << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}