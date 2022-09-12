#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int ans = 0;
    if ((l2 > r1) || (r2 < l1)) {
        ans = l1 + l2;
    } else {
        ans = max(l1, l2);
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