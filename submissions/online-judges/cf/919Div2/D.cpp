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

const ll INF = 2e18;

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<pair<ll, int>> lens;
    vector<int> X(n);
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        int b, x;
        cin >> b >> x;
        X[i] = x;
        if (b == 1) {
            cur++;
        } else if (b == 2) {
            if (cur > INF / (x + 1)) {
                cur = INF;
            } else {
                cur = (cur * (x + 1));
            }
        }
        lens.emplace_back(cur, b);
    }

    while (q--) {
        ll k;
        cin >> k;
        --k;
        while (true) {
            int p = lower_bound(lens.begin(), lens.end(), make_pair(k + 1, -1)) - lens.begin();
            if (lens[p].first == (k + 1) && lens[p].second == 1) {
                cout << X[p] << ' ';
                break;
            } else {
                assert(lens[p].second == 2);
                ll prv = lens[p - 1].first;
                k = (k % prv);
            }
        }
    }
    cout << '\n';
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