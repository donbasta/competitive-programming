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

ll fpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (1ll * ret * a) % mod;
        a = (1ll * a * a) % mod;
        b >>= 1;
    }
    return ret;
}

struct RollingHash {
    const vector<ll> B = {31, 37};
    const vector<ll> M = {1000000007, 1000000009};
    vector<ll> H[2], pw[2], ipw[2];
    ll iB[2];
    RollingHash() {}
    RollingHash(int n) {
        pw[0].resize(n + 1), pw[1].resize(n + 1);
        ipw[0].resize(n + 1), ipw[1].resize(n + 1);
        pw[0][0] = pw[1][0] = ipw[0][0] = ipw[1][0] = 1;
        for (int i = 0; i < 2; i++) {
            iB[i] = fpow(B[i], M[i] - 2, M[i]);
            for (int j = 1; j <= n; j++) {
                pw[i][j] = (1ll * pw[i][j - 1] * B[i]) % M[i];
                ipw[i][j] = (1ll * ipw[i][j - 1] * iB[i]) % M[i];
            }
        }
    }
    RollingHash(const string &s) {
        int n = s.length();
        H[0].resize(n), H[1].resize(n);
        pw[0].resize(n + 1), pw[1].resize(n + 1);
        ipw[0].resize(n + 1), ipw[1].resize(n + 1);
        pw[0][0] = pw[1][0] = ipw[0][0] = ipw[1][0] = 1;
        for (int i = 0; i < 2; i++) {
            iB[i] = fpow(B[i], M[i] - 2, M[i]);
            for (int j = 1; j <= n; j++) {
                pw[i][j] = (1ll * pw[i][j - 1] * B[i]) % M[i];
                ipw[i][j] = (1ll * ipw[i][j - 1] * iB[i]) % M[i];
            }
            H[i][0] = (s[0] - 'a' + 1);
            for (int j = 1; j < n; j++) {
                H[i][j] = (1ll * H[i][j - 1] + 1ll * (s[j] - 'a' + 1) * pw[i][j]) % M[i];
            }
        }
    }
    pair<ll, ll> get_hash(int a, int b) {
        vector<ll> X(2);
        for (int i = 0; i < 2; i++) {
            int hsh = (H[i][b] - (a ? H[i][a - 1] : 0)) % M[i];
            if (hsh < 0) hsh += M[i];
            hsh = (1ll * hsh * ipw[i][a]) % M[i];
            X[i] = hsh;
        }
        return make_pair(X[0], X[1]);
    }
};

void el_psy_congroo() {
    string s;
    cin >> s;

    RollingHash rh(s);

    int n = s.length();
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }

    if (cnt[0] == n) {
        cout << (n - 1) << '\n';
        return;
    }

    int fpb = 0;
    for (int i = 1; i < 26; i++) {
        fpb = __gcd(fpb, cnt[i]);
    }

    vector<int> divs;
    for (int i = 1; i * i <= fpb; i++) {
        if (fpb % i != 0) continue;
        divs.push_back(i);
        if (i * i != fpb) divs.push_back(fpb / i);
    }

    ll ans = 0;
    for (auto d : divs) {
        vector<int> freq = cnt;
        for (int i = 1; i < 26; i++) freq[i] /= d;
        int ada = 0;
        for (int i = 1; i < 26; i++) {
            if (freq[i] > 0) ada++;
        }
        vector<int> tmp = freq;
        vector<pair<int, int>> itv;
        int start;
        int cur_ada = ada;
        bool ok = true;

        vector<int> gaps;
        bool scan = false;
        int cur_gap = 0;
        for (int i = 0; i < n; i++) {
            if (!scan) {
                if (s[i] == 'a') {
                    cur_gap++;
                } else {
                    gaps.push_back(cur_gap);
                    start = i;
                    scan = true;
                    tmp[s[i] - 'a']--;
                    if (tmp[s[i] - 'a'] == 0) cur_ada--;
                    if (tmp[s[i] - 'a'] < 0) {
                        ok = false;
                        break;
                    }
                    if (cur_ada == 0) {
                        itv.emplace_back(start, i);
                        tmp = freq;
                        scan = false;
                        cur_ada = ada;
                        cur_gap = 0;
                    }
                }
            } else {
                if (s[i] == 'a') {
                    continue;
                } else {
                    tmp[s[i] - 'a']--;
                    if (tmp[s[i] - 'a'] == 0) cur_ada--;
                    if (tmp[s[i] - 'a'] < 0) {
                        ok = false;
                        break;
                    }
                    if (cur_ada == 0) {
                        itv.emplace_back(start, i);
                        tmp = freq;
                        scan = false;
                        cur_ada = ada;
                        cur_gap = 0;
                    }
                }
            }
        }
        if (!ok) {
            continue;
        }
        gaps.push_back(cur_gap);

        int sz = itv.size();
        pair<ll, ll> cek = rh.get_hash(itv[0].first, itv[0].second);
        for (int i = 1; i < sz; i++) {
            if (cek != rh.get_hash(itv[i].first, itv[i].second)) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }

        assert(itv.size() + 1 == gaps.size());
        int mn = INF;
        for (int i = 1; i < sz; i++) {
            mn = min(mn, gaps[i]);
        }
        // x <= gaps[0], y <= gaps.back(), x+y <= mn
        for (int x = 0; x <= min(mn, gaps[0]); x++) {
            ans += min(gaps.back(), mn - x) + 1;
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