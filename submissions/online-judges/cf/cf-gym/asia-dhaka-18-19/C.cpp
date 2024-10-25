#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 1e6;
const ll MOD = 1e7 + 7;  // 941 * 10627
const ll A = 941, B = 10627;

vector<ll> primes;
bool is_prime[M + 5];
ll jwb[M + 5], pg[M + 5], gpf[M + 5];
ll inv;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll fpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

ll solve(ll p, ll q, ll cp, ll cq) {
    if (cp > 0) p = 0;
    if (cq > 0) q = 0;
    ll ret = (1ll * B * p + 1ll * q * A) % MOD;
    ret = (ret * inv) % MOD;
    return ret;
}

void init() {
    fill(is_prime + 1, is_prime + M + 1, true);
    for (int i = 2; i <= M; i++) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        gpf[i] = i;
        for (int j = i + i; j <= M; j += i) {
            is_prime[j] = false;
            gpf[j] = i;
        }
    }

    ll tmp;
    gcd(A * B, A + B, tmp, inv);
    inv %= (MOD);
    if (inv < 0) inv += MOD;

    ll ca = 1, cnta = 0;
    ll cb = 1, cntb = 0;
    jwb[1] = 1;
    for (int i = 2; i <= M; i++) {
        vector<pair<int, int>> fp;
        int cur = i;
        while (cur > 1) {
            int p = gpf[cur];
            int pw = 0;
            while (cur % p == 0) {
                pw++;
                cur /= p;
            }
            fp.emplace_back(p, pw);
        }
        for (auto e : fp) {
            {
                if ((pg[e.first] % A == (A - 1)) || (pg[e.first] % A == (A - 2))) {
                    cnta--;
                } else {
                    ll x = (1ll * (pg[e.first] + 1) * (pg[e.first] + 2) / 2) % A;
                    ca = (1ll * ca * fpow(x, A - 2, A)) % A;
                }
                ll y = pg[e.first] + e.second;
                if ((y % A == (A - 1)) || (y % A == (A - 2))) {
                    cnta++;
                } else {
                    ll x = (1ll * (y + 1) * (y + 2) / 2) % A;
                    ca = (1ll * ca * x) % A;
                }
            }
            {
                if ((pg[e.first] % B == (B - 1)) || (pg[e.first] % B == (B - 2))) {
                    cntb--;
                } else {
                    ll x = (1ll * (pg[e.first] + 1) * (pg[e.first] + 2) / 2) % B;
                    cb = (1ll * cb * fpow(x, B - 2, B)) % B;
                }
                ll y = pg[e.first] + e.second;
                if ((y % B == (B - 1)) || (y % B == (B - 2))) {
                    cntb++;
                } else {
                    ll x = (1ll * (y + 1) * (y + 2) / 2) % B;
                    cb = (1ll * cb * x) % B;
                }
            }
            pg[e.first] += e.second;
        }
        jwb[i] = solve(ca, cb, cnta, cntb);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int x;
    cin >> x;
    while (x != 0) {
        cout << jwb[x] << '\n';
        cin >> x;
    }

    return 0;
}