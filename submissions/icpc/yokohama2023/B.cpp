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

using pll = pair<ll, ll>;

bool gte(pll a, pll b) {
    return a.first * b.second >= a.second * b.first;
}

pll F(ll a, ll b, ll p, ll q) {
    ll x = p * a - b * q, y = q;
    ll fpb = __gcd(abs(x), abs(y));
    x /= fpb, y /= fpb;
    return make_pair(x, y);
}

void el_psy_congroo() {
    ll n, c, p, q;
    cin >> n >> c >> p >> q;
    ll fpb = __gcd(p, q);
    p /= fpb, q /= fpb;
    string s;
    cin >> s;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[i + 1] = cnt[i] + (s[i] == 'Y');
    }

    int cur = 1, rank = 0;
    vector<pll> mx(n + 1);
    mx[0] = make_pair(0, 1);
    for (int i = 1; i <= n; i++) {
        pll cur_val = F(i, cnt[i], p, q);
        if (i - cur + 1 >= c) {
            if (gte(mx[i - c], cur_val)) {
                rank++;
                cur = i + 1;
                mx[i] = cur_val;
            } else {
                mx[i] = mx[i - 1];
                if (gte(cur_val, mx[i - 1])) mx[i] = cur_val;
            }
        } else {
            mx[i] = mx[i - 1];
            if (gte(cur_val, mx[i - 1])) mx[i] = cur_val;
        }
    }
    cout << rank << '\n';
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