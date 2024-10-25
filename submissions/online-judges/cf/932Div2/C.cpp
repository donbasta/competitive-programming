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
    ll n, l;
    cin >> n >> l;
    vector<ll> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        if (B[a] == B[b]) return A[a] < A[b];
        return B[a] < B[b];
    });
    int L = 1, R = n, ans = 0;
    while (L <= R) {
        int mid = (L + R) >> 1;
        bool ok = false;
        for (int i = 0; i + mid - 1 < n; i++) {
            multiset<ll> ms;
            ll smallest_mid = 0;
            ll tmp;
            for (int j = i; j <= i + mid - 1; j++) {
                ms.insert(-A[idx[j]]);
                smallest_mid += A[idx[j]];
            }
            if (smallest_mid + B[idx[i + mid - 1]] - B[idx[i]] <= l) {
                ok = true;
                break;
            }
            for (int j = i + mid; j < n; j++) {
                if (A[idx[j]] < -(*ms.begin())) {
                    smallest_mid += A[idx[j]] + *ms.begin();
                    ms.erase(ms.begin());
                    ms.insert(-A[idx[j]]);
                }
                if (smallest_mid + B[idx[j]] - B[idx[i]] <= l) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) {
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
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