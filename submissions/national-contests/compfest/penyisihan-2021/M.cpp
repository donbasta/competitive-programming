#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll M = 17081945;
    ll pw = 0;
    while (M % 5 == 0) {
        M /= 5;
        pw++;
    }
    ll a, b;
    cin >> a >> b;
    bool ok = (a * 2 <= pw * b);
    cout << (ok ? "Ya" : "Tidak") << '\n';
    return;
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