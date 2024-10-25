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
    ll n, k;
    cin >> n >> k;

    const function<ll(int, int)> get = [&](int a, int b) -> ll {
        ll mask = (1ll << (b + 1)) - (1ll << a);
        return (n & mask) >> a;
    };
    const function<ll(ll, ll)> one_stall = [&](ll M, ll V) -> ll {
        ll lo = 1, hi = 1e18;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll cek = (M / mid);
            // debug(lo, hi, mid);
            if (cek == V) {
                return mid;
            } else if (cek < V) {
                hi = mid - 1;
            } else if (cek > V) {
                lo = mid + 1;
            }
        }
        return -1;
    };

    int ptr = 60;
    ll need = k;
    vector<ll> prices;
    bool ok = false;
    while (ptr >= 0) {
        ll until = -1;
        ll rem = get(0, ptr);
        ll cari = one_stall(rem, need);
        if (cari != -1) {
            prices.push_back(cari);
            break;
        }
        for (int j = ptr; j >= 0; j--) {
            ll nw = get(j, ptr);
            if (nw == need) {
                ok = true;
                prices.push_back(1ll << j);
                break;
            }
            if (nw > need) {
                until = j;
                break;
            }
        }
        if (ok) {
            break;
        } else if (until == -1) {
            cout << "NO" << '\n';
            return;
        } else {
            prices.push_back(1ll << (until + 1));
            need -= get(until + 1, ptr);
            ptr = until;
        }
    }
    cout << "YES" << '\n';
    cout << prices.size() << '\n';
    for (auto p : prices) {
        cout << p << ' ';
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