#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;

using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;

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
    ll q, k;
    cin >> q >> k;

    set<ll> se;
    set<pair<ll, ll>> lmao;
    oset ose;

    while (q--) {
        ll t, x;
        cin >> t >> x;
        if (t == 1) {
            if (se.count(x)) {
                auto p1 = se.upper_bound(x);
                auto p2 = se.lower_bound(x);
                if (p1 != se.end()) {
                    ll R = *p1;
                    if (R - x >= k + 1) {
                        lmao.erase(make_pair(x, R));
                    }
                }
                if (p2 != se.begin()) {
                    auto p3 = se.lower_bound(x);
                    --p3;
                    ll L = *p3;
                    if (x - L >= k + 1) {
                        lmao.erase(make_pair(L, x));
                    }
                }
                if (p1 != se.end() && p2 != se.begin()) {
                    --p2;
                    ll L = *p2, R = *p1;
                    if (R - L >= k + 1) {
                        lmao.emplace(L, R);
                    }
                }
                se.erase(x);
                ose.erase(x);
            } else {
                auto p1 = se.upper_bound(x);
                auto p2 = se.upper_bound(x);
                if (p1 != se.end() && p2 != se.begin()) {
                    auto p3 = se.upper_bound(x);
                    --p3;
                    ll R = *p1, L = *p3;
                    if (R - L >= k + 1) {
                        lmao.erase(make_pair(L, R));
                    }
                }
                if (p1 != se.end()) {
                    ll R = *p1;
                    if (R - x >= k + 1) {
                        lmao.emplace(x, R);
                    }
                }
                if (p2 != se.begin()) {
                    --p2;
                    ll L = *p2;
                    if (x - L >= k + 1) {
                        lmao.emplace(L, x);
                    }
                }
                se.insert(x);
                ose.insert(x);
            }
        } else {
            assert(se.count(x));
            auto p1 = lmao.lower_bound(make_pair(x, -1));
            auto p2 = lmao.lower_bound(make_pair(x, -1));
            ll ans;
            if (p1 != lmao.end() && p2 != lmao.begin()) {
                --p2;
                ll A = p2->second;
                ll B = p1->first;
                // A <= r <= B
                ans = ose.order_of_key(B + 1) - ose.order_of_key(A);
            } else if (p1 != lmao.end() && p2 == lmao.begin()) {
                ll B = p1->first;
                // r <= B
                ans = ose.order_of_key(B + 1);
            } else if (p1 == lmao.end() && p2 != lmao.begin()) {
                --p2;
                ll A = p2->second;
                // A <= r
                ans = (ll)se.size() - ose.order_of_key(A);
            } else {
                assert(lmao.empty());
                ans = se.size();
            }
            cout << ans << '\n';
        }
    }
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