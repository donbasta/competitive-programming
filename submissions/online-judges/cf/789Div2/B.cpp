#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i + 1]) {
            ans++;
        }
    }
    int last = -1;
    int seg = 0;
    for (int i = 0; i < n; i += 2) {
        if (s[i] == s[i + 1]) {
            int lol = s[i] - '0';
            if (lol != last) {
                last = lol;
                seg++;
            }
        }
    }
    if (seg == 0) {
        seg = 1;
    }
    cout << ans << ' ' << seg << '\n';
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