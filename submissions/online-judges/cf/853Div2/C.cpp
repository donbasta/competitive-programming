#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

ll F(ll x) {
    return x * (x - 1) / 2;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ar(n);
    vector<int> cnt(n + m + 1);
    vector<int> last(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 1; i <= m; i++) {
        int p, v;
        cin >> p >> v;
        --p;
        cnt[ar[p]] += (i - last[p]);
        ar[p] = v;
        last[p] = i;
    }
    for (int i = 0; i < n; i++) {
        cnt[ar[i]] += (m + 1 - last[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= m + n; i++) {
        ans += F(m + 1) - F(m + 1 - cnt[i]);
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