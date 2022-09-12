#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> rbt(n);
    for (int i = 0; i < n; i++) {
        cin >> rbt[i];
    }
    int topmost = n, leftmost = m;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (rbt[i][j] == 'R') {
                topmost = min(topmost, i);
                leftmost = min(leftmost, j);
            }
        }
    }
    bool ok = rbt[topmost][leftmost] == 'R';
    cout << (ok ? "YES" : "NO") << '\n';
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