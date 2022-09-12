#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++) {
        if (n % i != 0) continue;
        int ans = 0;
        for (int j = 0; j < i; j++) {
            vector<int> cnt(26);
            for (int k = j; k < n; k += i) {
                cnt[(s[k] - 'a')]++;
            }
            int mx = -1;
            for (int k = 0; k < 26; k++) {
                mx = max(mx, cnt[k]);
            }
            ans += ((n / i) - mx);
        }
        if (ans <= k) {
            cout << i << '\n';
            return;
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}
