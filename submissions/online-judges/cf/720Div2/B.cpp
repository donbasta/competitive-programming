#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    int mn = 2e9;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= mn) {
            mn = x;
            idx = i;
        }
    }
    cout << n - 1 << '\n';
    for (int i = 0; i < n; i++) {
        if (i == idx) continue;
        if (abs(idx - i) % 2 == 0) {
            cout << i + 1 << ' ' << idx + 1 << ' ' << mn << ' ' << mn << '\n';
        } else {
            cout << i + 1 << ' ' << idx + 1 << ' ' << mn + 1 << ' ' << mn << '\n';
        }
    }
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