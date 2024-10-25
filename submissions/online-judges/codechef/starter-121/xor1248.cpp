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
const int B = 60;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    ll ks = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ks ^= ar[i];
    }
    ll ret = ks;
    for (int i = 0; i < n; i++) {
        ks ^= ar[i];
        vector<ll> bit(B);
        for (int j = B - 1; j >= 0; j--) {
            if ((ar[i] >> j) & 1) bit[j]++;
        }
        ll tmp = 0;
        for (int j = B - 1; j >= 0; j--) {
            ll cnt = bit[j];
            ll on = ((ks >> j) & 1);
            if (cnt == 0 && on == 0) {
                continue;
            }
            if ((cnt + on) % 2 == 0) {
                assert(cnt > 0ll);
                if (j > 0) {
                    tmp += (1ll << j);
                    ll rem = ((on & 1) ? cnt : (cnt - 1));
                    bit[j - 1] += 2ll * (rem);
                }
            } else {
                if (j > 0) {
                    ll rem = ((on & 1) ? cnt : (cnt - 1));
                    bit[j - 1] += 2ll * (rem);
                }
                tmp += (1ll << j);
            }
        }
        ret = max(ret, tmp);
        ks ^= ar[i];
    }
    cout << ret << '\n';
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