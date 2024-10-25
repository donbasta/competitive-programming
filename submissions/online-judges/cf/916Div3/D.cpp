#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;
    for (auto& e : c) cin >> e;
    vector<pair<ll, int>> ap(n), bp(n), cp(n);
    for (int i = 0; i < n; i++) {
        ap[i] = make_pair(a[i], i);
        bp[i] = make_pair(b[i], i);
        cp[i] = make_pair(c[i], i);
    }
    sort(ap.begin(), ap.end());
    sort(bp.begin(), bp.end());
    sort(cp.begin(), cp.end());
    ll ans = 0;
    for (int x = n - 3; x <= n - 1; x++) {
        for (int y = n - 3; y <= n - 1; y++) {
            for (int z = n - 3; z <= n - 1; z++) {
                if (ap[x].second == bp[y].second) continue;
                if (ap[x].second == cp[z].second) continue;
                if (bp[y].second == cp[z].second) continue;
                ans = max(ans, ap[x].first + bp[y].first + cp[z].first);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}