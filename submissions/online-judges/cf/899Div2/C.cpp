#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> ar(n + 1);
    vector<int> idx;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        if (ar[i] > 0) {
            idx.emplace_back(i);
        }
    }
    int l = 0;
    int sz = (int)idx.size();
    while (l < sz && (idx[l] % 2 == 0)) {
        l++;
    }
    for (int i = l; i < sz; i++) {
        ans += ar[idx[i]];
    }
    if (l == 0) {
        cout << ans << '\n';
        return;
    }
    ll lol = 0;
    ll suf = ar[idx[l - 1]];
    for (int i = l - 1; i >= 0; i--) {
        ll tmp = -INF;
        int until = (i > 0 ? idx[i - 1] + 1 : 1);
        for (int j = idx[i] - 1; j >= until; j--) {
            if (j % 2 == 0)
                tmp = max(tmp, 0ll);
            else
                tmp = max(tmp, ar[j]);
        }
        lol = max(lol, tmp + suf);
        if (idx[i] >= 4) {
            lol = max(lol, suf);
        }
        if (i > 0) suf += ar[idx[i - 1]];
    }
    ans += lol;
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