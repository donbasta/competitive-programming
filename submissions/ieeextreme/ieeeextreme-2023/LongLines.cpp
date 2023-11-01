#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> h(n);
    ll a, c, q;
    cin >> h[0] >> a >> c >> q;
    for (int i = 1; i < n; i++) {
        h[i] = (a * h[i - 1] + c) % q;
    }
    vector<int> R(n, n);
    vector<pair<ll, int>> tmp;
    for (int i = 0; i < n; i++) {
        while (!tmp.empty() && tmp.back().first <= h[i]) {
            R[tmp.back().second] = i;
            tmp.pop_back();
        }
        tmp.emplace_back(h[i], i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int ka = min(R[i], n - 1);
        ans += (ka - i);
    }
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
