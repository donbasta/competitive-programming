#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll c, r, s;
    cin >> c >> r >> s;
    ll best = c / s;
    if (r == 0) {
        best = (c + s - 1) / s;
    }
    ll worst = -1;
    if (s == 1) {
        worst = c;
    } else {
        if (r * (s - 1) >= c) {
            worst = 0;
        } else {
            worst = (c - r * (s - 1) + (s - 1)) / s;
        }
    }
    cout << best << ' ' << worst << '\n';
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