#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    if (n >= 100) {
        cout << 9 << '\n';
    } else if (n <= 18) {
        cout << 0 << '\n';
    } else {
        cout << ((n + 1) / 10) - 1 << '\n';
    }
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