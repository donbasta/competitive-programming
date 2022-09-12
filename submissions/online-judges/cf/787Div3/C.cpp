#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string s;
    cin >> s;
    int n = (int) s.length();
    int l = -1, r = n;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') l = i;
        if (s[i] == '0' && !found) {
            r = i, found = true;
        }
    }
    int ans = 0;
    if (r < l) {
        ans = 0;
    } else if (l == -1 && r == n) {
        ans = n;
    } else if (l == -1) {
        ans = (r + 1);
    } else if (r == n) {
        ans = (n - l);
    } else {
        ans = (r - l + 1);
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