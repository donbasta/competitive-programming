#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;

void solve() {
    cin >> n >> m;
    vector<int> ar(n);
    vector<int> cnt(4);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    ll ans = 0;
    if (m == 2) {
        for (int i = 0; i < n; i++) {
            ans += ar[i];
        }
    } else if (m == 3) {
        for (int i = 0; i < n; i++) {
            cnt[ar[i]]++;
        }
        ans += 2 * min((n + 1) / 2, cnt[2]);
        cnt[2] -= min((n + 1) / 2, cnt[2]);
        ans += (cnt[2] + cnt[1]);
    } else if (m == 4) {
        for (int i = 0; i < n; i++) {
            cnt[ar[i]]++;
        }
        ans += 3 * min((n + 1) / 2, cnt[3]);
        bool enough = (n + 1) / 2 > cnt[3];
        cnt[3] -= min((n + 1) / 2, cnt[3]);
        if (cnt[3] == 0) {
            if (enough) ans += 2 * (cnt[2] >= 1);
            ans += (cnt[3] + cnt[1]);
        } else if (cnt[3] > 0) {
            ans += (cnt[3] + cnt[1]);
        }
    }
    cout << ans << '\n';
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