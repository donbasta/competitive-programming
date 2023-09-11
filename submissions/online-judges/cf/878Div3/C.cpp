#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int cur = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] <= q) {
            cur++;
            if (cur >= k) {
                ans += (cur - k + 1);
            }
        } else {
            cur = 0;
        }
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