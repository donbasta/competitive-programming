#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    ll xr = 0;
    for (int i = 1; i <= n; i++) {
        ll ar;
        cin >> ar;
        xr ^= ar;
    }
    if ((n % 2 == 0) && xr) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        cout << n - ((n & 1) ? 2 : 3) << '\n';
        int j;
        for (int i = n; i >= 3; i -= 2) {
            cout << i << ' ' << i - 1 << ' ' << i - 2 << '\n';
            j = i;
        }
        for (int i = j + 2; i <= n; i += 2) {
            cout << i << ' ' << i - 1 << ' ' << i - 2 << '\n';
        }
    }
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