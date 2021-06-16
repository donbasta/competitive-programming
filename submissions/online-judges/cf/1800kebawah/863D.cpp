#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

typedef struct item* pitem;
struct item {
    int prio, key;
    bool rev;
    pitem l, r;
    item (int key) : prio (rng32()), key (key), rev (false), l (NULL), r (NULL) {s}
}

void push (pitem t) {
    if (t && t->rev) {
        t->rev = false;
        swap (t->l, t->r);
        if (t->l) t->l->rev ^= true;
        if (t->r) t->r->rev ^= true;
    }
}

int cnt (pitem t) {
    return t ? t->cnt : 0;
}

void upd (pitem t) {
    if (t) {
        t->cnt = cnt (t->l) + cnt (t->r) + 1;
    }
}

void merge (pitem & t, pitem l, pitem r) {
    push (l), push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prio > r->prio)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd (t);
}

void reverse (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r - l + 1);
    t2->rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}

void insert (pitem& t, int pos, pitem n) {
    if (!t) {
        t = n;
    } else {
        pitem t1, t2;
        split (t, t1, t2, pos);
        merge (t1, t1, n);
        merge (t, t1, t2);
    }
}

void erase (pitem& t, int key) {
    if (!t) return;
    if (t->key == key) {
        merge (t, t->l, t->r);
    } else {
        erase (key < t->key ? t->l : t->r, val);
    }
    upd (t);
}

const int N = 2e5;

int a[N + 10];
int n, q, m;

pitem T;

void solve() {
    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        merge (T, T, &item(i));
    }
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            erase ()
        } else if (t == 2) {

        }
    }
    for (int i = 1; i <= m; i++) {
        int b;
        cin >> b;
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