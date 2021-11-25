#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int r, c;
    cin >> r >> c;
    vector<string> s(r);
    for (int i = 0; i < r; i++) {
        cin >> s[i];
    }
    int a, b;
    cin >> a >> b;
    vector<string> t(a);
    for (int i = 0; i < a; i++) {
        cin >> t[i];
    }
    int ans = 0;
    for (int i = 0; i + a - 1 < r; i++) {
        for (int j = 0; j + b - 1 < c; j++) {
            bool ok = true;
            for (int ii = 0; ii < a; ii++) {
                for (int jj = 0; jj < b; jj++) {
                    ok &= ((t[ii][jj] == '?') || (t[ii][jj] == s[i + ii][j + jj]));
                }
            }
            if (ok) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
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