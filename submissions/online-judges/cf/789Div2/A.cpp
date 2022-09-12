#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(105);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    bool ok = false;
    if (cnt[0] >= 1) {
        ok = true;
    }
    bool dbl = false;
    for (int i = 1; i <= 100; i++) {
        if (cnt[i] > 1) {
            dbl = true;
        }
    }
    int ans = -1;
    if (ok) {
        ans = n - cnt[0];
    } else {
        if (dbl) {
            ans = n;
        } else {
            ans = n + 1;
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