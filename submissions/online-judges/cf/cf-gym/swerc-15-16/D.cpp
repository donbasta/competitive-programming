#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int m, n;
    cin >> n >> m;
    vector<int> ar(n + m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ar[i + j]++;
        }
    }
    int mx = -1;
    for (int i = 2; i <= m + n; i++) {
        mx = max(mx, ar[i]);
    }
    for (int i = 2; i <= m + n; i++) {
        if (ar[i] == mx) {
            cout << i << '\n';
        }
    }
    return;
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