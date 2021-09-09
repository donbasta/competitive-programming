#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const ll MOD = 1e9 + 7;
 
int n, k;
 
ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}
 
void solve() {
    cin >> n >> k;
    vector<int> H, E(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        H.emplace_back(x);
    }
 
    E[0] = 0;
    ll ik = fpow(k - 1, MOD - 2);
    for (int i = 1; i <= n; i++) {
        ll tmp = k;
        int si = sqrt(i);
        for (int j = 2; j <= min(k, si); j++) {
            tmp = (tmp + E[i / j]) % MOD;
        }
        vector<int> divs;
        if (k > si) {
            for (int j = 1; j <= si; j++) {
                if (i % j == 0 && j * j != i) {
                    divs.emplace_back(i / j);
                }
            }
            reverse(divs.begin(), divs.end());
            int cur = i / (si + 1);
            int last = si + 1;
            for (int j = 0; j < (int)divs.size(); j++) {
                if (divs[j] > k) {
                    tmp = (tmp + 1LL * E[cur] * (k - last)) % MOD;
                    cur = i / k;
                    break;
                }
                tmp = (tmp + 1LL * E[cur] * (divs[j] - last)) % MOD;
                cur = i / divs[j];
                last = divs[j];
            }
            tmp = (tmp + E[cur]) % MOD;
        }
        tmp = (tmp * ik) % MOD;
        E[i] = tmp;
    }
    ll ans = 0;
    for (auto health : H) {
        // cerr << health << ' ' << E[health] << '\n';
        ans = (ans + E[health]) % MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
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