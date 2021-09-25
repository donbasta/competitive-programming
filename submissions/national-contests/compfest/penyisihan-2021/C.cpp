#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;

ll bit[N + 5];
int n, m;

void upd(int x, ll val) {
    while (x <= n) {
        bit[x] += val;
        x += (x & (-x));
    }
}

ll get(int x) {
    ll res = 0;
    while (x > 0) {
        res += bit[x];
        x -= (x & (-x));
    }
    return res;
}

ll get(int l, int r) {
    return get(r) - get(l - 1);
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> p(n + 1, vector<int>(m + 1));
    vector<vector<int>> ve(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j ++) {
            cin >> p[i][j];
            ve[p[i][j]][j] = i;
        }
    }
    ll ans = 0;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            int a = p[j][i];
            int nx = ve[a][i + 1];
            ans += get(nx + 1, n);
            upd(nx, 1);
        }
        for (int j = 1; j <= n; j++) {
            bit[j] = 0;
        }
    }
    cout << ans << '\n';
    return;
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