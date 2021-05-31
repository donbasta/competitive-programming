#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void ans(int p, int q, int r) {
    cout << p << ' ' << q << ' ' << r << '\n';
}

int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
    }
    cout << 3 * n << '\n';
    for (int i = 1; i < n; i += 2) {
        for (int j = 0; j < 3; j++) {
            ans(1, i, i + 1);
            ans(2, i, i + 1);
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