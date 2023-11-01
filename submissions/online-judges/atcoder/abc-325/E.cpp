#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void el_psy_congroo() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<vector<ll>> d(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    vector<ll> d1(n, INF), d2(n, INF);
    set<pair<ll, int>> se;
    se.emplace(0, 0);
    d1[0] = 0;
    while (!se.empty()) {
        int v = se.begin()->second;
        ll dv = se.begin()->first;
        se.erase(se.begin());
        if (dv != d1[v]) continue;
        for (int i = 0; i < n; i++) {
            ll D = d[v][i];
            if (d1[i] > d1[v] + D * a) {
                d1[i] = d1[v] + D * a;
                se.emplace(d1[i], i);
            }
        }
    }
    se.clear();
    se.emplace(0, n - 1);
    d2[n - 1] = 0;
    while (!se.empty()) {
        int v = se.begin()->second;
        ll dv = se.begin()->first;
        se.erase(se.begin());
        if (dv != d2[v]) continue;
        for (int i = 0; i < n; i++) {
            ll D = d[v][i];
            if (d2[i] > d2[v] + D * b + c) {
                d2[i] = d2[v] + D * b + c;
                se.emplace(d2[i], i);
            }
        }
    }
    ll ans = min(d1[n - 1], d2[0]);
    for (int i = 1; i < n - 1; i++) {
        ans = min(ans, d1[i] + d2[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}