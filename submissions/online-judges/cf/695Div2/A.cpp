#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    if (n == 1) {
        cout << 9 << '\n';
        return;
    }
    if (n == 2) {
        cout << 98 << '\n';
        return;
    }
    cout << 989;
    int c = 0;
    for (int i = 4; i <= n; i++) {
        cout << c;
        c = (c + 1) % 10;
    }
    cout << '\n';
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