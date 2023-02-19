#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> hehe;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        hehe.emplace_back(l, r);
    }
    ll ans = hehe[0].first - 1;
    int cur = hehe[0].first;
    for (int i = 1; i < n; i++) {
        int l = hehe[i].first, r = hehe[i].second;
        if (cur < l) {
            ans += l - cur;
            cur = l;
        } else if (cur > r) {
            ans += cur - r;
            cur = r;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}