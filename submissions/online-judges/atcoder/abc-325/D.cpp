#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> itv;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        b += a;
        itv.emplace_back(a, b);
    }
    sort(itv.begin(), itv.end(), [&](pair<ll, ll> x, pair<ll, ll> y) -> bool {
        if (x.second == y.second) return x.first > y.first;
        return x.second > y.second;
    });
    int ans = 1;
    ll pos = itv[0].second;
    int cur = 1;
    multiset<ll> se;
    while (cur < n || !se.empty()) {
        while (cur < n && itv[cur].second >= pos - 1) {
            se.insert(itv[cur].first);
            cur++;
        }
        while (!se.empty() && *se.rbegin() >= pos) {
            se.erase(se.find(*se.rbegin()));
        }
        if (cur < n && se.empty()) {
            pos = itv[cur].second;
            ans++;
            cur++;
        } else if (!se.empty()) {
            ans++;
            pos--;
            se.erase(se.find(*se.rbegin()));
        }
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