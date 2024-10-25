#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    vector<ll> p(2), t(2);
    for (int i = 0; i < 2; i++) {
        cin >> p[i] >> t[i];
    }
    ll h, s;
    cin >> h >> s;
    ll bat = (h + p[0] + p[1] - s - 1) / (p[0] + p[1] - s);
    ll ret = 1e18;
    for (ll i = 0; i <= bat; i++) {
        ll tm = i * max(t[0], t[1]);
        ll sisa = h - i * (p[0] + p[1] - s);
        set<pair<ll, int>> se;
        se.emplace(tm + t[0], 0);
        se.emplace(tm + t[1], 1);
        while (sisa > 0) {
            if (se.begin()->first == (--se.end())->first) {
                tm = se.begin()->first;
                sisa -= (p[0] + p[1] - s);
                se.clear();
                se.emplace(tm + t[0], 0);
                se.emplace(tm + t[1], 1);
            } else {
                tm = se.begin()->first;
                int idx = se.begin()->second;
                sisa -= (p[idx] - s);
                pair<ll, int> nx;
                nx.first = tm + t[idx];
                nx.second = idx;
                se.erase(se.begin());
                se.emplace(nx);
            }
        }
        ret = min(ret, tm);
    }
    cout << ret << '\n';
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