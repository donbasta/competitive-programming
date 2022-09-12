#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string s;
    cin >> s;
    string cs = s;
    sort(s.begin(), s.end());
    int n = s.length();
    char ans;
    if (n == 2) {
        if (cs == s) {
            ans = s[1];
        } else {
            ans = s[0];
        }
    } else {
        ans = s[0];
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