#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

ll fn(ll len) {
    return (len - 1) * len * (len + 1) / 6;
}

void solve() {
    int n, q;
    cin >> n >> q;
    set<pair<pair<int, int>, ll>> se;
    se.emplace(make_pair(0, n + 1), fn(n + 1));
    ll ans = fn(n + 1);
    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        auto it = se.lower_bound(make_pair(make_pair(c, 0), 0));
        if (it != se.end() && it->first.first == c) {
            auto prv = it;
            --prv;
            auto it_x = *it;
            auto prv_x = *prv;
            int le = prv_x.first.first;
            int ri = it_x.first.second;
            ans -= it_x.second;
            ans -= prv_x.second;
            ans += fn(ri - le);
            se.erase(it_x);
            se.erase(prv_x);
            se.emplace(make_pair(le, ri), fn(ri - le));
        } else {
            --it;
            auto it_x = *it;
            int le = it_x.first.first;
            int ri = it_x.first.second;
            ans -= it_x.second;
            ans += fn(c - le);
            ans += fn(ri - c);
            se.erase(it_x);
            se.emplace(make_pair(le, c), fn(c - le));
            se.emplace(make_pair(c, ri), fn(ri - c));
        }
        cout << ans << '\n';
    }
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