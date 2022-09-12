#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ll tmp = 0;
        ll moves = 0;
        for (int j = i + 1; j < n; j++) {
            ll u = (tmp / ar[j]) + 1;
            moves += u;
            tmp = 1LL * ar[j] * u;
        }   
        tmp = 0;
        for (int j = i - 1; j >= 0; j--) {
            ll u = (tmp / ar[j]) + 1;
            moves += u;
            tmp = 1LL * ar[j] * u;
        }
        ans = min(ans, moves);
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