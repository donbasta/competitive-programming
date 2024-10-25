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
const ll MOD = 998244353;
const int N = 5e5;

ll fc[N + 1], ifc[N + 1];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void init() {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) fc[i] = (fc[i - 1] * i) % MOD;
    ifc[N] = fpow(fc[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
}

void el_psy_congroo() {
    int n, c;
    cin >> n >> c;
    vector<int> L(n + 1), R(n + 1), val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i] >> val[i];
    }
    vector<int> ord;
    const function<void(int)> dfs = [&](int v) {
        if (L[v] != -1) dfs(L[v]);
        ord.push_back(v);
        if (R[v] != -1) dfs(R[v]);
    };
    dfs(1);
    vector<int> cur;
    cur.push_back(1);
    for (auto e : ord) cur.push_back(val[e]);
    cur.push_back(c);

    int itr = 0;
    ll ans = 1;
    while (itr < cur.size()) {
        if (cur[itr] != -1) {
            itr++;
            continue;
        }
        int j = itr;
        while (j < cur.size() && cur[j] == -1) j++;
        int left = cur[itr - 1], right = cur[j];
        int cnt = j - itr;
        if (right < left) {
            cout << 0 << '\n';
            return;
        }
        ll tmp = 1;
        for (int i = 1; i <= cnt; i++) {
            tmp = (tmp * (right - left + i)) % MOD;
        }
        tmp = (tmp * ifc[cnt]) % MOD;
        ans = (ans * tmp) % MOD;
        itr = j;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}