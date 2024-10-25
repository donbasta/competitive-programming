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

void el_psy_congroo() {
    ll n, x;
    cin >> n >> x;
    vector<ll> ve(n);
    for (int i = 0; i < n; i++) cin >> ve[i];
    vector<ll> dx;
    for (int i = 1; i * i <= x; i++) {
        if (x % i != 0) continue;
        dx.push_back(i);
        if (i * i != x) dx.push_back(x / i);
    }
    sort(dx.begin(), dx.end());
    reverse(dx.begin(), dx.end());

    map<ll, bool> tmp;
    tmp[1] = true;
    if (x % ve[0] == 0) {
        tmp[ve[0]] = true;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (x % ve[i] != 0) continue;
        if (tmp.find(x / ve[i]) != tmp.end()) {
            tmp.clear();
            ans++;
            tmp[1] = true;
            tmp[ve[i]] = true;
        } else {
            for (auto dd : dx) {
                if ((tmp.find(dd) != tmp.end()) && (x % (dd * ve[i]) == 0)) {
                    // debug(dd);
                    tmp[dd * ve[i]] = true;
                }
            }
        }
        // debug(i, tmp);
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