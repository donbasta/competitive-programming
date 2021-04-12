#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 2e9;

int n, c;

void solve() {
    cin >> n >> c;
    vector<ll> a(n + 1), b(n);
    vector<pair<ll, ll>> greedy(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> b[i];
    }
    greedy[1] = make_pair(0, 0); //day, tugrik
    for (int i = 2; i <= n; i++) {
        ll d = greedy[i - 1].first;
        ll t = greedy[i - 1].second;
        if (t >= b[i - 1]) {
            greedy[i] = make_pair(d + 1, t - b[i - 1]);
        } else {
            ll m = (b[i - 1] - t + a[i - 1] - 1) / a[i - 1];
            greedy[i] = make_pair(d + m + 1, t + (a[i - 1] * m) - b[i - 1]);
        }
    }
    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        if (greedy[i].second >= c) {
            ans = min(ans, greedy[i].first);
            continue;
        }
        int need = c - greedy[i].second;
        int day = (need + a[i] - 1) / a[i];
        ans = min(ans, greedy[i].first + day);
    }
    cout << ans << '\n';
    return;
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