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

const int INF = 2e9;

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<vector<ll>> Q;
    for (int i = 0; i < q; i++) {
        ll l, r, c;
        cin >> l >> r >> c;
        --l, --r;
        Q.emplace_back(vector<ll>{l, r, c});
    }
    sort(Q.begin(), Q.end());
    ll bl = Q[0][0], br = Q[0][1];
    for (int i = 1; i < q; i++) {
        if (Q[i][0] > br) {
            cout << -1 << '\n';
            return;
        }
        br = max(br, Q[i][1]);
    }
    if (bl != 0 || br != n - 1) {
        cout << -1 << '\n';
        return;
    }

    sort(Q.begin(), Q.end(), [&](vector<ll> &q1, vector<ll> &q2) -> bool {
        return q1[2] < q2[2];
    });

    set<pair<int, int>> se;

    const int INF = 2e9;
    ll ans = 0;
    for (int i = 0; i < q; i++) {
        int l = Q[i][0], r = Q[i][1], c = Q[i][2];
        vector<pair<int, int>> rem;
        auto it = se.upper_bound(make_pair(l, INF));
        auto tmp = it;
        if (tmp != se.begin() && (--tmp)->second >= l) {
            --it;
        }
        int cnt = 0;
        int emp = (r - l + 1);
        while (it != se.end()) {
            if (it->first > r) break;
            cnt++;
            rem.emplace_back(*it);
            int x = max(it->first, l);
            int y = min(it->second, r);
            emp -= (y - x + 1);
            ++it;
        }

        ans += 1ll * (emp + cnt) * c;
        for (auto t : rem) se.erase(t);
        se.emplace(l, r);
    }
    cout << ans << '\n';
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