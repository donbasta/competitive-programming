#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;

ll convToBase3(ll x) {
    ll ret = 0;
    ll pw = 1;
    while (x) {
        if (x & 1) ret += pw;
        pw = (pw * 3);
        x >>= 1;
    }
    return ret;
}

ll floor(ll a, ll b) {
    if (a % b == 0) return a / b;
    if (a < 0) {
        return (a / b) - 1;
    }
    return a / b;
}
 
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> ve; 
    for (ll i = 1; i <= n; i++) {
        ve.emplace_back(convToBase3(i * 2));
    }
    ll sum = 0;
    for (auto e : ve) {
        sum += e;
    }
    ll A = floor((m - sum), n);
    for (auto& e : ve) {
        e += A;
    }
    ll sisa = m - (sum + A * n);
    ve[n - 1] += sisa;
    for (auto e : ve) {
        cout << e << ' ';
    }
    cout << '\n';
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
