#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using oset = tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = 1e9;
int n, k;

void solve() {
    cin >> n >> k;
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pre[i] = pre[i - 1] + 1LL * (x - k);
    }

    ll ans = 0;
    oset ose;
    ose.insert(make_pair(0, 0));
    for (int i = 1; i <= n; i++) {
        ans += ose.order_of_key(make_pair(pre[i] + 1, -1));
        ose.insert(make_pair(pre[i], i));
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