#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

ll func(ll x) {
    ll sq = x * x;
    ll ans = sq * (sq - 1) / 2;
    ll cant = x * x * 4 - x * 12 + 8;
    ans -= cant;
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i == 1)
            cout << 0 << '\n';
        else if (i == 2)
            cout << 6 << '\n';
        else if (i == 3)
            cout << 28 << '\n';
        else
            cout << func(i) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}