#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int c, d, ans;

void solve() {
    cin >> c >> d;
    if (c == d) {
        if (c == 0) {
            ans = 0;
        } else {
            ans = 1;
        }
    } else if ((c % 2) != (d % 2)) {
        ans = -1;
    } else {
        ans = 2;
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