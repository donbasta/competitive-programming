#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string s;
    cin >> s;
    int len = s.length();
    if (len <= 2) {
        cout << 0 << '\n';
        return;
    }
    vector<int> cnt(2);
    for (auto c : s) {
        cnt[c - '0']++;
    }
    int ans = min(cnt[0], cnt[1]) - (cnt[0] == cnt[1]);
    cout << ans << '\n';
    return;
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