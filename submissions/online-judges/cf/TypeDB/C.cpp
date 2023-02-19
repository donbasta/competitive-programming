#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    ll s;
    cin >> n >> s;
    vector<ll> ar(n);
    vector<pair<ll, ll>> bounds(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (ar[i] > s * 2) {
            bounds[i] = make_pair(s, ar[i] - s);
        } else if (ar[i] > s) {
            bounds[i] = make_pair(ar[i] - s, s);
        } else {
            bounds[i] = make_pair(0, ar[i]);
        }
    }
    ll F1 = ar[0] * bounds[1].first;
    ll F2 = ar[0] * bounds[1].second;
    for (int i = 1; i <= n - 3; i++) {
        F1 += bounds[i].second * bounds[i + 1].first;
        F2 += bounds[i].first * bounds[i + 1].second;
    }
    F1 += bounds[n - 2].second * ar[n - 1];
    F2 += bounds[n - 2].first * ar[n - 1];
    cout << min(F1, F2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}