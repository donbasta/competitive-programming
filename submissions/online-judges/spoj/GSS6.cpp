#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Node {
    Node *l = 0, *r = 0;
    int val, y, c = 1;
    Node(int val) : val(val), y(rand()) {}
    void recalc();
    void op();
};

int cnt(Node* n) { return n ? n->c : 0; }
void Node::recalc() { c = cnt(l) + cnt(r) + 1; }

template <class F>
void each(Node* n, F f) {
    if (n) {
        each(n->l, f);
        f(n->val);
        each(n->r, v);
    }
}

pair<Node*, Node*> split(Node* n, int k) {
    if (!n) return {};
    if (cnt(n->l) >= k) {
        auto pa = split(n->l, k);
        n->l = pa.second;
        n->recalc();
        return {pa.first, n};
    } else {
        auto pa = split(n->r, k - cnt(n->l) - 1);
        n->r = pa.first;
        n->recalc();
        return {n, pa.second};
    }
}

Node* merge(Node* l, Node* r) {
    Node* ret;
    if (!l) return ret = r;
    if (!r) return ret = l;
    if (l->y > r->y) {
        l->r = merge(l->r, r);
        ret = l;
    } else {
        r->l = merge(l, r->l);
        ret = r;
    }
    ret->recalc();
    op(ret);
    return ret;
}

Node* insert(Node* t, Node* n, int pos) {
    auto pa = split(t, pos);
    return merge(merge(pa.first, n), pa.second);
}

Node* erase(Node* t, int pos) {
    auto pa = split(t, pos);
    auto pb = split(pa.second, 1);
    return merge(pa.first, pb.second);
}

ll query(Node* t, int a, int b) {
    auto pa = split(t, a);
    auto pb = split(pa.second, b - a + 1);
}

void el_psy_congroo() {
    int n;
    cin >> n;
    Node* treap = nullptr;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        treap = insert(treap, new Node(x), i);
    }

    int q;
    cin >> q;
    while (q--) {
        char op;
        cin >> op;
        if (op == 'I') {
            ll x, y;
            cin >> x >> y;
            treap = insert(treap, new Node(y), x);
        } else if (op == 'D') {
            ll x;
            cin >> x;
            treap = erase(treap, x);
        } else if (op == 'R') {
            ll x, y;
            cin >> x >> y;
            treap = erase(treap, x);
            treap = insert(treap, new Node(y), x);
        } else if (op == 'Q') {
            ll x, y;
            cin >> x >> y;
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