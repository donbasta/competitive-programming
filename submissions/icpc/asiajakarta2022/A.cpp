#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using point = pair<ll, ll>;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<point> pt;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pt.emplace_back(x, y);
    }
    for (int i = 0; i < n; i++) {
        vector<pair<point, int>> tmp;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            point nw = make_pair(pt[j].first - pt[i].first, pt[j].second - pt[i].second);
            tmp.emplace_back(nw, j);
        }
    }
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