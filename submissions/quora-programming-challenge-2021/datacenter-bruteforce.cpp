#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

int n;
vector<pair<ll, ll>> loc;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        loc.emplace_back(x, y);
    }
    ll idx = -1, ans = INF;
    for (int i = 0; i < n; i++) {
        ll tmp = 0;
        for (int j = 0; j < n; j++) {
            tmp += max(abs(loc[i].first - loc[j].first), abs(loc[i].second - loc[j].second));
        }
        if (tmp < ans) {
            ans = tmp;
            idx = i;
        }
    }
    cout << idx + 1 << '\n';
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