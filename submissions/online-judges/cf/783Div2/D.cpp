#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        sum += ar[i];
    }
    int ans = 0;
    if (sum > 0) {
        ans = n;
    } else {

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