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
    ll n, d;
    cin >> n >> d;
    vector<ll> ar(n);
    ll N = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        N += ar[i];
    }
    if (d == 1) {
        cout << (N * (N - 1) / 2) << '\n';
        return;
    }
    if (d == 2) {
        ll ans = (N * (N - 1)) / 2;
        for (int i = 0; i < n; i++) {
            ans -= (ar[i] * (ar[i] - 1)) / 2;
        }
        cout << ans << '\n';
        return;
    }
    sort(ar.begin(), ar.end());
    ll itr = 0, ans = 0, prv = 0;
    while (itr < n) {
        ll sisa = n - itr;
        ll c2 = (sisa * (sisa - 1)) / 2;
        ans += c2 * (ar[itr] - prv);
        prv = ar[itr];
        itr++;
        while (itr < n && ar[itr] == prv) itr++;
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