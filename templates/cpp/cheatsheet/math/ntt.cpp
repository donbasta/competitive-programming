#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vll = vector<ll>;

const ll mod = (119 << 23) + 1, root = 62;

// KTH cheatsheet template
ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void NTT(vll &a, vll &rt, vll &rev, int n) {
    for (int i = 0; i < n; i++) {
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
                a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
                ai += (ai + z >= mod ? z - mod : z);
            }
        }
    }
}

vll conv(const vll &a, const vll &b) {
    if (a.empty() || b.empty())
        return {};
    int s = (int)a.size() + (int)b.size() - 1;
    int B = 32 - __builtin_clz(s);
    int n = 1 << B;
    vll L(a), R(b), out(n), rt(n, 1), rev(n);
    L.resize(n), R.resize(n);
    for (int i = 0; i < n; i++) {
        rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
    }
    ll curL = mod / 2;
    ll inv = fastexpo(n, mod - 2);
    for (int k = 2; k < n; k *= 2) {
        ll z[] = {1, fastexpo(root, curL /= 2)};
        for (int i = k; i < 2 * k; i++) {
            rt[i] = rt[i / 2] * z[i & 1] % mod;
        }
    }
    NTT(L, rt, rev, n);
    NTT(R, rt, rev, n);
    for (int i = 0; i < n; i++) {
        out[-i & (n - 1)] = L[i] * R[i] % mod * inv % mod;
    }
    NTT(out, rt, rev, n);
    return {out.begin(), out.begin() + s};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vll A = {1, 0, 1, 1}, B = {1, 2};
    vll C = conv(A, B);
    for (auto i : C) {
        cerr << i << ' ';
    }

    return 0;
}
