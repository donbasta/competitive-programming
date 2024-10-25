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
const ll MOD = 1e9 + 7;
const ll i2 = (MOD + 1) / 2;

struct BIT {
    vector<ll> tree;
    int n;
    BIT(int n) : n(n), tree(n + 1) {}
    void upd(int v, ll val) {
        v++;
        while (v <= n) tree[v] += val, v += v & -v;
    }
    ll get(int v) {
        v++;
        int ret = 0;
        while (v) ret += tree[v], v -= v & -v;
        return ret;
    }
    ll get(int a, int b) {
        return get(b) - get(a - 1);
    }
};

void el_psy_congroo() {
    string s;
    ll n;
    cin >> s >> n;
    int m = s.length();
    ll inv = 0;

    vector<ll> cnt(26), pre(26);
    for (auto c : s) cnt[c - 'a']++;
    for (int i = 0; i < 26; i++) pre[i] = cnt[i] + (i ? pre[i - 1] : 0);

    BIT bit(26);
    for (int i = 0; i < m; i++) {
        int cur = s[i] - 'a';
        inv = (inv + bit.get(cur + 1, 25)) % MOD;
        bit.upd(cur, 1);
    }

    n %= MOD;
    ll ans = (inv * n) % MOD;
    ll lol = 0;
    for (int i = 0; i < m; i++) {
        int cur = s[i] - 'a';
        lol = (lol + (cur ? pre[cur - 1] : 0)) % MOD;
    }
    lol = (lol * n) % MOD;
    lol = (lol * (n - 1)) % MOD;
    lol = (lol * i2) % MOD;
    ans = (ans + lol) % MOD;
    if (ans < 0) ans += MOD;
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