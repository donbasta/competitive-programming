#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using point = pair<ll, ll>;

const int INF = 2e9;
const int N = 300;

int cross(point a, point b, point c) {
    ll dx1 = b.first - a.first;
    ll dy1 = b.second - a.second;
    ll dx2 = c.first - b.first;
    ll dy2 = c.second - b.second;
    ll cek = dx1 * dy2 - dy1 * dx2;
    return ((cek < 0) ? -1 : ((cek > 0) ? 1 : 0));
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<point> pt(n);
    for (int i = 0; i < n; i++) {
        cin >> pt[i].first >> pt[i].second;
    }
    bitset<N> bb[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if (cross(pt[i], pt[j], pt[k]) > 0) {
                    bb[i][j].set(k);
                }
            }
        }
    }

    ll ans = 1ll * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120;
    ll t3 = 0, t4 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                int cr = cross(pt[i], pt[j], pt[k]);
                if (cr <= 0) continue;
                int c1 = (bb[i][j] & bb[j][k] & bb[k][i]).count();
                t3 += c1 * (c1 - 1) / 2;
                int c2 = (bb[i][j] & bb[j][k] & bb[i][k]).count();
                int c3 = (bb[i][j] & bb[k][j] & bb[k][i]).count();
                int c4 = (bb[j][i] & bb[j][k] & bb[k][i]).count();
                t4 += c1 * (c2 + c3 + c4);
            }
        }
    }
    ans -= (t3 / 3 + t4 / 6);
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