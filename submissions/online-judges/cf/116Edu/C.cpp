#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> ar(n);

    vector<ll> pw(10);
    pw[0] = 1;
    for (int i = 1; i < 10; i++) {
        pw[i] = pw[i - 1] * 10;
    }

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ll penuh = (pw[ar[i + 1]] / pw[ar[i]]) - 1;
        if (penuh < k) {
            k -= penuh;
            ans += penuh * pw[ar[i]]; 
        } else if (penuh == k) {
            ans += ((k * pw[ar[i]]) + pw[ar[i + 1]]);
            k = 0;
            break;
        } else if (penuh > k) {
            ans += (k + 1) * pw[ar[i]];
            k = 0;
            break;
        }
    }
    if (k > 0) {
        ans += (k + 1) * pw[ar[n - 1]];
    }
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