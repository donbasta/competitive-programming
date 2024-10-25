#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// using ll = __int128;
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

pair<ll, ll> F(pair<ll, ll> X, pair<ll, ll> Y, pair<ll, ll> Z) {
    ll a = (Y.first * Z.second);
    ll b = (Y.second * Z.first);
    ll fpb = __gcd(a, b);
    a /= fpb, b /= fpb;
    ll c = X.first * b + X.second * a;
    ll d = X.second * b;
    fpb = __gcd(c, d);
    c /= fpb, d /= fpb;
    return make_pair(c, d);
}

void el_psy_congroo() {
    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s.push_back(c);
    }

    vector<vector<pair<ll, ll>>> st;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(') {
            vector<pair<ll, ll>> emp;
            st.push_back(emp);
        } else if (c == ')') {
            if (st.empty() || st.back().size() != 3) {
                cout << -1 << '\n';
                return;
            }
            vector<pair<ll, ll>> cur = st.back();
            st.pop_back();
            pair<ll, ll> res = F(cur[0], cur[1], cur[2]);
            if (!st.empty()) {
                st.back().push_back(res);
            } else {
                if (i < n - 1) {
                    cout << -1 << '\n';
                    return;
                } else {
                    cout << res.first << ' ' << res.second << '\n';
                    return;
                }
            }
        } else {
            if (!st.empty()) {
                st.back().push_back(make_pair(c - '0', 1));
            } else {
                cout << -1 << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
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