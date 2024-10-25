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
};

int cnt(Node* n) { return n ? n->c : 0; }
void Node::recalc() { c = cnt(l) + cnt(r) + 1; }

void debug(Node* n) {
    if (n) {
        debug(n->l);
        cerr << n->val << '\n';
        debug(n->r);
    }
}

pair<Node*, Node*> split(Node* n, int k) {  // left punya k elements
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

Node* insert(Node* t, Node* n, int pos) {
    auto pa = split(t, pos);
    return merge(merge(pa.first, n), pa.second);
}

Node* erase(Node* t, int pos) {
    auto pa = split(t, pos);
    auto pb = split(pa.second, 1);
    return merge(pa.first, pb.second);
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

    debug(treap);
    cerr << "-----\n";

    treap = insert(treap, new Node(3), 1);
    debug(treap);
    cerr << "-----\n";

    treap = erase(treap, 4);
    debug(treap);
    cerr << "-----\n";
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