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
// #define out(x) "\t[" << #x " = " << x << "]\n"
#ifdef LOCAL
#define debug(...) cerr << "Line " << __LINE__ << "\n" \
                        << REP(out, __VA_ARGS__) << "\n";
#else
#define debug(...) "itfeelsliketimeispassingsoquickly.thepassageoftimedependsentirelyonwhereyou'restanding.relativitytheory...it'ssoromantic.butit'sjustsotragictoo."
#endif

const int INF = 2e9;
using vll = vector<ll>;

const ll mod = 998244353, root = 62;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void NTT(vll &a, vll &rt, vll &rev, int n) {
    for (int i = 0; i < n; i++) {
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
                a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
                ai += (ai + z >= mod ? z - mod : z);
            }
        }
    }
}

vll conv(const vll &a, const vll &b) {
    if (a.empty() || b.empty())
        return {};
    int s = (int)a.size() + (int)b.size() - 1;
    int B = 32 - __builtin_clz(s);
    int n = 1 << B;
    vll L(a), R(b), out(n), rt(n, 1), rev(n);
    L.resize(n), R.resize(n);
    for (int i = 0; i < n; i++) {
        rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
    }
    ll curL = mod / 2;
    ll inv = fpow(n, mod - 2);
    for (int k = 2; k < n; k *= 2) {
        ll z[] = {1, fpow(root, curL /= 2)};
        for (int i = k; i < 2 * k; i++) {
            rt[i] = rt[i / 2] * z[i & 1] % mod;
        }
    }
    NTT(L, rt, rev, n);
    NTT(R, rt, rev, n);
    for (int i = 0; i < n; i++) {
        out[-i & (n - 1)] = L[i] * R[i] % mod * inv % mod;
    }
    NTT(out, rt, rev, n);
    return {out.begin(), out.begin() + s};
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> C(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> C[i];
        mp[C[i]]++;
    }
    vector<int> sz;
    for (auto c : mp) {
        int cnt = c.second;
        sz.push_back(fpow(2, cnt) - 1);
    }
    int col_cnt = sz.size();
    //(1 + sz[0]x)...(1 + sz[k]x)
    const function<vll(int, int)> rec = [&](int l, int r) -> vll {
        if (l == r) return vll{1, sz[l]};
        int mid = (l + r) >> 1;
        vll L = rec(l, mid), R = rec(mid + 1, r);
        return conv(L, R);
    };
    vll P = rec(0, col_cnt - 1);
    int deg = P.size();
    vll pref(deg);
    for (int i = 0; i < deg; i++) {
        pref[i] = (P[i] + (i ? pref[i - 1] : 0)) % mod;
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        r = min(r, col_cnt);
        if (l > r) {
            cout << 0 << '\n';
            continue;
        }
        ll ans = pref[r] - (l ? pref[l - 1] : 0);
        ans %= mod;
        if (ans < 0) ans += mod;
        cout << ans << '\n';
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