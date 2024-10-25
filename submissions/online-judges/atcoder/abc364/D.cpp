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
    int n, q;
    cin >> n >> q;
    vector<ll> A(n), B(q), K(q), idx(q);
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());

    for (int i = 0; i < q; i++) {
        cin >> B[i] >> K[i];
    }
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) -> bool {
        return B[i] < B[j];
    });

    vector<ll> L, R;
    for (int i = 0; i < n; i++) {
        if (A[i] < B[idx[0]])
            L.push_back(B[idx[0]] - A[i]);
        else
            R.push_back(A[i] - B[idx[0]]);
    }

    const ll INF = 2e9;
    for (int i = 0; i < q; i++) {
        ll lo = 0, hi = INF, piv = -1;
        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;
            ll a = upper_bound(L.begin(), L.end(), mid + offset_L) - L.begin();
            ll b = upper_bound(R.begin(), R.end(), mid + offset_R) - R.begin();
            if ((a + b) >= K[idx[i]]) {
                piv = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        ans[idx[i]] = piv;
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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