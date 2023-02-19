#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> facts;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ll pw = 0;
            while (n % i == 0) {
                n /= i, pw++;
            }
            facts.emplace_back(pw, i);
        }
    }
    if (n > 1) facts.emplace_back(1, n);
    sort(facts.begin(), facts.end());
    ll base = 1;
    for (auto e : facts) {
        base *= e.second;
    }
    // cerr << base << '\n';
    ll ans = base * facts[0].first;
    base /= facts[0].second;
    // cerr << ans << '\n';
    for (int i = 1; i < facts.size(); i++) {
        // cerr << facts[i].first << ' ' << facts[i].second << '\n';
        if (facts[i].first == facts[i - 1].first) {
            base /= facts[i].second;
        } else {
            ans += base * (facts[i].first - facts[i - 1].first);
            base /= facts[i].second;
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
        solve();
    }

    return 0;
}