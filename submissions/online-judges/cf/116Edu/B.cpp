#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll pw = 1;
    ll i = 0;
    while (pw <= k) {
        pw *= 2;
        i++;
    }
    ll ans = 0;
    if (n >= pw) {
        ll tmp = (n - pw + k - 1) / k;
        ans = (i + tmp);
    } else {
        while (pw > n) {
            pw /= 2, i--;
        }
        if (pw == n) {
            ans = i;
        } else {
            ans = i + 1;
        }
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