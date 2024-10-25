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
    int m;
    cin >> m;
    vector<ll> A(m), B(m);
    for (int i = 0; i < m; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];

    ll dA = accumulate(A.begin(), A.end(), 0ll);
    ll dB = accumulate(B.begin(), B.end(), 0ll);
    if (dA < dB)
        A[0] += (dB - dA);
    else if (dB < dA)
        B[0] += (dA - dB);

    // debug(A, B);

    const function<ll(vector<ll>, vector<ll>)> go = [&](vector<ll> P, vector<ll> Q) -> ll {
        queue<pair<ll, ll>> rem;
        ll ret = 0;

        vector<ll> ta = P, tb = Q;
        // debug(ta, tb);

        bool ada_start_carry = false;
        ll lmao = 0, tmp = 0;
        for (int i = 0; i < m; i++) {
            if (tb[m - 1 - i] > 0) {
                rem.emplace(tb[m - 1 - i], m - 1 - i);
            }
            tmp += tb[m - 1 - i];
            ll kur = min(ta[i], tmp);
            lmao += kur;
            tmp -= kur;

            // debug(i, kur);

            if (kur == 0) continue;

            ll buf = 0;
            while (true) {
                if (buf + rem.front().first > kur) {
                    pair<ll, ll> last = rem.front();
                    if (last.second + i >= m) {
                        ada_start_carry = true;
                    }
                    rem.pop();
                    tb[last.second] -= (kur - buf);
                    rem.emplace(last.first - (kur - buf), last.second);
                    break;
                } else {
                    if (rem.front().second + i >= m) {
                        ada_start_carry = true;
                    }
                    buf += rem.front().first;
                    tb[rem.front().second] = 0;
                    rem.pop();
                    if (buf == kur) break;
                }
            }
            // debug(ada_start_carry);

            // cerr << i << '\n';
            // queue<pair<ll, ll>> tmp = rem;
            // while (!tmp.empty()) {
            //     cerr << tmp.front().first << ' ' << tmp.front().second << '\n';
            //     tmp.pop();
            // }
            // cerr << "--\n";
        }
        if (!ada_start_carry) {
            ll tot = 0;
            for (int j = m - 1; j >= 1; j--) {
                tot += Q[j];
                if (tot > 0 && P[m - j] > 0) {
                    ada_start_carry = true;
                    break;
                }
            }
            if (!ada_start_carry) return 0;
            ret = max(ret, lmao - 1);
        } else {
            ret = max(ret, lmao);
        }
        // debug(ret);

        return ret;
    };
    // debug(go(A, B), go(B, A));
    ll ans = max(go(A, B), go(B, A));
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