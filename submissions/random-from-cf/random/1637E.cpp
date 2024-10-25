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
    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    map<int, vector<int>> ve;
    vector<int> vals;
    for (auto e : cnt) {
        ve[e.second].push_back(e.first);
    }
    for (auto &e : ve) {
        sort(e.second.begin(), e.second.end());
        reverse(e.second.begin(), e.second.end());
        vals.push_back(e.first);
    }
    set<pair<int, int>> bad;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        bad.emplace(u, v);
        bad.emplace(v, u);
    }

    int sz = vals.size();
    ll ans = 0;
    for (int i = 0; i < sz; i++) {
        for (int j = i; j < sz; j++) {
            if (i == j) {
                int cc = vals[i] + vals[i];
                vector<int> p = ve[vals[i]];
                for (auto pp : p) {
                    for (auto qq : p) {
                        if (pp == qq || bad.count(make_pair(pp, qq)))
                            continue;
                        else {
                            ans = max(ans, 1ll * cc * (pp + qq));
                            break;
                        }
                    }
                }
            } else {
                int cc = vals[i] + vals[j];
                vector<int> p = ve[vals[i]], q = ve[vals[j]];
                if (p.size() > q.size()) p.swap(q);
                for (auto pp : p) {
                    for (auto qq : q) {
                        if (bad.count(make_pair(pp, qq)))
                            continue;
                        else {
                            ans = max(ans, 1ll * cc * (pp + qq));
                            break;
                        }
                    }
                }
            }
            debug(i, j, ans);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}