#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using matrix = vector<vector<ll>>;

matrix identity, fibo;

matrix mul(matrix a, matrix b, ll mod) {
    int sz = (int)a.size();
    matrix d(sz, vector<ll>(sz));
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                d[i][j] = (d[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return d;
}

matrix fpow(matrix a, ll b, ll mod) {
    matrix ret = identity;
    while (b) {
        if (b & 1)
            ret = mul(ret, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return ret;
}

void solve(int tc) {
    ll n, m;
    cin >> n >> m;
    matrix T = fpow(fibo, n - 1, m);
    ll ans = T[0][0] % m;
    if (ans < 0) ans += m;
    cout << "Case #" << tc << ": " << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    identity = {{1, 0}, {0, 1}};
    fibo = {{1, 1}, {1, 0}};

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve(i);
    }

    return 0;
}