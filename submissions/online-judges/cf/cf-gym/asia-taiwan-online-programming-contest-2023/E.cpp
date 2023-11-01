
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using matrix = vector<vector<ll>>;

matrix identity;
ll mod;

matrix mul(matrix a, matrix b) {
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

matrix fpow(matrix a, ll b) {
    matrix ret = identity;
    while (b) {
        if (b & 1) ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll a, b;
    cin >> a >> b >> mod;
    a %= mod;
    identity = {{1, 0}, {0, 1}};
    matrix A = {{a, -1}, {1, 0}};

    int sz = 3;
    for (int i = 0; i < sz; i++) {
        vector<ll> temp;
        for (int j = 0; j < sz; j++) {
            temp.push_back((i == j) ? 1 : 0);
        }
        identity.push_back(temp);
    }

    printMatrix(identity);
}

void el_psy_congroo() {
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