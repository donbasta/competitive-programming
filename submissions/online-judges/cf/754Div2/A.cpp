#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve () {
    ll a, b, c;
    cin >> a >> b >> c;
    ll sum = (a + c + b);
    if (sum % 3 == 0) {
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}