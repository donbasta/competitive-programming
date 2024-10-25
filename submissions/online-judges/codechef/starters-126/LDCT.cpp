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
const ll MOD = 1e9 + 7;
const int K = 60;
const ll MX = 1e9;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

vector<int> primes;
bool pr[K + 1];
void init_prime() {
    for (int i = 2; i <= K; i++) {
        bool ok = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                ok = false;
            }
        }
        if (ok) {
            primes.push_back(i);
            pr[i] = true;
        }
    }
}

unordered_map<ll, ll> cnt;
void generateDivisors(int curIdx, ll curDiv, const vector<pair<ll, ll>>& ar) {
    if (curIdx == ar.size()) {
        cnt[curDiv]++;
        return;
    }
    for (int i = 0; i <= ar[curIdx].second; i++) {
        generateDivisors(curIdx + 1, curDiv, ar);
        curDiv *= ar[curIdx].first;
    }
}

vector<pair<ll, ll>> T[20];
void precomp_subset() {
    vector<pair<ll, ll>> bils;
    bils.emplace_back(1, 0);
    T[0] = bils;
    for (int i = 0; i < primes.size(); i++) {
        vector<pair<ll, ll>> tmps;
        for (auto e : bils) {
            if (e.first * primes[i] <= MX) tmps.emplace_back(e.first * primes[i], e.second + 1);
        }
        for (auto e : bils) tmps.push_back(e);
        bils.swap(tmps);
        T[i + 1] = bils;
    }
}


void el_psy_congroo() {
    cnt.clear();

    ll n, k;
    cin >> n >> k;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];

    if (!pr[k]) {
        cout << 0 << '\n';
        return;
    }

    ll pw[n + 1];
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = (pw[i - 1] * 2) % MOD;
    }

    
    for (int i = 0; i < n; i++) {
        bool ok = false;
        ll tmp = ar[i];
        vector<pair<ll, ll>> fp;
        for (auto e : primes) {
            int pw = 0;
            while (tmp % e == 0) {
                tmp /= e, pw++;
            }
            if (pw > 0) {
                fp.emplace_back(e, pw);
            }
        }
        generateDivisors(0, 1, fp);
    }
    int idx = 0;
    while (idx < primes.size() && primes[idx] != k) {
        idx++;
    }

    ll ans = 0;

    for (auto e : T[idx]) {
        ll tmp = primes[idx] * e.first;
        if (tmp >= MX || !cnt.count(tmp)) continue;
        ll now = (pw[cnt[tmp]] - 1) % MOD;
        if (e.second & 1) {
            ans = (ans - now) % MOD;
        } else {
            ans = (ans + now) % MOD;
        }
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init_prime();
    // debug(primes, primes.size());
    precomp_subset();
    // for (int i = 0; i < 17; i++) {
    //     cerr << i << ' ' << T[i].size() << '\n';
    // }

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}