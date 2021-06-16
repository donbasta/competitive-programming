#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<ll> ar(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        sum += ar[i];
    }
    if (sum % n != 0) {
        cout << -1 << '\n';
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] > (sum / n)) ans++;
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