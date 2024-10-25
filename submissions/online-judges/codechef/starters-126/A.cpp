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
const ll MOD = 1e9 + 9;
const ll MOD2 = 1e9 + 7;
const ll B = 37;
const ll B2 = 31;

void el_psy_congroo() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<pair<ll, ll>> se;

    vector<ll> pw(n), pw2(n);
    pw[0] = pw2[0] = 1;
    for (int i = 1; i < n; i++) {
        pw[i] = (pw[i - 1] * B) % MOD;
        pw2[i] = (pw2[i - 1] * B2) % MOD2;
    }

    ll hsh = 0, hsh2 = 0;
    for (int i = 0; i < n; i++) {
        hsh = (hsh + pw[i] * (s[i] - 'a' + 1)) % MOD;
        hsh2 = (hsh2 + pw2[i] * (s[i] - 'a' + 1)) % MOD2;
    }
    for (int i = 0; i + 2 < n; i++) {
        ll tmp = hsh;
        for (int j = i; j <= i + 2; j++) {
            tmp = (tmp - pw[j] * (s[j] - 'a' + 1)) % MOD;
        }
        if (tmp < 0) tmp += MOD;
        tmp = (tmp + pw[i + 2] * (s[i] - 'a' + 1)) % MOD;
        tmp = (tmp + pw[i] * (s[i + 1] - 'a' + 1)) % MOD;
        tmp = (tmp + pw[i + 1] * (s[i + 2] - 'a' + 1)) % MOD;

        ll tmp2 = hsh2;
        for (int j = i; j <= i + 2; j++) {
            tmp2 = (tmp2 - pw2[j] * (s[j] - 'a' + 1)) % MOD2;
        }
        if (tmp2 < 0) tmp2 += MOD2;
        tmp2 = (tmp2 + pw2[i + 2] * (s[i] - 'a' + 1)) % MOD2;
        tmp2 = (tmp2 + pw2[i] * (s[i + 1] - 'a' + 1)) % MOD2;
        tmp2 = (tmp2 + pw2[i + 1] * (s[i + 2] - 'a' + 1)) % MOD2;

        se.emplace(tmp, tmp2);
    }
    cout << se.size() << '\n';
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