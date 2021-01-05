#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m, c1 = 0, c2 = 0, mx1 = 0, mx2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        mx1 = max(mx1, c1 + r);
        c1 += r;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        mx2 = max(mx2, c2 + b);
        c2 += b;
    }
    cout << mx1 + mx2 << '\n';
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