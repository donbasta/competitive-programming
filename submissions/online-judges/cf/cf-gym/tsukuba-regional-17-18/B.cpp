#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 20;
pii p[M], g[M][M];
int m, ans;

pii grad(pii a, pii b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    int gcd = __gcd(dx, dy);
    dx /= gcd;
    dy /= gcd;
    if (dx == 0 && dy < 0) dy = -dy;
    if (dx < 0) dx = -dx, dy = -dy;
    return make_pair(dx, dy);
}

void bf(int idx, vector<int>& ve, int open) {
    if (open > m / 2) return;
    if (idx == m) {
        assert(open == 0);
        map<pii, int> mp;
        for (int i = 0; i < (int)ve.size(); i++) {
            pii arah = g[i][ve[i]];
            mp[arah]++;
        }
        int mx = 0;
        for (auto i : mp) {
            int tmp = i.second;
            tmp /= 2;
            mx += tmp * (tmp - 1) / 2;
        }
        ans = max(ans, mx);
        return;
    }
    if ((open < m / 2) && (m - 1 - idx >= open + 1)) {
        bf(idx + 1, ve, open + 1);
    }
    if (open > 0) {
        for (int i = 0; i < idx; i++) {
            if (ve[i] == -1) {
                ve[i] = idx; ve[idx] = i;
                bf(idx + 1, ve, open - 1);
                ve[i] = -1, ve[idx] = -1;
            }
        }
    }
}

void solve() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> p[i].first >> p[i].second;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) continue;
            g[i][j] = grad(p[i], p[j]);
        }
    }
    vector<int> ve(m, -1);
    bf(0, ve, 0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}