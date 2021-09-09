#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int l, r;

void solve() {
    cin >> l >> r;
    int u = (r / 2) + 1;
    int ans;
    if (u >= l) {
        ans = r - u;
    } else {
        ans = r % l;
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