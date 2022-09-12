#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;
const ll MOD = 998244353;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll m = sqrtl(1LL * k * k * 4 + k * 4 + 1 + n * 8);
    m -= (2 * k + 1);
    m /= 2;
    m += 1;

    vector<int> tot(n + 1);
    vector<int> buf(n + 1);
    vector<int> ans(n + 1);

    for (int j = 0; j <= n; j += k) {
        buf[j] = 1;
    }
    for (int j = k; j <= (k + m); j++) {
        for (int i = 1; i <= n; i++) {
            tot[i] = ((i >= j) ? buf[i - j] : 0) % MOD;
        }
        for (int i = 0; i <= n; i++) {
            buf[i] = (((i > j) ? buf[i - (j + 1)] : 0) + tot[i]) % MOD;
        }
        for (int i = 1; i <= n; i++) {
            ans[i] = (ans[i] + tot[i]) % MOD;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
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
