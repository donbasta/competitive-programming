#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;
const ll MOD = 998244353;
 
void solve() {
    ll n, k;
    cin >> n >> k;
    ll m = sqrt(2 * n);
    vector<vector<int>> dp2(n + 1, vector<int>(m + 1));
    dp2[0][k - 1] = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> dp_new(m + 1);
        for (int j = k; j <= m; j++) {
            dp_new[j] = ((i >= j) ? dp2[i - j][j - 1] : 0);
            dp2[i][j - 1] = (((i >= j) ? dp2[i - j][j - 1] : 0) + dp_new[j - 1]) % MOD;
        }
        ll tmp = 0;
        for (int j = 1; j <= m; j++) {
            tmp = (tmp + dp_new[j]) % MOD;
        }
        cout << tmp << ' ';
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