#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    ll sum = 0;
    vector<ll> a(3), tot(3);
    vector<vector<ll>> ve(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < a[i]; j++) {
            ll t;
            cin >> t;
            sum += t;
            ve[i].emplace_back(t);
            tot[i] += t;
        }
        sort(ve[i].begin(), ve[i].end());
    }
    ll sub = INF;
    for (int i = 0; i < 3; i++) {
        int ii = (i + 1) % 3, iii = (i + 2) % 3;
        if (a[ii] == 1) {
            sub = min(sub, ve[ii][0]);
        }
        if (a[iii] == 1) {
            sub = min(sub, ve[iii][0]);
        }
        if (a[ii] == 2) {
            sub = min(sub, ve[ii][0] + ve[ii][1]);
        }
        if (a[iii] == 2) {
            sub = min(sub, ve[iii][0] + ve[iii][1]);
        }
        sub = min(sub, ve[ii][0] + ve[iii][0]);
        sub = min(sub, tot[ii]);
        sub = min(sub, tot[iii]);
    }
    sum -= 2LL * sub;
    cout << sum << '\n';
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