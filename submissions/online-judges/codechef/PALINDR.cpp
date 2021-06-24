#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e5;

int fc[N + 5], ifc[N + 5];

int fpow (int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = (1LL * ret * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void init_fac () {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = (1LL * fc[i - 1] * i) % MOD;
    }
    ifc[N] = fpow (fc[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
        ifc[i] = (1LL * ifc[i + 1] * (i + 1)) % MOD;
    }
}

mt19937 rng32 (chrono::steady_clock::now().time_since_epoch().count());

typedef struct item * pitem;
struct item { 
    int val, prio, cnt;
    bool rev;
    vector<int> occ;
    pitem l, r;
    item (int val) : prio(rng32()), val(val), cnt(0), rev(false), l(NULL), r(NULL) {
        occ.resize(10);
        occ[val] = 1;
    };
};

int cnt (pitem t) { return t ? t -> cnt : 0; }

void upd (pitem t) { 
    if (t) { t -> cnt = 1 + cnt (t -> l) + cnt (t -> r); } 
    for (int i = 0; i < 10; i++) {
        t -> occ[i] = (i == t -> val);
        if (t -> l) t -> occ[i] += (t -> l -> occ[i]);
        if (t -> r) t -> occ[i] += (t -> r -> occ[i]);
    }
}

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

int get (pitem & t, int pos) {
    pitem t1, t2, t3;
    split (t, t1, t2, pos);
    split (t2, t2, t3, 1);
    int ret = t2 -> val;
    merge (t1, t1, t2);
    merge (t, t1, t3);
    return ret;
}

ll calc (pitem & t, int l, int r) {
    pitem t1, t2;
    split (t, t, t1, l);
    split (t1, t1, t2, r - l + 1);
    int len = r - l + 1;
    int ans = fc[len / 2];
    int odd = 0;
    for (int i = 0; i < 10; i++) {
        int cnt = (t1 -> occ[i]);
        ans = (1LL * ans * ifc[cnt / 2]) % MOD;
        if ((t1 -> occ[i]) & 1) {
            odd++;
        }
    }
    if ((len & 1) && (odd > 1)) ans = 0;
    if ((len % 2 == 0) && (odd > 0)) ans = 0;
    merge (t1, t1, t2);
    merge (t, t, t1);
    return ans;
}

int n, m;
string s;

void solve() {
    cin >> n >> m >> s;

    pitem T = NULL;
    for (int i = 0; i < n; i++) {
        insert (T, new item(s[i] - 'a'), i);
    }

    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        --l, --r;
        if (t == 1) {
            reverse (T, l, r);
        } else if (t == 2) {
            ll ans = calc (T, l, r);
            cout << ans << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init_fac ();

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}