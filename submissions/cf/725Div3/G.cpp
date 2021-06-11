#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll x, y, a, b;

ll ceil(ll x, ll y) {
    return (x + y - 1) / y;
}

void solve() {
    cin >> x >> y >> a >> b;
    if (a == b) {
        cout << min(x / a, y / a) << '\n';
        return;
    }
    if (a < b) {
        swap(a, b);
        swap(x, y);
    }
    ll U = min({x / b, y / b, (x + y) / (a + b)});
    ll k = ceil((U * a - x), (a - b));
    if (U * b + k * (a - b) > y) U--;
    cout << U << '\n';
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