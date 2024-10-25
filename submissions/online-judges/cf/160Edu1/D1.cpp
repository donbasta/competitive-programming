#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 998244353;

struct BIT {
    vector<ll> tree;
    int n;
    BIT(int n) : tree(n + 1), n(n) {}
    void upd(int x, int val) {
        x++;
        while (x <= n) {
            tree[x] = (tree[x] + val) % MOD, x += x & -x;
        }
    }
    ll get(int x) {
        x++;
        ll ret = 0;
        while (x) {
            ret = (ret + tree[x]) % MOD, x -= x & -x;
        }
        return ret;
    }
    ll get(int x, int y) {
        ll ret = (get(y) - get(x - 1)) % MOD;
        if (ret < 0) ret += MOD;
        return ret;
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> p(n), l(n, -1), mn(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    mn[n - 1] = p[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        mn[i] = min(mn[i + 1], p[i]);
    }
    vector<pair<int, int>> ve;
    for (int i = n - 1; i >= 0; i--) {
        while (!ve.empty() && ve.back().first > p[i]) {
            l[ve.back().second] = i;
            ve.pop_back();
        }
        ve.emplace_back(p[i], i);
    }
    BIT bit(n);
    vector<ll> F(n);
    for (int i = 0; i < n; i++) {
        ll tmp = 0;
        if (l[i] == -1) {
            tmp++;
        }
        tmp = (tmp + bit.get(max(0, l[i]), i - 1)) % MOD;
        bit.upd(i, F[i] = tmp);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cerr << i << ' ' << F[i] << '\n';
        if (i == n - 1 || mn[i + 1] > p[i]) {
            ans = (ans + F[i]) % MOD;
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
        el_psy_congroo();
    }

    return 0;
}