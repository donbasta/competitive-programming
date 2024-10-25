#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<vector<int>> cant(n);
    for (int i = 0; i < l; i++) {
        int c, d;
        cin >> c >> d;
        --c, --d;
        cant[c].push_back(d);
    }
    multiset<ll> se;
    for (int i = 0; i < m; i++) {
        se.insert(b[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto x : cant[i]) {
            se.erase(se.find(b[x]));
        }
        if (!se.empty()) {
            ans = max(ans, a[i] + *se.rbegin());
        }
        for (auto x : cant[i]) {
            se.insert(b[x]);
        }
    }
    assert(ans != 0);
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