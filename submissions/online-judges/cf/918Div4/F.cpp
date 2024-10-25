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
#define debug(...) 69
#endif

const int INF = 2e9;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1) {}
    void upd(int idx, int val) {
        while (idx <= n) {
            tree[idx] += val, idx += idx & -idx;
        }
    }
    int get(int idx) {
        int ret = 0;
        while (idx) {
            ret += tree[idx], idx -= idx & -idx;
        }
        return ret;
    }
    int get(int x, int y) {
        return get(y) - get(x - 1);
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<pair<int, int>> ve(n);
    vector<int> comp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ve[i] = make_pair(a, b);
        comp.push_back(a);
        comp.push_back(b);
    }
    sort(comp.begin(), comp.end());
    map<int, int> mp;
    for (int i = 0; i < 2 * n; i++) {
        mp[comp[i]] = i + 1;
    }
    debug(mp);
    for (int i = 0; i < n; i++) {
        ve[i] = make_pair(mp[ve[i].first], mp[ve[i].second]);
    }
    sort(ve.begin(), ve.end(), [&](pair<int, int> x, pair<int, int> y) -> bool {
        return x.second < y.second;
    });
    BIT bit(2 * n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += bit.get(ve[i].first, ve[i].second - 1);
        bit.upd(ve[i].first, 1);
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