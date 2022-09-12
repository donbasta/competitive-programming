#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;
 
void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans;
    if (b >= a) {
        ans = max(0LL, n - a + 1);
    } else {
        ll x = n / a, y = n % a;
        ans = b * x;
        ans += min(y + 1, b);
        ans -= (b);
        ans = max(ans, 0LL);
    }
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
