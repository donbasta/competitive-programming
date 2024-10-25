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

using H = vector<ll>;
ll B[2] = {31, 37};
ll MOD[2] = {998244353, 1000000009};
const int N = 5000;

ll pw[N + 5][2], ipw[N + 5][2];

ll fpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

void precomp() {
    pw[0][0] = pw[0][1] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            pw[i][j] = (pw[i - 1][j] * B[j]) % MOD[j];
        }
    }
    ll iB[2];
    for (int j = 0; j < 2; j++) {
        iB[j] = fpow(B[j], MOD[j] - 2, MOD[j]);
    }
    ipw[0][0] = ipw[0][1] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            ipw[i][j] = (ipw[i - 1][j] * iB[j]) % MOD[j];
        }
    }
}

H get_hash(const string &S) {
}

void el_psy_congroo() {
    int n;
    cin >> n;
    string s[n];
    H hash[n];
    map<H, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        hash[i] = get_hash(s[i]);
        mp[hash[i]].push_back(i);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int len = s[i].length();
        for (int j = 0; j < len; j++) {
            string tmp;
            for (int k = j; k < len; k++) {
                tmp += s[i][k];
                H cek = get_hash(tmp);
                if (mp.count(cek)) {
                    for (auto v : mp[cek]) {
                        adj[v].emplace_back(i);
                        adj[i].emplace_back(v);
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precomp();

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}