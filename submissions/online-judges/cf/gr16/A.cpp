#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll n, s, ans;

void solve() {
    cin >> n >> s;
    if (n & 1) n++;
    else n += 2;
    n /= 2;
    ans = s / n;
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