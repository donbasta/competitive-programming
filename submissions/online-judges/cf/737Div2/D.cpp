#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int N = 3e5;

int n, m;
int dp[N + 5], dpk[N + 5], back[N + 5];
int t[4 * 2 * N + 5], lz[4 * 2 * N + 5];
map<int, int> mp;

void push(int v) {
    if (lz[v]) {
        t[v << 1] = max(t[v << 1], lz[v]);
        lz[v << 1] = max(lz[v << 1], lz[v]);
        t[v << 1 | 1] = max(t[v << 1 | 1], lz[v]);
        lz[v << 1 | 1] = max(lz[v << 1 | 1], lz[v]);
        lz[v] = 0;
    }
}

void upd(int v, int s, int e, int l, int r, int val) {
    if (s == l && e == r) {
        t[v] = val;
        lz[v] = val;
        return;
    }
    push(v);
    int mid = (s + e) >> 1;
    if (r <= mid) upd(v << 1, s, mid, l, r, val);
    else if (l > mid) upd(v << 1 | 1, mid + 1, e, l, r, val);
    else {
        upd(v << 1, s, mid, l, mid, val);
        upd(v << 1 | 1, mid + 1, e, mid + 1, r, val);
    }
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

int get(int v, int s, int e, int l, int r) {
    if (s == l && e == r) {
        return t[v];
    }
    push(v);
    int mid = (s + e) >> 1;
    if (r <= mid) return get(v << 1, s, mid, l, r);
    else if (l > mid) return get(v << 1 | 1, mid + 1, e, l, r);
    else {
        return max(
            get(v << 1, s, mid, l, mid),
            get(v << 1 | 1, mid + 1, e, mid + 1, r)
        );
    }
}

void solve() {
    cin >> n >> m;
    vector<vector<pair<int, int>>> seg(n + 1);
    vector<int> idx;
    for (int i = 0; i < m; i++) {
        int id, l, r;
        cin >> id >> l >> r;
        idx.emplace_back(l);
        idx.emplace_back(r);
        seg[id].emplace_back(l, r);
    }
    sort(idx.begin(), idx.end());
    idx.resize(unique(idx.begin(), idx.end()) - idx.begin());
    int sz = (int) idx.size();
    for (int i = 0; i < sz; i++) {
        mp[idx[i]] = i + 1;
    }

    for (int i = 1; i <= n; i++) {
        back[i] = -1;
    }

    dp[1] = 0;
    dpk[1] = 0;
    back[1] = 0;
    for (auto e : seg[1]) {
        int fi = mp[e.first], se = mp[e.second];
        upd(1, 1, sz, fi, se, 1);
    }
    for (int i = 2; i <= n; i++) {
        int last = 0;
        dpk[i] = i - 1;
        for (auto e : seg[i]) {
            int fi = mp[e.first], se = mp[e.second];
            int u = get(1, 1, sz, fi, se);
            // cerr << i << ' ' << u << ' ' << fi << ' ' << se << '\n';
            int tmp = i - 1 - u + dpk[u];
            if (tmp < dpk[i]) {
                dpk[i] = tmp;
                last = u;
            }
        }
        for (auto e : seg[i]) {
            int fi = mp[e.first], se = mp[e.second];
            upd(1, 1, sz, fi, se, i);
        }
        if (dpk[i] <= 1 + dp[i - 1]) {
            back[i] = last;
        }
        dp[i] = min(1 + dp[i - 1], dpk[i]);
    }
    cout << dp[n] << '\n';
    int now = n;
    while (back[now] == -1) --now;
    vector<bool> ada(n + 1);
    int cnt = 0;
    while (now > 0) {
        cnt++;
        ada[now] = true;
        now = back[now];
    }
    // assert(cnt == n - dp[n]);
    for (int i = 1; i <= n; i++) {
        if (!ada[i]) cout << i << ' ';
    }
    return;
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