#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;
string s;

void solve() {
    // cin >> n >> k;
    // cin >> s;
    // int last = -1;
    // int ans = 0;
    // int aman = -1;
    // int pos = -1;
    // for (int i = 0; i < n; i++) {
    //     if (s[i] == '*') {
    //         pos = i;
    //         if (last == -1) {
    //             ans++;
    //             last = i;
    //         } else {
    //             if (i - last <= k) {
    //                 aman = i;
    //             } else {
    //                 last = aman;
    //                 aman = i;
    //                 ans++;
    //             }
    //         }
    //     }
    // }
    // if (last != pos) {
    //     ans++;
    // }
    // cout << ans << '\n';
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