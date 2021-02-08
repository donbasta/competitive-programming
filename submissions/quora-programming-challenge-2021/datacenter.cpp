#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;
const int MX = 2e9;
const int N = 5e5 + 5;

#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair

ll n;
vector<pll> loc, ve;
vector<pll> t1[4 * N], t2[4 * N];
vector<ll> s1[4 * N], s2[4 * N]; 

void build(int v, int s, int e) {
    if (s == e) {
        t1[v] = vector<pll>(1, mp(loc[e].se, loc[e].se + loc[e].fi));
        t2[v] = vector<pll>(1, mp(loc[e].se, loc[e].fi - loc[e].se));
        s1[v] = vector<ll>(1, loc[e].se + loc[e].fi);
        s2[v] = vector<ll>(1, loc[e].fi - loc[e].se);
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    merge(t1[v << 1].begin(), t1[v << 1].end(), t1[v << 1 | 1].begin(), t1[v << 1 | 1].end(), back_inserter(t1[v]));
    for (auto& e : t1[v]) s1[v].emplace_back(e.se);
    for (int i = 1; i < (int)s1[v].size(); i++) { s1[v][i] += s1[v][i - 1]; }
    for (auto& e : t2[v]) s2[v].emplace_back(e.se);
    for (int i = 1; i < (int)s2[v].size(); i++) { s2[v][i] += s2[v][i - 1]; }
}

ll getCount(int v, int s, int e, int l, int r, int val) {
    if(l > e || r < s || l > r) {
        return 0;
    } else if (l <= s && r >= e) {
        int pos = lower_bound(t1[v].begin(), t1[v].end(), mp(val, -MX)) - t1[v].begin();
        return (int)t1[v].size() - pos;
    } else {
        int mid = (s + e) >> 1;
        return getCount(v << 1, s, mid, l, r, val) + getCount(v << 1 | 1, mid + 1, e, l, r, val);
    }
}

ll getCoor(int v, int s, int e, int l, int r, int val, bool sum) {
    if(l > e || r < s || l > r) {
        return 0;
    } else if (l <= s && r >= e) {
        if (sum) {
            int pos = lower_bound(t1[v].begin(), t1[v].end(), val) - t1[v].begin();
            int sz = (int)t1[v].size();
            return s1[v][sz - 1] - (pos > 0 ? s1[v][pos - 1] : 0);
        } else {
            int pos = lower_bound(t2[v].begin(), t2[v].end(), val) - t2[v].begin();
            int sz = (int)t2[v].size();
            return s2[v][sz - 1] - (pos > 0 ? s2[v][pos - 1] : 0);
        }
    } else {
        int mid = (s + e) >> 1;
        return getCoor(v << 1, s, mid, l, r, val, sum) + getCoor(v << 1 | 1, mid + 1, e, l, r, val, sum);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        loc.emplace_back(x + y, y - x);
        ve.emplace_back(x + y, y - x);
    }
    sort(loc.begin(), loc.end());
    build(1, 0, n - 1);

    ll ans = INF, idx = -1;
    for (int i = 0; i < n; i++) {
        int p, q;
        ll a = ve[i].first, b = ve[i].second;
        ll X = a + b;
        ll Y = a - b;
        ll A, B, C, D, AA, BB, CC, DD;
        //find sum (fi + se) yg fi >= a && se >= b = AA
        p = lower_bound(loc.begin(), loc.end(), mp(a, -MX)) - ve.begin();
        q = upper_bound(loc.begin(), loc.end(), mp(a, MX)) - ve.begin();
        AA = getCoor(1, 0, n - 1, p, n - 1, b, 1);
        //hitung ada berapa = A
        A = getCount(1, 0, n - 1, p, n - 1, b);
        //find sum (fi + se) yg fi <= a && se <= b = BB
        BB = getCoor(1, 0, n - 1, 0, n - 1, 1, 1) - getCoor(1, 0, n - 1, 0, n - 1, b + 1, 1) - getCoor(1, 0, n - 1, q, n - 1, 1, 1) + getCoor(1, 0, n - 1, q, n - 1, b + 1, 1);
        //hitung ada berapa = B
        BB = n - getCount(1, 0, n - 1, 0, n - 1, b + 1) - getCount(1, 0, n - 1, q, n - 1, 1) + getCount(1, 0, n - 1, q, n - 1, b + 1);
        //find sum (fi - se) yg fi < a && se > b = CC
        CC = getCoor(1, 0, n - 1, 0, n - 1, b + 1, 0) - getCoor(1, 0, n - 1, q, n - 1, b + 1, 0);
        //hitung ada berapa = C
        C = getCount(1, 0, n - 1, 0, n - 1, b + 1) - getCount(1, 0, n - 1, q, n - 1, b + 1);
        //find sum (fi - se) yg fi > a && se < b = DD
        DD = getCoor(1, 0, n - 1, q, n - 1, 1, 0) - getCoor(1, 0, n - 1, q, n - 1, b, 0);
        //hitung ada berapa = D
        D = getCount(1, 0, n - 1, q, n - 1, 1) - getCount(1, 0, n - 1, q, n - 1, b);
        ll tmp = (AA - A * X) + (B * X - BB) + (C * Y - CC) + (DD - D * Y);
        assert(tmp % 2 == 0);
        tmp /= 2;
        if (tmp < ans) {
            idx = i;
            ans = tmp;
        }
    }
    cout << idx + 1 << '\n';
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