#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int M = 1e5;

vector<pair<int, int>> A[M + 5], B[M + 5];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            A[x1].emplace_back(y1, y2);
        } else if (y1 == y2) {
            B[x1].emplace_back(1, y1);
            B[x2].emplace_back(-1, y1);
        }
    }
    for (int i = 1; i <= M; i++) {
        sort(B[i].begin(), B[i].end());
        reverse(B[i].begin(), B[i].end());
        sort(A[i].begin(), A[i].end());
    }
    ordered_set oset;
    ll ans = 0;
    for (int i = 1; i <= M; i++) {
        int t = 0;
        int sz = (int)B[i].size();
        for (; t < sz; t++) {
            if (B[i][t].first == -1) break;
            oset.insert(B[i][t].second);
        }
        for (auto seg : A[i]) {
            ans += oset.order_of_key(seg.second + 1) - oset.order_of_key(seg.first);
        }
        for (; t < sz; t++) {
            oset.erase(B[i][t].second);
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