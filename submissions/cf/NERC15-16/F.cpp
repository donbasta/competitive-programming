#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = LLONG_MAX;

inline ll sq(ll x) { return x * x; }
inline ld sq_dis (pair<ll, ll> pa, pair<ll, ll> pb) { return sqrtl(sq(pa.first - pb.first) + sq(pa.second - pb.second)); }

void ans(pair<ll, ll> dob_ans) {
    ll x = dob_ans.first;
    ll y = dob_ans.second;
    cout << x/2;
    if (x & 1) cout << ".5";
    cout << " ";
    cout << y/2;
    if (y & 1) cout << ".5";
    cout << '\n';
}

pair<ll, ll> dob_mid(pair<ll, ll> pa, pair<ll, ll> pb) {
    return make_pair(pa.first + pb.first, pa.second + pb.second);
}

vector<pair<ll, ll>> p;
vector<ld> le, ri;
ll n, w;

void run_le () {
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        le[i] = (ld)p[i].first;
    }
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && (v == -1 || le[j] < le[v])) {
                v = j;
            }
        }
        if (v == -1) break;
        vis[v] = 1;
        for (int j = 0; j < n; j++) {
            if (j == v) continue;
            ld A = sq_dis(p[v], p[j]);
            if (le[j] > max(A, le[v])) {
                le[j] = max(A, le[v]);
            }
        }
    }
}

void run_ri () {
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        ri[i] = (ld)(w - p[i].first);
    }
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && (v == -1 || ri[j] < ri[v])) {
                v = j;
            }
        }
        if (v == -1) break;
        vis[v] = 1;
        for (int j = 0; j < n; j++) {
            if (j == v) continue;
            ld A = sq_dis(p[v], p[j]);
            if (ri[j] > max(A, ri[v])) {
                ri[j] = max(A, ri[v]);
            }
        }
    }
}

void solve() {
    cin >> w >> n;

    if (n == 0) {
        ans(make_pair(w, 0));
        return;
    }

    p.resize(n), le.resize(n), ri.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    if (n == 1) {
        ll dob_absis;
        if (p[0].first * 2 >= w) {
            dob_absis = p[0].first;
        } else {
            dob_absis = p[0].first + w;
        }
        ans(make_pair(dob_absis, p[0].second * 2));
        return;
    }

    run_le();
    run_ri();

    ld mx = INF;
    for (int i = 0; i < n; i++) {
        mx = min(mx, max(le[i], ri[i]));
    }

    pair<ll, ll> doble_ans = {p[0].first+p[0].first, p[0].second+p[0].second};
    for (int i = 0; i < n; i++) {
        ld A2 = (ld)p[i].first / 2.0;
        if (A2 >= ri[i] && A2 <= mx) {
            mx = A2, doble_ans = dob_mid(p[i], make_pair(0, p[i].second));
        }
        if (A2 <= ri[i] && ri[i] <= le[i] && ri[i] <= mx) {
            mx = ri[i], doble_ans = dob_mid(p[i], make_pair(0, p[i].second));
        }
        A2 = (ld)(w - p[i].first) / 2.0;
        if (A2 >= le[i] && A2 <= mx) {
            mx = A2, doble_ans = dob_mid(p[i], make_pair(w, p[i].second));
        }
        if (A2 <= le[i] && le[i] <= ri[i] && le[i] <= mx) {
            mx = le[i], doble_ans = dob_mid(p[i], make_pair(w, p[i].second));
        }
        for (int j = i + 1; j < n; j++) {
            ld A = sq_dis(p[i], p[j]);
            ld il, ir, jl, jr;
            il = le[i];
            ir = ri[i];
            jl = le[j];
            jr = ri[j];
            ld A4 = A / 2.0;
            // cerr << A << ' ' << A4 << '\n';
            if (A4 >= max(il, jr) && A4 <= mx) {
                mx = A4;
                doble_ans = dob_mid(p[i], p[j]);
            }
            if (A4 >= max(jl, ir) && A4 <= mx) {
                mx = A4;
                doble_ans = dob_mid(p[i], p[j]);
            }
            if (A4 < max(il, jr) && (max(il, jr)) <= mx) {
                mx = max(il, jr);
                doble_ans = dob_mid(p[i], p[j]);
            }
            if (A4 < max(jl, ir) && (max(jl, ir)) <= mx) {
                mx = max(jl, ir);
                doble_ans = dob_mid(p[i], p[j]);
            }
            // cerr << i << ' ' << j << ' ' << mx << '\n';
        }
    }

    // cerr << "mx " << mx << '\n';
    ans(doble_ans);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(12);

    freopen("froggy.in", "r", stdin);
    freopen("froggy.out", "w", stdout);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}