#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int N = 1e6;

int dp[2][N + 5];
int n, m, k;

vector<int> kerja(int sz) {
    vector<int> a = kerja(sz / 2);
    vector<int> b = kerja(sz - (sz / 2));
    vector<int> ret(k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            ret[(i + j) % k] = (ret[(i + j) % k] + a[i] * b[j]) % mod;
        }
    }
    return ret;
}

void solve() {
    cin >> n >> m >> k;
    if (m * n < k) {
        cout << 0 << '\n';
        return;
    }
    vector<int> ans = kerja(n);
    int A = ans[0];
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << dp[n & 1][0] << '\n';
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