#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using matrix = vector<vector<ll>>;

const int INF = 2e9;
const ll MOD = 998244353;
matrix id;

matrix mul(matrix a, matrix b) {
    int sz = (int)a.size();
    matrix d(sz, vector<ll>(sz));
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                d[i][j] = (d[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return d;
}

matrix fpow(matrix a, ll b) {
    matrix ret = id;
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

void el_psy_congroo() {
    ll n, k;
    cin >> k >> n;
    ll k2 = (1ll << k);
    id.resize(k2);
    for (int i = 0; i < k2; i++) {
        id[i].resize(k2);
        id[i][i] = 1;
    }
    matrix A;
    A.resize(k2);
    for (int i = 0; i < k2; i++) {
        A[i].resize(k2);
        A[i][i] = 1;
        int prv = i - 1;
        if (prv < 0) prv += k2;
        A[i][prv] = 1;
    }
    matrix Apw = fpow(A, n);
    for (int i = 0; i < k2; i++) {
        cout << Apw[i][0] << ' ';
    }
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