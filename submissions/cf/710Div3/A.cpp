#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll n, m, x;

void solve() {
    cin >> n >> m >> x;
    ll row, col;
    x--;
    col = x / n;
    row = x % n;
    x = row * m + col + 1;
    cout << x << '\n';
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