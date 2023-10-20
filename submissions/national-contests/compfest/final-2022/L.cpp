#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ve;
    vector<ll> ar(n);
    set<ll> se;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        se.insert(x);
        ar[i] = x;
        ve.emplace_back(x, i);
    }
    sort(ve.begin(), ve.end());
    vector<int> to(n);
    for (int i = 0; i < n; i++) {
        to[ve[i].second] = i;
    }
    vector<bool> vis(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        int cur = to[i];
        if (cur == i) continue;
        vector<int> tmp;
        tmp.push_back(i);
        while (cur != i) {
            vis[cur] = true;
            tmp.push_back(cur);
            cur = to[cur];
        }
        for (auto e : tmp) se.erase(ar[e]);
        ll sum = 0;
        ll sum2 = 0;
        ll mn = 1e9;
        int sz = tmp.size();
        for (int j = 0; j < sz; j++) {
            sum += ar[tmp[j]];
            sum2 += ar[tmp[j]];
            mn = min(mn, ar[tmp[j]]);
        }
        sum += mn * (sz - 2);
        if (!se.empty()) {
            ll bruh = *se.begin();
            sum = min(sum, sum2 + mn + bruh * (sz + 1));
        }
        ans += sum;
        for (auto e : tmp) se.insert(ar[e]);
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