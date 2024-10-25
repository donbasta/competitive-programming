#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int N = 500;

int cross(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    ll dx1 = b.first - a.first;
    ll dy1 = b.second - a.second;
    ll dx2 = c.first - b.first;
    ll dy2 = c.second - b.second;
    ll cek = dx1 * dy2 - dy1 * dx2;
    if (cek < 0)
        return -1;
    else if (cek > 0)
        return 1;
    return 0;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> pt(n);
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
    bitset<N> bbb[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                int cr = cross(pt[i], pt[j], pt[k]);
                if (cr <= 0) continue;
                int cek = (bb[i][j] & bb[j][k] & bb[k][i]).count();
                if (cek == 0) {
                    bbb[i][j].set(k);
                }
            }
        }
    }

    ll ans = 0;
    ll convex = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += 1ll * bbb[i][j].count() * bbb[j][i].count();
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                int cr = cross(pt[i], pt[j], pt[k]);
                if (cr <= 0) continue;
                if (!bbb[i][j].test(k)) continue;
                int cek = (bbb[j][i] & bbb[j][k] & bbb[k][i]).count();
                convex += cek;
            }
        }
    }
    ans -= (convex / 2);
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