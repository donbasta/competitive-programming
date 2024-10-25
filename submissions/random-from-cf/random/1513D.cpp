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
    ll n, p;
    cin >> n >> p;
    vector<ll> ar(n);
    vector<pair<ll, ll>> ve;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ve.emplace_back(ar[i], i);
    }
    vector<bool> vis(n - 1);
    sort(ve.begin(), ve.end());
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (ve[i].first > p) {
            break;
        }
        int pos = ve[i].second;
        int tmp = pos;
        while (tmp > 0 && !vis[tmp - 1]) {
            if (ar[tmp - 1] % ve[i].first == 0) {
                sum += ve[i].first;
                vis[tmp - 1] = true;
                --tmp;
            } else {
                break;
            }
        }
        tmp = pos;
        while (tmp < n - 1 && !vis[tmp]) {
            if (ar[tmp + 1] % ve[i].first == 0) {
                sum += ve[i].first;
                vis[tmp] = true;
                ++tmp;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (!vis[i]) sum += p;
    }
    cout << sum << '\n';
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