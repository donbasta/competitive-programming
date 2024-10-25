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

const ll INF = 2e18;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;

    vector<vector<vector<ll>>> prv(n);
    for (int i = 0; i < m; i++) {
        ll l, d, k, c, a, b;
        cin >> l >> d >> k >> c >> a >> b;
        --a, --b;
        prv[b].push_back(vector<ll>{a, l, d, k, c});
    }
    vector<ll> last(n, -1);
    last[n - 1] = INF;
    priority_queue<pair<ll, ll>> pq;
    pq.emplace(INF, n - 1);
    while (!pq.empty()) {
        ll latest = pq.top().first, cur = pq.top().second;
        pq.pop();
        if (latest != last[cur]) continue;
        for (auto ve : prv[cur]) {
            ll prv_city = ve[0];
            ll L = ve[1], D = ve[2], K = ve[3], C = ve[4];
            // dari c kapan terakhir bisa berangkat
            // biar nyampe ke cur <= latest
            // lihat koneksi c ke cur: [l+c, l+d+c, ..., l+(k-1)d+c]
            if (latest - L - C < 0) continue;
            ll idx = ((latest - L - C) / D);
            idx = min(idx, K - 1);
            ll tmp = L + idx * D + C;
            if ((tmp - C) > last[prv_city]) {
                last[prv_city] = (tmp - C);
                pq.emplace(tmp - C, prv_city);
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (last[i] == -1) {
            cout << "Unreachable" << '\n';
            continue;
        }
        cout << last[i] << '\n';
    }
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