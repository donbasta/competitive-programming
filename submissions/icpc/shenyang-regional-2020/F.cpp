#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> ar(n + 2), mx(n + 2), mn(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    mx[1] = ar[1], mn[n] = ar[n];
    for (int i = 2; i <= n; i++) {
        mx[i] = max(mx[i - 1], ar[i]);
    }
    for (int i = n - 1; i >= 1; i--) {
        mn[i] = min(mn[i + 1], ar[i]);
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (mx[i] <= mn[i + 1]) ans++;
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