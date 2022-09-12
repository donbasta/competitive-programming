#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int sum = (a + b + c + d);
    int ans;
    if (sum == 4) {
        ans = 2;
    } else if (sum >= 1) {
        ans = 1;
    } else if (sum == 0) {
        ans = 0;
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