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
    int n;
    cin >> n;
    vector<ll> ar(n);
    const int M = 1e6;
    vector<ll> pref(3 * M + 1);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        pref[ar[i]]++;
    }
    for (int i = 1; i <= 3 * M; i++) {
        pref[i] += pref[i - 1];
    }

    sort(ar.begin(), ar.end());
    const int B = 1000;
    vector<ll> buf(B + 5, -1);

    ll ans = 0;
    ll prv = 1;
    for (int i = 0; i < n; i++) {
        ll tmp = 0;
        if (ar[i] > B) {
            if (ar[i] == ar[i - 1])
                prv++;
            else
                prv = 1;
            tmp -= prv;
            ll T = M / ar[i];
            for (int j = 1; j <= T; j++) {
                tmp -= pref[ar[i] * j - 1];
            }
            tmp += T * pref[ar[i] * (T + 1) - 1];
        } else {
            if (buf[ar[i]] != -1) {
                --buf[ar[i]];
                tmp = buf[ar[i]];
            } else {
                buf[ar[i]] = 0;
                for (int j = i + 1; j < n; j++) {
                    buf[ar[i]] += (ar[j] / ar[i]);
                }
                tmp = buf[ar[i]];
            }
        }
        // debug(i, ar[i], tmp);
        ans += tmp;
    }

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