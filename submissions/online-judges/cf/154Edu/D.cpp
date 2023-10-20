#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<int> pre(n), suf(n);
    pre[0] = 1;
    for (int i = 1; i < n; i++) {
        if (ar[i] >= ar[i - 1]) {
            pre[i] = pre[i - 1] + 1;
        } else {
            pre[i] = pre[i - 1];
        }
    }
    suf[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (ar[i] >= ar[i + 1]) {
            suf[i] = suf[i + 1] + 1;
        } else {
            suf[i] = suf[i + 1];
        }
    }
    int ans = min(pre[n - 1], suf[0] - 1);
    for (int i = 1; i < n; i++) {
        ans = min(ans, suf[i] - 1 + pre[i - 1]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}