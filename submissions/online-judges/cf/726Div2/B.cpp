#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll dis(ll a, ll b, ll c, ll d) {
    return abs(a - c) + abs(b - d);
}

void solve() {
    ll n, m, ii, jj;
    cin >> n >> m >> ii >> jj;
    vector<pair<ll, ll>> cor = {{1, m}, {n, 1}, {1, 1}, {n, m}};
    ll mx = -1;
    tuple<ll, ll, ll, ll> pos;
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            ll ans1 = dis(ii, jj, cor[i].first, cor[i].second);
            ans1 += dis(cor[i].first, cor[i].second, cor[j].first, cor[j].second);
            ans1 += dis(cor[j].first, cor[j].second, ii, jj);
            if (ans1 > mx) {
                mx = ans1;
                pos = make_tuple(cor[i].first, cor[i].second, cor[j].first, cor[j].second);
            }
        }
    }
    cout << get<0>(pos) << ' ' << get<1>(pos) << ' ' << get<2>(pos) << ' ' << get<3>(pos) << ' ';
    cout << '\n';
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