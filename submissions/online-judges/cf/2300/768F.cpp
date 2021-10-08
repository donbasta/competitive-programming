#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 1e5;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

struct Combi {
    vector<ll> fc, ifc;
    void init(int n) {
        fc.resize(n + 5), ifc.resize(n + 5);
        fc[0] = 1;
        for (int i = 1; i <= n; i++) {
            fc[i] = (fc[i - 1] * i) % MOD;
        }
        ifc[n] = fpow(fc[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
        }
    }
    ll cb(ll a, ll b) {
        if (a < 0 || b < 0 || a < b) {
            return 0;
        }
        ll ret = (fc[a] * ifc[b]) % MOD;
        ret = (ret * ifc[a - b]) % MOD;
        return ret;
    }
} combi;

void solve() {
    ll f, w, h;
    cin >> f >> w >> h;
    if (w == 0) {
        cout << 1 << '\n';
        return;
    }
    ll num = 0;
    for (int i = 1; i <= (w / (h + 1)); i++) {
        ll tmp = (combi.cb(f + 1, i) * combi.cb(w - h * i - 1, i - 1)) % MOD;
        num = (num + tmp) % MOD;
    }
    num = (num * fpow(combi.cb(f + w, f), MOD - 2)) % MOD;
    if (num < 0) num += MOD;
    cout << num << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    combi.init(2 * N);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}