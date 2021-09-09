#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    if (n % 2 == 0) {
        for (int i = 1; i <= n / 2; i++) {
            cout << 2 * i << ' ' << 2 * i - 1 << ' ';
        }
    } else {
        cout << 3 << ' ' << 1 << ' ' << 2 << ' ';
        for (int i = 4; i <= n; i += 2) {
            cout << i + 1 << ' ' << i << ' '; 
        }
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