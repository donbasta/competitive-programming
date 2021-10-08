#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using cd = complex<ld>;
using vd = vector<ld>;
using vl = vector<ll>;
const ld PI = acos(-1);

const ll MOD = 1e9 + 7;

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    ld ang = PI * 2 / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> mul(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        ll haha = roundl(fa[i].real());
        haha %= MOD;
        result[i] = haha;
    }

    return result;
}


void solve() {
    ll n, m, k;

    cin >> n >> m >> k;
    vector<ll> ar(n + 2), pre(n + 2), suf(n + 2);
    vector<int> cntPref(k), cntSuf(k);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        ar[i] %= k;
    }
    if (k == 1) {
        ll tmp = (n * m) % MOD;
        tmp = (tmp * tmp) % MOD;
        tmp -= (n * m - 1);
        tmp %= MOD;
        if (tmp < 0) tmp += MOD;
        cout << tmp << '\n';
        return;
    }

    if (m == 1) {
        ll ans = 0;
        cntPref[0]++;
        for (int i = 1; i <= n; i++) {
            pre[i] = (pre[i - 1] + ar[i]) % k;
            ans = (ans + cntPref[pre[i]]) % MOD;
            cntPref[pre[i]]++;
        }
        ll sisa = pre[n] % k;
        cntPref.assign(k, 0);
        cntPref[pre[1]]++;
        for (int i = 2; i < n; i++) {
            int cari = (pre[i] - sisa) % k;
            if (cari < 0) cari += k;
            ans = (ans + cntPref[cari]) % MOD;
            cntPref[pre[i]]++;
        }
        cout << ans << '\n';
        return;
    }

    ll ans = 0;
    cntPref[0] = 1;
    for (int i = 1; i <= n; i++) {
        pre[i] = (pre[i - 1] + ar[i]) % k;
        if (i < n) {
            if (m > 1) {
                ans = (ans + cntPref[pre[i]]) % MOD;
            }
            cntPref[pre[i]]++;
        }
    }
    cntSuf[0] = 1;
    for (int i = n; i >= 1; i--) {
        suf[i] = (suf[i + 1] + ar[i]) % k;
        if (i > 1) {
            if (m > 1) {
                if (suf[i] % k == 0) ans++;
            }
            cntSuf[suf[i]]++;
        }
    }

    ans = (ans * m) % MOD;
    // cerr << ans << '\n';

    vector<int> C1, C2;
    for (int i = 0; i < k; i++) {
        C1.emplace_back(cntPref[i]);
        C2.emplace_back(cntSuf[i]);
    }

    vector<int> prod = mul(C1, C2);


    vector<int> prodInt(k);
    int sz = (int) prod.size();
    for (int i = 0; i < sz; i++) {
        prodInt[i % k] = (1LL * prodInt[i % k] + prod[i]) % MOD;
    }

    for (int i = 0; i <= m - 2; i++) {
        ll sumTengah = (pre[n] * i) % k;
        ll sumSamping = (k - sumTengah) % k;
        ll tmp = prodInt[sumSamping];
        if (i == 0) tmp--; 
        ans = (ans + tmp * m) % MOD;
        if (ans < 0) ans += MOD;
        // cerr << ans << '\n';
    }

    ll sumTengah = (pre[n] * (m - 1)) % k;
    ll sumSamping = (k - sumTengah) % k;
    ll sumRemove = (pre[n] - sumSamping) % k;
    if (sumRemove < 0) sumRemove += k;
    vector<int> tmp(k + 1);
    tmp[0]++;
    for (int i = 1; i <= n; i++) {
        int cari = (pre[i] - sumRemove) % k;
        if (cari < 0) cari += k;
        ans = (ans + tmp[cari] * 1LL * m) % MOD;
        tmp[pre[i]]++;
    }
    // cerr << ans << '\n';

    if ((pre[n] * 1LL * m) % k == 0) {
        ans++;
    }

    if (m > 1) {
        for (int i = 1; i < n; i++) {
            if (pre[i] % k == 0) ans -= m;
            ans %= MOD;
        }
        for (int i = 2; i <= n; i++) {
            if (suf[i] % k == 0) ans -= m;
            ans %= MOD;
        }
    }

    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n'; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}
