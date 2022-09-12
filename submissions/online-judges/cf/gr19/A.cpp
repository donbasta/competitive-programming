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
    vector<int> mx(n + 5), mn(n + 5);
    for (int i = 1; i <= n; i++) {
        mx[i] = max(mx[i - 1], ar[i]);
    }
    mn[n + 1] = 1e9 + 1;
    for (int i = n; i >= 1; i--) {
        mn[i] = min(mn[i + 1], ar[i]);
    }
    bool ok = false;
    for (int i = 1; i < n; i++) {
        ok |= (mx[i] > mn[i + 1]);
    }
    cout << (ok ? "YES" : "NO") << '\n';
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