#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<string> p(n);
    ll grid = 0;
    vector<ll> pc(n + 1), pr(n + 1), r(n + 1), c(n + 1);
    vector<vector<ll>> part(n + 1, vector<ll>(n + 1));
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        for (int j = 0; j < n; j++) {
            grid += (p[i][j] == 'B');
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r[i + 1] += (p[i][j] == 'B');
            c[j + 1] += (p[i][j] == 'B');
        }
    }
    for (int i = 1; i <= n; i++) pc[i] = (pc[i - 1] + c[i]);
    for (int i = 1; i <= n; i++) pr[i] = (pr[i - 1] + r[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll x = part[i + 1][j];
            ll y = part[i][j + 1];
            ll z = part[i][j];
            part[i + 1][j + 1] = x + y - z + (p[i][j] == 'B');
        }
    }

    auto get = [&](int p, int q) -> ll {
        p++, q++;
        ll pa = (p) / n;
        ll qa = (q) / n;
        ll pb = p % n;
        ll qb = q % n;
        ll ans = pa * qa * grid;
        ans += (pc[qb] * pa);
        ans += (pr[pb] * qa);
        ans += part[pb][qb];
        return ans;
    };

    for (int i = 0; i < q; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll x = get(c, d);
        ll y = get(c, b - 1);
        ll z = get(a - 1, d);
        ll t = get(a - 1, b - 1);
        ll ans = (x - y - z + t);
        cout << ans << '\n';
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