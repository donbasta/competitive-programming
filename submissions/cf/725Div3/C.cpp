#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, l, r;

void solve() {
    cin >> n >> l >> r;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    ll ans = 0;
    int mn = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] * 2 >= l && ar[i] * 2 <= r) mn++;
        int up = upper_bound(ar.begin(), ar.end(), r - ar[i]) - ar.begin();
        int lw = lower_bound(ar.begin(), ar.end(), l - ar[i]) - ar.begin();
        ans += 1LL * (up - lw);
    }
    ans -= mn;
    ans /= 2;
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