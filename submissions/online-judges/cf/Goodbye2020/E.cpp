#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const int M = 60;
const int N = 5e5;

int n;

ll fpow (ll a, ll b, ll c) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return ret;
}

void solve() {
    cin >> n;
    vector<ll> ar(n), ve(M);
    vector<int> cnt(M);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        for (int j = 0; j < M; j++) {
            if ((ar[i] >> j) & 1) cnt[j]++;
        }
    }
    ll Ans = 0;
    for (int i = 0; i < M; i++) {
        ve[i] = (1LL * cnt[i] * fpow(2, i, mod)) % mod;
    }
    for (int i = 0; i < n; i++) {
        ll tmp = 0;
        for (int j = 0; j < M; j++) {
            if (((ar[i] >> j) & 1)) continue;
            tmp = (tmp + fpow(2, j, mod) * cnt[j]) % mod;
        }
        for (int j = 0; j < M; j++) {
            if (!((ar[i] >> j) & 1)) continue;
            ll now = (tmp + ar[i] * n) % mod;
            Ans = (Ans + ve[j] * now) % mod;
        }
    }
    Ans %= mod;
    if (Ans < 0) Ans += mod;
    cout << Ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}