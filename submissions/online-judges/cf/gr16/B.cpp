
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string s;

void solve() {
    cin >> s;
    int n = (int) s.length();
    int last = -1;
    int block = 0;
    for (int i = 0; i < n; i++) {
        int now = s[i] - '0';
        if (now != last) {
            if (now == 0) block++; 
        }
        last = now;
    }
    // cerr << block << '\n';
    int ans;
    if (block == 0) {
        ans = 0;
    } else if (block == 1) {
        ans = 1;
    } else {
        ans = 2;
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