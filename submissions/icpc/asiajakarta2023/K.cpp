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
using vi = vector<ll>;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void FST(vi &a, bool inv) {
    for (int n = (int)a.size(), step = 1; step < n; step *= 2) {
        for (int i = 0; i < n; i += 2 * step)
            for (int j = i; j < i + step; j++) {  // rep(j, i, i + step)
                ll &u = a[j], &v = a[j + step];
                tie(u, v) = make_pair((u + v) % MOD, (u - v) % MOD);
            }
    }
    if (inv)
        for (ll &x : a) x = (x * fpow((int)a.size(), MOD - 2)) % MOD;
    // for (ll &x : a) x /= (int)a.size();
}
vi conv(vi a, vi b) {
    FST(a, 0);
    FST(b, 0);
    for (int i = 0; i < (int)a.size(); i++) a[i] = (a[i] * b[i]) % MOD;
    FST(a, 1);
    return a;
}
vi extend(vi a, vi b) {
    for (auto bb : b) a.push_back(bb);
    return a;
}

const int M = 1e5;
ll fc[M + 1], ifc[M + 1];

void init() {
    fc[0] = 1;
    for (int i = 1; i <= M; i++) fc[i] = (fc[i - 1] * i) % MOD;
    ifc[M] = fpow(fc[M], MOD - 2);
    for (int i = M - 1; i >= 0; i--) ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
}

ll cb(ll a, ll b) {
    if (a < b || a < 0 || b < 0) return 0;
    ll ret = (fc[a] * ifc[b]) % MOD;
    return (ret * ifc[a - b]) % MOD;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    ll mx = -1;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        mx = max(mx, ar[i]);
    }

    int A = 1;
    while (A <= mx) A <<= 1;
    vector<vector<ll>> coef(A, vector<ll>(2));
    vector<ll> cnt(A);
    for (int i = 0; i < n; i++) cnt[ar[i]]++;

    for (int i = 0; i < A; i++) {
        ll pw2 = 1;
        for (int j = 0; j <= cnt[i]; j++) {
            coef[i][j & 1] = (coef[i][j & 1] + pw2 * cb(cnt[i], j)) % MOD;
            pw2 = (pw2 * 2) % MOD;
        }
    }
    const function<pair<vi, vi>(int, int)> go = [&](int L, int R) -> pair<vi, vi> {
        if (L == R) {
            return make_pair(vector<ll>{coef[L][0]}, vector<ll>{coef[L][1]});
        }
        int mid = (L + R) >> 1;
        pair<vi, vi> vL = go(L, mid);
        pair<vi, vi> vR = go(mid + 1, R);
        vi A = conv(vL.first, vR.first);
        vi B = conv(vL.first, vR.second);
        vi C = conv(vL.second, vR.first);
        vi D = conv(vL.second, vR.second);
        return make_pair(extend(A, D), extend(C, B));
    };

    pair<vi, vi> ret = go(0, A - 1);
    ll ans = ((ret.first[0] + ret.second[0]) % MOD);
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}