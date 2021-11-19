#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve () {
    ll n, m;
    cin >> n >> m;
    cout << min(n * (m + 1), m * (n + 1)) << '\n';
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}