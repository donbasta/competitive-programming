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

struct DS {
    int len = 0;
    ll sum_L = 0, sum_R = 0;
    multiset<ll> L, R;
    DS() {}
    void erase(ll x) {  // make sure x ada
        len--;
        if (x >= *R.begin()) {
            R.erase(R.find(x));
            sum_R -= x;
            if (L.size() > R.size()) {
                ll biggest_left = *(--L.end());
                L.erase(L.find(biggest_left));
                sum_L -= biggest_left;
                R.insert(biggest_left);
                sum_R += biggest_left;
            }
        } else {
            L.erase(L.find(x));
            sum_L -= x;
            if (R.size() - L.size() > 1) {
                ll smallest_right = *R.begin();
                L.insert(smallest_right);
                sum_L += smallest_right;
                R.erase(R.find(smallest_right));
                sum_R -= smallest_right;
            }
        }
    }
    void insert(ll x) {
        len++;
        if (R.empty()) {
            sum_R += x;
            R.insert(x);
        } else if (x < *R.begin()) {
            sum_L += x;
            L.insert(x);
            if (L.size() > R.size()) {
                ll biggest_left = *(--L.end());
                L.erase(L.find(biggest_left));
                sum_L -= biggest_left;
                R.insert(biggest_left);
                sum_R += biggest_left;
            }
        } else if (x >= *R.begin()) {
            sum_R += x;
            R.insert(x);
            if (R.size() - L.size() > 1) {
                ll smallest_right = *R.begin();
                L.insert(smallest_right);
                sum_L += smallest_right;
                R.erase(R.find(smallest_right));
                sum_R -= smallest_right;
            }
        }
    }
    ll get() {
        ll ret = sum_R - sum_L;
        if (len & 1) ret -= *R.begin();
        return ret;
    }
} ds;

void el_psy_congroo() {
    ll n, k;
    cin >> n >> k;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];
    for (int i = 0; i < n; i++) ar[i] -= i;

    int r = 0;
    int ans = 1;
    ds.insert(ar[0]);
    for (int i = 0; i < n; i++) {
        while (r < n - 1) {
            ds.insert(ar[r + 1]);
            if (ds.get() <= k) {
                r++;
                ans = max(ans, r - i + 1);
            } else {
                ds.erase(ar[r + 1]);
                break;
            }
        }
        ds.erase(ar[i]);
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