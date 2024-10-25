#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;
const ll MX = 1e17;

void el_psy_congroo() {
    int m;
    cin >> m;
    vector<ll> n(m), l(m), r(m), all(m);
    ll L = 0, R = 0;
    bool ok = false;
    vector<vector<ll>> ve(m);
    vector<unordered_map<ll, ll>> cnt(m);
    for (int i = 0; i < m; i++) {
        cin >> n[i] >> l[i] >> r[i];
        L += l[i], R += r[i];
        if (R > MX) {
            ok = true;
        }
        for (int j = 0; j < n[i]; j++) {
            ll tmp;
            cin >> tmp;
            ve[i].push_back(tmp);
        }
        for (int j = 0; j < n[i]; j++) {
            cin >> cnt[i][ve[i][j]];
            all[i] += cnt[i][ve[i][j]];
        }
    }
    if (ok) {
        cout << 0 << '\n';
        return;
    }
    set<ll> se;
    unordered_map<ll, vector<int>> mp;
    for (int i = 0; i < m; i++) {
        for (auto e : ve[i]) {
            if (e >= L && e <= R) {
                se.insert(e);
                mp[e].push_back(i);
            }
        }
    }
    if (se.size() < R - L + 1) {
        cout << 0 << '\n';
        return;
    }
    ll ret = INF;
    for (ll len = L; len <= R; len++) {
        ll cap = R;
        ll tam = 0;
        for (auto x : mp[len]) {
            cap -= r[x];
            ll avail = all[x] - cnt[x][len];
            if (avail > r[x]) {
                cap += r[x];
            } else if (avail < l[x]) {
                cap += l[x];
                tam += l[x] - avail;
            } else {
                cap += avail;
            }
        }
        ll tmp = tam + max(0ll, len - cap);
        // cerr << len << ' ' << tmp << '\n';
        ret = min(ret, tmp);
    }
    cout << ret << '\n';
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