#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<pair<int, int>> ve;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        ve.emplace_back(l, i);
        ve.emplace_back(r, -i);
    }
    sort (ve.begin(), ve.end());
    ll ans = 0;
    int cur_event = 0;
    for (auto event : ve) {
        if (event.second < 0) {
            cur_event--;
        } else if (event.second > 0) {
            ans += cur_event;
            cur_event++;
        }
    }
    assert(cur_event == 0);
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