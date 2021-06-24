#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

mt19937 rng32 (chrono::steady_clock::now().time_since_epoch().count());

typedef struct item * pitem;
struct item {
    int val, prio, cnt;
    pitem l, r;
    item (int val) : prio(rng32()), val(val), cnt(0), l(NULL), r(NULL) {};
};

int cnt (pitem t) { return t ? t -> cnt : 0; }

void upd (pitem t) { 
    if (t) { t -> cnt = 1 + cnt (t -> l) + cnt (t -> r); } 
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t) return void (l = r = 0);
    int cur_key = add + cnt (t -> l);
    if (key <= cur_key)
        split (t -> l, l, t -> l, key, add),  r = t;
    else
        split (t -> r, t -> r, r, key, add + 1 + cnt (t -> l)),  l = t;
    upd (t);
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l -> prio > r -> prio)
        merge (l -> r, l -> r, r),  t = l;
    else
        merge (r -> l, l, r -> l),  t = r;
    upd (t);
}

void insert (pitem & t, pitem it, int pos) {
    if (!t) {
        t = it; return;
    }
    pitem t1, t2;
    split (t, t1, t2, pos);
    merge (t1, t1, it);
    merge (t, t1, t2);
}

int get (pitem & t, int pos) {
    pitem t1, t2, t3;
    split (t, t1, t2, pos);
    split (t2, t2, t3, 1);
    int ret = t2 -> val;
    merge (t1, t1, t2);
    merge (t, t1, t3);
    return ret;
}

void swap_interval (pitem & t, int l1, int r1, int l2, int r2) {
    pitem t1, t2, t3, t4;
    split (t, t, t1, l1);
    split (t1, t1, t2, r1 - l1 + 1);
    split (t2, t2, t3, l2 - r1 - 1);
    split (t3, t3, t4, r2 - l2 + 1);
    merge (t, t, t3);
    merge (t, t, t2);
    merge (t, t, t1);
    merge (t, t, t4);
}

int n;

void solve() {
    cin >> n;

    pitem T = NULL;
    for (int i = 0; i < n; i++) {
        insert (T, new item (i), i);
    }

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a >= b) continue;
        --a, --b;
        int l1, r1, l2, r2;
        l1 = a, r1 = min (b - 1, n - 1 - b + a);
        l2 = b, r2 = min (n - 1, 2 * b - 1 - a);
        swap_interval (T, l1, r1, l2, r2);
    }

    for (int i = 0; i < n; i++) {
        cout << get (T, i) + 1 << ' ';
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