#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, q, m;

void solve() {
    cin >> n >> q >> m;
    vector<array<int, 3>> queries;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < q; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        --l, --r;
        queries.push_back({t, l, r});
    }
    reverse(queries.begin(), queries.end());
    while (m--) {
        int cur;
        cin >> cur;
        --cur;
        for (auto& qu: queries) {
            auto [t, l, r] = qu;
            if (t == 1) {
                if (cur >= l && cur <= r) {
                    cur--;
                    if (cur < l) cur = r;
                }
            } else if (t == 2) {
                if (cur >= l && cur <= r) {
                    cur = r + l - cur;
                }
            }
        }
        cout << ar[cur] << ' ';
    }
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