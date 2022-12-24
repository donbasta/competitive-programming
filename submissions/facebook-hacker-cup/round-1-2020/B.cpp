#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MAX = 1e10;

int n, m, k, s;
ll a[2], b[2], c[2], d[2];
vector<ll> p, q;

bool ok(ll time) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        int nj = j;
        while (nj < m && (min(abs(p[i] - q[j]), abs(p[i] - q[nj])) + abs(q[j] - q[nj]) <= time))
            nj++;
        j = nj;
    }
    return j == m;
}

void solve() {
    cin >> n >> m >> k >> s;
    assert(s == 0);
    p.resize(n);
    q.resize(m);
    for (int i = 0; i < k; i++) {
        cin >> p[i];
    }
    cin >> a[0] >> b[0] >> c[0] >> d[0];
    for (int i = 0; i < k; i++) {
        cin >> q[i];
    }
    cin >> a[1] >> b[1] >> c[1] >> d[1];
    for (int i = k; i < n; i++) {
        p[i] = (((a[0] * p[i - 2] % d[0]) + (b[0] * p[i - 1] % d[0]) + c[0]) % d[0]) + 1;
    }
    for (int i = k; i < m; i++) {
        q[i] = (((a[1] * q[i - 2] % d[1]) + (b[1] * q[i - 1] % d[1]) + c[1]) % d[1]) + 1;
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    ll l = 1, r = MAX, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}