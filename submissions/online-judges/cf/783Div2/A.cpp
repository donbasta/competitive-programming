#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    int ans = 0;
    if ((n == 1) && (m > 2)) ans = -1;
    else {
        ans = (2 * (m - 1)) - ((m - n) & 1);
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