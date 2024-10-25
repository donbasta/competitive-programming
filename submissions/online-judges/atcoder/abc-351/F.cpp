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

struct BIT {
    int n;
    vector<ll> tree;
    BIT(int n) : n(n), tree(n + 1) {}
    void upd(int v, ll val) {
        v++;
        while (v <= n) {
            tree[v] += val;
            v += v & -v;
        }
    }
    ll get(int v) {
        v++;
        ll ret = 0;
        while (v) {
            ret += tree[v];
            v -= v & -v;
        }
        return ret;
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<pair<ll, int>> ve;
    for (int i = 0; i < n; i++) {
        ve.emplace_back(ar[i], i);
    }
    sort(ve.begin(), ve.end());
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        idx[ve[i].second] = i;
    }

    BIT bit1(n), bit2(n);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll cnt = bit1.get(idx[i] - 1);
        ll sum = bit2.get(idx[i] - 1);
        ll tmp = ar[i] * cnt - sum;
        ans += tmp;
        bit1.upd(idx[i], 1);
        bit2.upd(idx[i], ar[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}