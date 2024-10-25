#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using frac = pair<ll, ll>;

const ll INF = 1e12;

void el_psy_congroo() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<P> pt(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pt[i] = P(x, y);
    }
    vector<ll> x1(m), x2(m), y(m);
    for (int i = 0; i < m; i++) {
        cin >> x1[i] >> x2[i] >> y[i];
    }
    vector<P> qu(q);
    for (int i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;
        qu[i] = P(x, y);
    }

    vector<ll> ret(q);

    vector<vector<pair<frac, frac>>> isect(n, vector<pair<frac, frac>>(m));
    vector<vector<pair<frac, frac>>> isect2(q, vector<pair<frac, frac>>(m));
    vector<vector<bool>> ada(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pt[i].y <= y[j]) continue;
            ada[i][j] = true;
            isect[i][j].first = make_pair(x1[j] * y[j] - pt[i].x * pt[i].y, y[j] - pt[i].y);
            isect[i][j].second = make_pair(x2[j] * y[j] - pt[i].x * pt[i].y, y[j] - pt[i].y);
        }
    }
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < m; j++) {
            isect2[i][j].first = make_pair(qu[i].x * y[j] - x1[j] * qu[i].y, y[j] - qu[i].y);
            isect2[i][j].second = make_pair(qu[i].x * y[j] - x2[j] * qu[i].y, y[j] - qu[i].y);
        }
    }
    for (int i = 0; i < q; i++) {
        ll ans = n;
        frac L = make_pair(-INF, 1), R = make_pair(INF, 1);
        for (int mask = 1; mask < (1 << m); mask++) {
            for (int j = 0; j < m; j++) {
                if (!((mask >> j) & 1)) continue;
                L = max(L, isect2[i][j].first);
                R = min(R, isect2[i][j].second);
            }
        }
        if (L > R) continue;
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