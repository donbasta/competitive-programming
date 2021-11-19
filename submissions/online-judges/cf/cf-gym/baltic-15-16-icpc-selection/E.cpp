#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int _n) : n(_n) {
        bit.resize(n + 1);
    }
    void upd(int pos, int val) {
        while (pos <= n) {
            bit[pos] += val;
            pos += (pos & (-pos));
        }
    }
    int get(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += bit[pos];
            pos -= (pos & (-pos));
        }
        return ret;
    }
    int get(int l, int r) {
        if (l > r) {
            return 0;
        }
        return get(r) - get(l - 1);
    }
};

void solve () {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        int a = i + 1, b = p[i];
        if (a > b) swap(a, b);
        ve.emplace_back(a, -b);
    }
    sort(ve.begin(), ve.end());
    BIT bit(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int a = ve[i].first, b = -ve[i].second;
        ans += bit.get(a + 1, b - 1);
        bit.upd(a, 1);
        bit.upd(b, 1);
    }
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}