#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> ve;
    for (int i = 1; i <= n; i++) {
        int x, c;
        cin >> x >> c;
        ve.emplace_back(x, c);
    }
    sort (ve.begin(), ve.end());
    for (int i = 0; i < n; i++) {
        pre[i + 1][0] = pre[i][0];
        pre[i + 1][1] = pre[i][1];
        pre[i + 1][ve[i].second]++;
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        int pos = lower_bound(ve.begin(), ve.end(), make_pair(x + 1, -1)) - ve.begin();
        for (int i = 0; i <= k; i++) {
            int dl = x - ve[pos - i].first;
            int dr = ve[pos + k - i - 1].first -  x;
            int dl1 = x - ve[pos - i - 1].first;
            int dr1 = ve[pos + k - i].first - x;
            if ((dr1 <= dl) ||)
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}