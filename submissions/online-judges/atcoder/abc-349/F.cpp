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
const ll MOD = 998244353;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll pow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

void el_psy_congroo() {
    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (m % x != 0) continue;
        mp[x]++;
    }
    map<ll, ll> fp;
    ll tmp = m;
    if (tmp % 2 == 0) {
        int pw = 0;
        while (tmp % 2 == 0) {
            tmp /= 2, pw++;
        }
        fp[2] = pw;
    }
    for (ll i = 3; i * i <= tmp; i += 2) {
        if (tmp % i == 0) {
            int pw = 0;
            while (tmp % i == 0) {
                tmp /= i, pw++;
            }
            fp[i] = pw;
        }
    }
    if (tmp > 1) fp[tmp] = 1;
    // debug(mp, fp);
    int cnt = fp.size();
    vector<ll> ie(1 << cnt);
    vector<ll> primes;
    for (auto p : fp) primes.push_back(p.first);

    for (auto dv : mp) {
        ll lol = 0;
        for (int i = 0; i < cnt; i++) {
            if (dv.first % pow(primes[i], fp[primes[i]]) != 0) {
                lol ^= (1ll << i);
            }
        }
        ll count = dv.second;
        for (int sm = lol; sm; sm = (sm - 1) & lol) {
            ie[sm] = (ie[sm] + count) % (MOD - 1);
        }
        ie[0] = (ie[0] + count) % (MOD - 1);
    }

    // debug(ie);

    ll ans = 0;
    for (int i = 0; i < (1 << cnt); i++) {
        ll xx = fpow(2, ie[i]) - 1;
        if (__builtin_popcount(i) % 2 == 0) {
            ans = (ans + xx) % MOD;
        } else {
            ans = (ans - xx) % MOD;
        }
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;
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