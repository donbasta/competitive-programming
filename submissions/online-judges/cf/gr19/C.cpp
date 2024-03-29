#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    int mx = 0;
    ll tot = 0;
    for (int i = 2; i < n; i++) {
        mx = max(mx, ar[i]);
        tot += ar[i];
    }
    if (((tot & 1) && (n == 3)) || (mx == 1)) {
        cout << -1 << '\n';
        return;
    }
    cout << (tot + 1) / 2 << '\n';
    return;
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