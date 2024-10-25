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
// const ll MOD = 1e9 + 9;
const ll MOD[2] = {998244353, 1000000009};
const ll B[2] = {3, 5};

ll fpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i];
        if (s[i] == '(')
            pre[i + 1]++;
        else
            pre[i + 1]--;
    }

    vector<vector<ll>> pw(n + 1, vector<ll>(2)), ipw(n + 1, vector<ll>(2)), pref(n + 1, vector<ll>(2));
    pw[0][0] = ipw[0][0] = pw[0][1] = ipw[0][1] = 1;
    ll iB[2];
    iB[0] = fpow(B[0], MOD[0] - 2, MOD[0]);
    iB[1] = fpow(B[1], MOD[1] - 2, MOD[1]);
    for (int x = 0; x < 2; x++)
        for (int i = 1; i <= n; i++) pw[i][x] = (pw[i - 1][x] * B[x]) % MOD[x];
    for (int x = 0; x < 2; x++)
        for (int i = 1; i <= n; i++) ipw[i][x] = (ipw[i - 1][x] * iB[x]) % MOD[x];

    for (int x = 0; x < 2; x++)
        for (int i = 0; i < n; i++) {
            int dig = (s[i] == '(' ? 1 : 2);
            ll add = (1ll * dig * pw[i][x]) % MOD[x];
            pref[i][x] = ((i ? pref[i - 1][x] : 0ll) + add) % MOD[x];
        }

    auto get_hash = [&](int a, int b) -> vector<ll> {
        vector<ll> ret;
        for (int x = 0; x < 2; x++) {
            ll sum = (pref[b][x] - (a ? pref[a - 1][x] : 0)) % MOD[x];
            sum = (sum * ipw[a][x]) % MOD[x];
            if (sum < 0) sum += MOD[x];
            ret.push_back(sum);
        }
        return ret;
    };

    map<vector<ll>, vector<pair<int, int>>> segs;
    map<int, vector<int>> pos;
    map<int, int> ptr;
    for (int i = 0; i <= n; i++) {
        pos[pre[i]].push_back(i);
    }

    // for (int i = 0; i < n; i++) {
    //     if (s[i] == ')') continue;

    //     if (ptr[pre[i]] == pos[pre[i]].size()) continue;
    //     int j = pos[pre[i]][++ptr[pre[i]]];
    //     segs[get_hash(i, j - 1)].emplace_back(i, j - 1);
    // }

    for (int i = 0; i < n; i++) {
        if (s[i] == ')') continue;

        if (ptr[pre[i]] == pos[pre[i]].size()) continue;
        while (ptr[pre[i]] < (int)pos[pre[i]].size() && pos[pre[i]][ptr[pre[i]]] < i + 1) ++ptr[pre[i]];
        if (ptr[pre[i]] == pos[pre[i]].size()) continue;
        int j = pos[pre[i]][ptr[pre[i]]];
        // debug(i, pre[i], ptr[pre[i]], j, j - 1);
        segs[get_hash(i, j - 1)].emplace_back(i, j - 1);
    }

    ll ans = 0;
    for (auto e : segs) {
        int sz = e.second.size();
        int ptr = 0;
        for (int i = 0; i < sz; i++) {
            while (ptr < sz && e.second[ptr].first <= e.second[i].second) ptr++;
            ans += (sz - ptr);
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