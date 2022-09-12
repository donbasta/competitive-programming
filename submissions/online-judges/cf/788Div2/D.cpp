#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll M = 1e5;
vector<pair<ll, ll>> C;

void solve() {
    ll n;
    cin >> n;
    int u = lower_bound(C.begin(), C.end(), make_pair((n + 1) / 2, 0LL)) - C.begin();
    ll A = C[u].first, B = C[u].second;
    // cerr << A << ' ' << B << '\n';

    ll ans;
    if (B == 1) {
        ans = sqrt(A * 3);
    } else if (B == 2) {
        ans = sqrt(A * 3 + 1);
    } else if (B == 3) {
        ans = sqrt(A * 3 + 1);
    }   
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (ll i = 0; i <= M; i++) {
        ll wow = i * i * 3;
        C.emplace_back(wow, 1);
        C.emplace_back(wow + i * 2, 2);
        C.emplace_back(wow + i * 4 + 1, 3);
    }
    sort(C.begin(), C.end());

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}