#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int mod = 998244353;

ll powmod(ll a, ll p) {
    ll r = 1;
    for (; p; p >>= 1, a = a * a % mod)
        if (p & 1)
            r = r * a % mod;
    return r;
}

const int root = 646;
const int root_1 = powmod(root, mod - 2);
const int root_pw = 1 << 20;

void fft(vector<int>& a, bool invert) {
    int n = (int)a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(wlen * 1ll * wlen % mod);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j], v = (int)(a[i + j + len / 2] * 1ll * w % mod);
                a[i + j] = u + v < mod ? u + v : u + v - mod;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                w = int(w * 1LL * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = powmod(n, mod - 2);
        for (int i = 0; i < n; ++i) a[i] = int(a[i] * 1ll * n_1 % mod);
    }
}

void squaring(vector<int>& a) {
    int n1 = 2 * a.size();
    int lg = 0;
    while ((1 << lg) < n1) ++lg;
    n1 = 1 << lg;
    a.resize(n1, 0);
    fft(a, false);
    for (int i = 0; i < n1; ++i) a[i] = 1LL * a[i] * a[i] % mod;
    fft(a, true);
    while (n1 > 1 && a[n1 - 1] == 0) --n1;
    a.resize(n1);
}

vector<int> multiply(vector<int>& a, vector<int>& b) {
    int n1 = a.size() + b.size();
    int lg = 0;
    while ((1 << lg) < n1) ++lg;
    n1 = 1 << lg;
    a.resize(n1, 0);
    b.resize(n1, 0);
    fft(a, false);
    fft(b, false);
    vector<int> res(n1);
    for (int i = 0; i < n1; i++) res[i] = 1LL * a[i] * b[i] % mod;
    fft(res, true);

    while (n1 > 1 && res[n1 - 1] == 0) --n1;
    res.resize(n1);
    return res;
}

vector<int> fast_expo(vector<int>& a, int m) {
    if (m == 0) return {1};
    if (m == 1) return a;
    vector<int> c = a;
    vector<int> b = fast_expo(a, m / 2);
    squaring(b);
    if (m & 1) b = multiply(b, c);
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, x;
    cin >> n >> k;
    vector<int> a(10, 0);
    for (int i = 1; i <= k; ++i) {
        cin >> x;
        a[x] = 1;
    }

    int t = 10;
    while (t > 1 && a[t - 1] == 0) t--;
    a.resize(t);
    // for(auto i: a) cout << i << " ";
    // cout << "\n";
    a = fast_expo(a, n / 2);
    // for(auto i: a) cout << i << " ";
    ll ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        ans = (ans + 1LL * a[i] * a[i]) % mod;
    }
    if (ans < 0) ans += mod;
    cout << ans;
}