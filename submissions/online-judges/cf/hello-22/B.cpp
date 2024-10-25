#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> segs(n);
    vector<ll> cost(n);
    for (int i = 0; i < n; i++) {
        ll l, r, c;
        cin >> l >> r >> c;
        segs[i] = make_pair(l, r);
        cost[i] = c;
    }

    map<ll, set<int>> ml, mr;
    map<pair<ll, ll>, ll> sg;
    ll mx = -1, mn = INF;
    for (int i = 0; i < n; i++) {
        ll l = segs[i].first, r = segs[i].second, c = cost[i];
        mx = max(mx, r);
        mn = min(mn, l);
        ml[l].insert(c);
        mr[r].insert(c);
        if (!sg.count(segs[i])) {
            sg[segs[i]] = c;
        } else {
            sg[segs[i]] = min(c, sg[segs[i]]);
        }

        ll tmp = *ml[mn].begin() + *mr[mx].begin();
        if (sg.count(make_pair(mn, mx))) {
            tmp = min(tmp, sg[make_pair(mn, mx)]);
        }
        cout << tmp << '\n';
    }
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