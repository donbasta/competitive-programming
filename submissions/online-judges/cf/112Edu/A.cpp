#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll n;

void solve() {
    cin >> n;
    ll bat = max(3LL, (n + 1) / 2);
    ll ans = bat * 5;
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