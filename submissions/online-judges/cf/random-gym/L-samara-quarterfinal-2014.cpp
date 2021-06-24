#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

mt19937 rng32 (chrono::steady_clock::now().time_since_epoch().count());

typedef struct item * pitem;
struct item {
    char val;
    int prio, cnt;
    bool rev;
    pitem l, r;
    item (char val) : prio(rng32()), val(val), cnt(0), rev(false), l(NULL), r(NULL) {};
};

int cnt (pitem t) { return t ? t->cnt : 0; }

void upd (pitem t) { 
    if (t) { t -> cnt = 1 + cnt (t -> l) + cnt (t -> r); } 
}

//push for reverse operation
void push (pitem t) {
    if (t && t -> rev) {
        t -> rev = false;
        swap (t -> l, t -> r);
        if (t -> l) t -> l -> rev ^= true;
        if (t -> r) t -> r -> rev ^= true;
    }
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t) return void (l = r = 0);
    push (t);
    int cur_key = add + cnt (t -> l);
    if (key <= cur_key)
        split (t -> l, l, t -> l, key, add),  r = t;
    else
        split (t -> r, t -> r, r, key, add + 1 + cnt (t -> l)),  l = t;
    upd (t);
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
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

void reverse (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r - l + 1);
    t2 -> rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}

char get (pitem & t, int pos) {
    pitem t1, t2, t3;
    split (t, t1, t2, pos);
    split (t2, t2, t3, 1);
    char ret = t2 -> val;
    merge (t1, t1, t2);
    merge (t, t1, t3);
    return ret;
}

int n, l, r, m;
string s;

void solve() {
    cin >> n >> l >> r >> s >> m;
    --l, --r;

    pitem T = NULL;
    for (int i = 0; i < n; i++) {
        insert (T, new item (s[i]), i);
    }

    while (m--) {
        char type, x, y;
        cin >> type;
        if (type == 'S') {
            cin >> x >> y;
            if (x == 'L' && y == 'R') l++;
            if (x == 'L' && y == 'L') l--;
            if (x == 'R' && y == 'R') r++;
            if (x == 'R' && y == 'L') r--;
        } else if (type == 'Q') {
            cin >> x;
            char ans;
            if (x == 'L') ans = get (T, l);
            if (x == 'R') ans = get (T, r);
            cout << ans;
        } else if (type == 'R') {
            reverse (T, l, r);
        }
    }
    cout << '\n';
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