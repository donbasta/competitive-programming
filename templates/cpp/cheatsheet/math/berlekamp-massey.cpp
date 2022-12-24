#include <bits/stdc++.h>
using namespace std;

// recover any n-order linear recurrence relation
// from the first 2n terms of the sequence
// e.g. berlekampMassey({0, 1, 1, 3, 5, 11}) = {1, 2}

using ll = long long;
const ll MOD = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

vector<ll> berlekampMassey(vector<ll> seq) {
    int n = seq.size(), L = 0, m = 0;
    vector<ll> C(n), B(n), T;
    C[0] = B[0] = 1;

    ll b = 1;
    for (int i = 0; i < n; i++) {
        ll d = seq[i] % MOD;
        for (int j = 1; j <= L; j++) {
            d = (d + C[j] * seq[i - j]) % MOD;
        }
        if (!d)
            continue;
        T = C;
        ll coef = (d * fpow(b, MOD - 2)) % MOD;
        for (int j = m; j < n; j++) {
            C[j] = (C[j] - coef * B[j - m]) % MOD;
        }
        if (L * 2 > i)
            continue;
        L = i + 1 - L;
        B = T;
        b = d;
        m = 0;
    }

    C.resize(L + 1);
    C.erase(C.begin());
    for (ll &x : C) {
        x = (MOD - x) % MOD;
    }
    return C;
}

int main() {
    vector<ll> seq = {0, 1, 1, 3, 5, 11};
    vector<ll> coefRec = berlekampMassey(seq);

    for (auto &e : coefRec) {
        cerr << e << ' ';
    }
    cerr << '\n';

    vector<ll> fibo = {0, 1, 1, 2, 3, 5};
    coefRec = berlekampMassey(fibo);

    for (auto &e : coefRec) {
        cerr << e << ' ';
    }
    cerr << '\n';

    seq = {1, 2, 4, 8, 16, 32};
    coefRec = berlekampMassey(seq);

    for (auto &e : coefRec) {
        cerr << e << ' ';
    }
    cerr << '\n';
}