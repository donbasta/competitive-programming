#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

template <typename T>
struct XORBasis {
    int DIM, RANK;
    vector<T> BASE;
    XORBasis(int _DIM) : DIM(_DIM), BASE(DIM + 1, -1), RANK(0) {}
    void insert(T x) {
        for (int i = DIM; i >= 0; i--) {
            if (!((x >> i) & 1)) continue;
            if (BASE[i] == -1) {
                BASE[i] = x;
                RANK++;
                return;
            }
            x ^= BASE[i];
        }
    }
    bool span(T x) {
        for (int i = DIM; i >= 0; i--) {
            if (!((x >> i) & 1)) continue;
            if (BASE[i] == -1) return false;
            x ^= BASE[i];
        }
        return true;
    }
};

vector<pair<int, int>> prime_factorization(int x) {
    vector<pair<int, int>> ret;
    for (int i = 2; i * i <= x; i++) {
        if (x % i != 0) continue;
        int pw = 0;
        while (x % i == 0) {
            pw++, x /= i;
        }
        ret.emplace_back(i, pw);
    }
    if (x > 1) ret.emplace_back(x, 1);
    return ret;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    set<int> pr;
    vector<vector<pair<int, int>>> fp(n);
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        fp[i] = prime_factorization(ar[i]);
        for (auto e : fp[i]) {
            if (e.second % 2 == 0) continue;
            pr.insert(e.first);
        }
    }
    map<int, ll> hash;
    for (auto e : pr) hash[e] = rng();
    vector<ll> F(n);
    for (int i = 0; i < n; i++) {
        for (auto e : fp[i]) {
            if (e.second % 2 == 0) continue;
            F[i] ^= hash[e.first];
        }
    }
    XORBasis<ll> xb(60);
    for (int i = 0; i < n; i++) {
        xb.insert(F[i]);
    }
    int rank = xb.RANK;
    ll ans = fpow(2, n - rank) % MOD;
    ans = (ans - 1) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}