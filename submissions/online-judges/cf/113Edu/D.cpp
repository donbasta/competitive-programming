#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<int> x(n), y(m);
    vector<int> ca(m), cb(n);
    map<int, bool> mx, my;
    map<pair<int, int>, int> ma, mb;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        mx[x[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
        my[y[i]] = true;
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        bool aa = (mx.find(a) != mx.end());
        bool bb = (my.find(b) != my.end());
        if (aa && bb) {
            continue;
        } else if (aa) {
            int au = upper_bound(y.begin(), y.end(), b) - y.begin();
            ca[au]++;
            ma[make_pair(a, au)]++;
        } else if (bb) {
            int bu = upper_bound(x.begin(), x.end(), a) - x.begin();
            cb[bu]++;
            mb[make_pair(b, bu)]++;
        } else {
            assert(false);
        }
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        // cerr << i << ' ' << ca[i] << '\n';
        ans += 1LL * ca[i] * (ca[i] - 1) / 2;
    }
    // cerr << '\n';
    for (int i = 0; i < n; i++) {
        // cerr << i << ' ' << cb[i] << '\n';
        ans += 1LL * cb[i] * (cb[i] - 1) / 2;
    }
    for (auto e : ma) {
        int val = e.second;
        ans -= 1LL * val * (val - 1) / 2;
    }
    for (auto e : mb) {
        int val = e.second;
        ans -= 1LL * val * (val - 1) / 2;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}