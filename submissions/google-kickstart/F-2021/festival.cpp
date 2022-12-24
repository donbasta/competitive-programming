#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using oset = tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

int d, n, k;

void solve() {
    cin >> d >> n >> k;
    vector<vector<pair<int, int>>> in(d + 1), out(d + 1);
    for (int i = 0; i < n; i++) {
        int h, s, e;
        cin >> h >> s >> e;
        in[s].emplace_back(h, i);
        out[e].emplace_back(h, i);
    }

    oset ose;
    ll tmp = 0;
    ll ans = 0;
    int sz = 0;
    for (int i = 1; i <= d; i++) {
        for (auto attr : in[i]) {
            if (ose.order_of_key(attr) < k) {
                if (sz >= k) {
                    auto j = ose.find_by_order(k - 1);
                    tmp -= j->first;
                }
                tmp += attr.first;
            }
            ose.insert(attr);
            sz++;
        }
        ans = max(ans, tmp);
        for (auto attr : out[i]) {
            if (ose.order_of_key(attr) < k) {
                if (sz > k) {
                    auto j = ose.find_by_order(k);
                    tmp += j->first;
                }
                tmp -= attr.first;
            }
            ose.erase(attr);
            sz--;
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
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}