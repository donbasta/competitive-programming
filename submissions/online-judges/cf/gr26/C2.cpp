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

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<ll> mx(n), mn(n);
    vector<ll> pmx(n), pmn(n);
    ll cur_pmx = 1, cur_pmn = 1;
    ll cur_mx = 0, cur_mn = 0;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ll a = cur_mx + ar[i], b = abs(cur_mx + ar[i]);
        ll c = cur_mn + ar[i], d = abs(cur_mn + ar[i]);
        ll tmp_mx = cur_mx, tmp_mn = cur_mn;

        cur_mx = max(a, max(b, max(c, d)));
        cur_mn = min(a, min(b, min(c, d)));

        ll ABmx = 0, CDmx = 0, ABmn = 0, CDmn = 0;
        if (a == cur_mx) ABmx++;
        if (b == cur_mx) ABmx++;
        if (c == cur_mx) CDmx++;
        if (d == cur_mx) CDmx++;
        if (a == cur_mn) ABmn++;
        if (b == cur_mn) ABmn++;
        if (c == cur_mn) CDmn++;
        if (d == cur_mn) CDmn++;

        if (tmp_mx != tmp_mn) {
            pmx[i] = (cur_pmx * ABmx + cur_pmn * CDmx) % MOD;
            pmn[i] = (cur_pmx * ABmn + cur_pmn * CDmn) % MOD;
        } else {
            pmx[i] = (cur_pmx * ABmx) % MOD;
            pmn[i] = (cur_pmx * ABmn) % MOD;
        }

        cur_pmx = pmx[i], cur_pmn = pmn[i];
        mx[i] = cur_mx;
        mn[i] = cur_mn;
    }

    cout << pmx.back() << '\n';
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